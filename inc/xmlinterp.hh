#ifndef XMLINTERP4ACTIONS_HH
#define XMLINTERP4ACTIONS_HH

#include <string>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/sax/Locator.hpp>

#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>

//XERCES_CPP_NAMESPACE_USE

#include "Configuration.hh"


/*!
* \brief Implements reactions to certain events during XML reading
*
* Contains reactions to certain events during XML reading
*/
class XMLInterp4Config : public xercesc::DefaultHandler 
{
    private:
        /*!
        * \brief Configuration read from file
        */
        Configuration & conf;
    public:
        /*!
        * \brief Initialize the object with configuration file
        * \param[in] rConfig - configuration file used to init interpreter
        */
        XMLInterp4Config(Configuration &rConfig) : conf(rConfig) {};

        /*!
        * \brief It will be executed in the begining of document
        */
        virtual void startDocument() override;
        /*!
        * \brief t will be executed in the end of document
        */
        virtual void endDocument() override;

        /*!
        * \brief When new element is found
        * \param[in] pURI - pURI
        * \param[in] pLocalName - pLocalName
        * \param[in] pQNname -  pQNname
        * \param[in] attrs -  set of attributes
        */
        virtual void startElement(
                        const XMLCh *const pURI, 
                        const XMLCh *const pLocalName, 
                        const XMLCh *const pQNname,
                        const   xercesc::Attributes& attrs
                        ) override;

        /*!
        * \brief When the element is ended
        * \param[in] pURI - pURI
        * \param[in] pLocalName - pLocalName
        * \param[in] pQNname -  pQNname
        */
        virtual  void endElement(
                        const XMLCh *const pURI, 
                        const XMLCh *const pLocalName, 
                        const XMLCh *const pQNname
                        ) override;
        /*!
        * \brief Reaction to a fatal error
        */
        void fatalError(const xercesc::SAXParseException&);
        /*!
        * \brief Reaction to an error
        * \param[in, out] exc - just an exception
        */
        void error(const xercesc::SAXParseException &exc);
        /*!
        * \brief Reaction to a warning
        * \param[in, out] exc - just an exception
        */
        void warning(const xercesc::SAXParseException &exc);


            /*!
            * \brief Do something with XML element
            * \param[in] ElemName - name of an element
            * \param[in] Attrs - set of attributes of an element
            */
        void WhenStartElement( const std::string& ElemName, const xercesc::Attributes& Attrs);
        /*!
        * \brief Process library attributes
        * \param[in] Attrs - set of attributes of an element
        */
        void ProcessLibAttrs(const xercesc::Attributes& Attrs);
        /*!
        * \brief Process cube attributes
        * \param[in] Attrs - set of attributes of an element
        */
        void ProcessCubeAttrs(const xercesc::Attributes& Attrs); 

};

#endif
