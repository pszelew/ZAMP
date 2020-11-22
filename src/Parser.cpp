#include "Parser.hh"


bool Parser::ParseCmd(std::istringstream & IStrm4Cmds)
{
    std::string Cmd4Preproc = "cpp -P ";
    char Line[LINESIZE];
    std::ostringstream OTmpStrm;
    Cmd4Preproc += cmdFile.c_str();

    FILE * pProc = popen(Cmd4Preproc.c_str(),"r");
    if(!pProc)
        return false;
    while(fgets(Line,LINESIZE,pProc))
    {
        OTmpStrm<<Line;
    }
    IStrm4Cmds.str(OTmpStrm.str());

    return pclose(pProc) == 0;
}

bool Parser::ParseXML(std::istringstream & IStrm4Cmds)
{
    const char * sFileName = this->xmlFile.c_str();
    try {
            XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
            char* message = XMLString::transcode(toCatch.getMessage());
            std::cerr << "Error during initialization! :\n";
            std::cerr << "Exception message is: \n"
                    << message << "\n";
            XMLString::release(&message);
            return 1;
    }

    SAX2XMLReader* pParser = XMLReaderFactory::createXMLReader();

    pParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
    pParser->setFeature(XMLUni::fgSAX2CoreValidation, true);
    pParser->setFeature(XMLUni::fgXercesDynamic, false);
    pParser->setFeature(XMLUni::fgXercesSchema, true);
    pParser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);

    pParser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);

    DefaultHandler* pHandler = new XMLInterp4Config(this->conf);
    pParser->setContentHandler(pHandler);
    pParser->setErrorHandler(pHandler);

    try {
        
        if (!pParser->loadGrammar("config/config.xsd",
                                xercesc::Grammar::SchemaGrammarType,true)) {
        std::cerr << "!!! Plik grammar/actions.xsd, '" << std::endl
            << "!!! ktory zawiera opis gramatyki, nie moze zostac wczytany."
            << std::endl;
        return false;
        }
        pParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse,true);
        pParser->parse(sFileName);
    }
    catch (const XMLException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            std::cerr << "Informacja o wyjatku: \n"
                    << "   " << sMessage << "\n";
            XMLString::release(&sMessage);
            return false;
    }
    catch (const SAXParseException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

            std::cerr << "Blad! " << std::endl
                    << "    Plik:  " << sSystemId << std::endl
                    << "   Linia: " << Exception.getLineNumber() << std::endl
                    << " Kolumna: " << Exception.getColumnNumber() << std::endl
                    << " Informacja: " << sMessage 
                    << std::endl;

            XMLString::release(&sMessage);
            XMLString::release(&sSystemId);
            return false;
    }
    catch (...) {
            std::cout << "Zgloszony zostal nieoczekiwany wyjatek!\n" ;
            return false;
    }

    delete pParser;
    delete pHandler;
    return true;
}
