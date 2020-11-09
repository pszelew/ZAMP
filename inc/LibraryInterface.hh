#ifndef LIBRARYINTERFACE_HH
#define LIBRARYINTERFACE_HH

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <dlfcn.h>
#include <memory>
#include "Interp4Command.hh"


/*!
 * \file
 * \brief Definition of LibraryInterface
 *
 *  File contains definition of LibraryInterface
 */


/*!
* \brief Class used to represent library interface
*
*   Class used to represent library interface
*/
class LibraryInterface
{
    private:
        /*!
        * \brief Handler to shared library
        *
        *  Handler to shared library
        */
        void* libHandler;
        /*!
        * \brief Pointer to instance creating function
        *
        *  Pointer to instance creating function
        */
        Interp4Command* (*createCmd)(void);
         /*!
        * \brief Name of command as string
        *
        *  Name of command as string
        */
        std::string cmdName;
        
    public:
        /*!
        * \brief Library interface contructor
        *
        * Library interface contructor
        */
        LibraryInterface(){}
        /*!
        * \brief Library interface destructor
        *
        * Library interface destructor
        */
        ~LibraryInterface();
        
        /*!
        * \brief Initialize library interface instance
        * 
        *  Initialize library interface instance
        * \param[in] fileName - name of library file to be opened
        * \retval true - initialized without problems
        * \retval false - initialized with problems
        */
        bool init(std::string fileName);

        /*!
        * \brief Get name of library interface
        * 
        *  Get name of library interface
        * 
        */
        std::string GetName(){return cmdName;}
        /*!
        * \brief Create command instance
        * 
        *  Create command instance
        * 
        */
        Interp4Command* CreateCmd(){ return createCmd(); }
};


#endif
