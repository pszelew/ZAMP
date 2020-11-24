#ifndef PARSER_HH
#define PARSER_HH

#include <string>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <iostream>
#include "xmlinterp.hh"
using namespace XERCES_CPP_NAMESPACE;
#define LINESIZE 500

/*!
 * \file
 * \brief Definition of LibraryInterface
 *
 *  File contains definition of LibraryInterface
 */

    /*! 
    *   
    *   \brief Class used to represent parser of CMD and XML
    *
    *   Parser of CMD and XML
    */
    class Parser
    {
        private:
            /*! \brief Name of cmd file to be read */
            std::string cmdFile;
            /*! \brief Name of xml file to be read */
            std::string xmlFile;
            /*! \brief Configuration read from a xml file */
            Configuration conf;
        public:
            /*!
            * \brief Parser constructor
            *
            * Parser constructor
            * \param[in] cmd - name of cmd file
            * \param[in] xml - name of xml file
            */
            Parser(std::string cmd, std::string xml): cmdFile(cmd), xmlFile(xml) {} 
            /*!
            * \brief Read data from cmd file
            *
            * Read data from cmd file
            * \param[out] IStrm4Cmds - output stream 
            * \retval true - File read was successfull
            * \retval false - File read wasn't successfull
            */
            bool ParseCmd(std::istringstream & IStrm4Cmds);
            /*!
            * \brief Read data from cmd file
            *
            * Read data from xml file
            * \retval true - File read was successfull
            * \retval false - File read wasn't successfull
            */
            bool ParseXML();
            /*!
            * \brief Returns current configuration value (read-only)
            *
            * \return Returns current configuration value (read-only)
            */
            const Configuration & GetConf() const { return conf; }

    };


#endif