#include <xercesc/util/PlatformUtils.hpp>
#include "xmlinterp.hh"
#include <cassert>
#include <sstream>
#include <cstdlib>
#include <iostream>



using namespace std;



/*!
 * Metoda wywoływana jest bezpośrednio przed rozpoczęciem
 * przetwarzana dokumentu XML.
 */
void XMLInterp4Config::startDocument()
{
  cout << "*** Rozpoczecie przetwarzania dokumentu XML." << endl;
}


/*!
 * Metoda wywoływana jest bezpośrednio po zakończeniu
 * przetwarzana dokumentu XML.
 */
void XMLInterp4Config::endDocument()
{
  cout << "=== Koniec przetwarzania dokumentu XML." << endl;
}





/*!
 * Analizuje atrybuty elementu XML \p "Lib" i odpowiednio je interpretuje.
 * \param[in] Attrs - (\b in) atrybuty elementu XML \p "Lib".
 */
void XMLInterp4Config::ProcessLibAttrs(const xercesc::Attributes  &Attrs)
{
    if (Attrs.getLength() != 1) 
    {
        cerr << "Zla ilosc atrybutow dla \"Lib\"" << endl;
        exit(1);
    }

    char* sParamName = xercesc::XMLString::transcode(Attrs.getQName(0));

    if (strcmp(sParamName,"Name")) 
    {
        cerr << "Zla nazwa atrybutu dla Lib" << endl;
        exit(1);
    }         

    XMLSize_t  Size = 0;
    char* sLibName = xercesc::XMLString::transcode(Attrs.getValue(Size));

    cout << "  Nazwa biblioteki: " << sLibName << endl;

    this->conf.AddPluginPaths(sLibName);

    xercesc::XMLString::release(&sParamName);
    xercesc::XMLString::release(&sLibName);
}


/*!
 * Analizuje atrybuty. Sprawdza czy ich nazwy są poprawne. Jeśli tak,
 * to pobiera wartości atrybutów (w postaci napisów) i przekazuje ...
 * \param[in] Attrs - (\b we,) atrybuty elementu XML \p "Cybe".
 */
void XMLInterp4Config::ProcessCubeAttrs(const xercesc::Attributes  &Attrs)
{
    if (Attrs.getLength() != 3) 
    {
        cerr << "Zla ilosc atrybutow dla \"Cube\"" << endl;
        exit(1);
    }

    /*
    *  Tutaj pobierane sa nazwy pierwszego i drugiego atrybuty.
    *  Sprawdzamy, czy na pewno jest to Name i Value.
    */

    char* sName_Name = xercesc::XMLString::transcode(Attrs.getQName(0));
    char* sName_SizeXYZ = xercesc::XMLString::transcode(Attrs.getQName(1));
    char* sName_RGB = xercesc::XMLString::transcode(Attrs.getQName(2));

    XMLSize_t  Index = 0;
    char* sValue_Name    = xercesc::XMLString::transcode(Attrs.getValue(Index));
    char* sValue_SizeXYZ = xercesc::XMLString::transcode(Attrs.getValue(1));
    char* sValue_RGB     = xercesc::XMLString::transcode(Attrs.getValue(2));


    //------------------------------------------------
    // Wyświetlenie nazw atrybutów i ich "wartości"
    //
    cout << " Atrybuty:" << endl
        << "     " << sName_Name << " = \"" << sValue_Name << "\"" << endl
        << "     " << sName_SizeXYZ << " = \"" << sValue_SizeXYZ << "\"" << endl
        << "     " << sName_RGB << " = \"" << sValue_RGB << "\"" << endl   
        << endl; 
    //------------------------------------------------
    this->conf.AddMobileName(sValue_Name);
    

    istringstream IStrm;
    IStrm.str(sValue_SizeXYZ);
    double  x, y, z;
    IStrm >> x >> y >> z;
    
    if (IStrm.fail()) 
    {
        cerr << " Blad!!!" << endl;
    } 
    else 
    {
        cout << " Czytanie wartosci OK!!!" << endl;
        this->conf.AddMobileScale(Vector3D(x, y, z));
    }
    IStrm.clear();
    IStrm.str(sValue_RGB);
    IStrm >> x >> y >> z;
    if (IStrm.fail()) 
    {
        cerr << " Blad!!!" << endl;
    } 
    else 
    {
        cout << " Czytanie wartosci OK!!!" << endl;
        conf.AddMobileColor(Vector3D(x, y, z));
    }


    xercesc::XMLString::release(&sName_Name);
    xercesc::XMLString::release(&sName_SizeXYZ);
    xercesc::XMLString::release(&sName_RGB);
    xercesc::XMLString::release(&sValue_Name);
    xercesc::XMLString::release(&sValue_SizeXYZ);
    xercesc::XMLString::release(&sValue_RGB);
}





void XMLInterp4Config::WhenStartElement( const std::string       &ElemName,
		                         const xercesc::Attributes   &Attrs
                                       )
{
  if (ElemName == "Lib") {
    ProcessLibAttrs(Attrs);   
    return;   
  }

  if (ElemName == "Cube") 
  {
    ProcessCubeAttrs(Attrs);
    return;
  }

  

}


void XMLInterp4Config::startElement(  const   XMLCh* const    pURI,
                                       const   XMLCh* const    pLocalName,
                                       const   XMLCh* const    pQNname,
				       const   xercesc::Attributes&     Attrs
                                    )
{
  char* sElemName = xercesc::XMLString::transcode(pLocalName);
  cout << "+++ Poczatek elementu: "<< sElemName << endl;

  WhenStartElement(sElemName, Attrs);

  xercesc::XMLString::release(&sElemName);
}




void XMLInterp4Config::endElement(  const   XMLCh* const    pURI,
                                     const   XMLCh* const    pLocalName,
                                     const   XMLCh* const    pQName
                                  )
{
   char* sElemName = xercesc::XMLString::transcode(pLocalName);
   cout << "----- Koniec elementu: "<< sElemName << endl;

   xercesc::XMLString::release(&sElemName);
}




void XMLInterp4Config::fatalError(const xercesc::SAXParseException&  Exception)
{
   char* sMessage = xercesc::XMLString::transcode(Exception.getMessage());
   char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

   cerr << "Blad fatalny! " << endl
        << "    Plik:  " << sSystemId << endl
        << "   Linia: " << Exception.getLineNumber() << endl
        << " Kolumna: " << Exception.getColumnNumber() << endl
        << " Informacja: " << sMessage 
        << endl;

   xercesc::XMLString::release(&sMessage);
   xercesc::XMLString::release(&sSystemId);
}

void XMLInterp4Config::error(const xercesc::SAXParseException&  Exception)
{
    cerr << "Blad w linii: !" << Exception.getLineNumber() << endl;
    cerr << "Kolumna: " << Exception.getColumnNumber() << endl;
    cerr << Exception.getMessage();
}


void XMLInterp4Config::warning(const xercesc::SAXParseException&  Exception)  
{
    cerr << "Ostrzezenie w linii: !" << Exception.getLineNumber() << endl;
    cerr << "Kolumna: " << Exception.getColumnNumber() << endl;
    cerr << Exception.getMessage();
}
