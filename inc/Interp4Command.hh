#ifndef  INTERP4COMMAND_HH
#define  INTERP4COMMAND_HH

#include <iostream>
#include "MobileObject.hh"
#include <memory>
/*!
 * \file
 * \brief Definition of class Interp4Command
 *
 * File contains definition of class Interp4Command
 */

    /*!
    * \brief Class used to represent an abstract command for mobile object
    *
    *  Class used to represent an abstract command for mobile object
    */
    class Interp4Command {
        public:
            /*!
            * \brief Virtual destructor
            *
            *  
            */
            virtual ~Interp4Command() {}
            /*!
            * \brief Display name and parameters of command
            */
            virtual void PrintCmd() const = 0;
            /*!
            * \brief Print syntax of command
            */
            virtual void PrintSyntax() const = 0;
            /*!
            * \brief Return the name of command
            */
            virtual const char* GetCmdName() const = 0;
            /*!
            * \brief Execute command
            * \retval true - executed without problems
            * \retval false - there was an error 
            */
            virtual bool ExecCmd(  std::shared_ptr<MobileObject>  wObMob,  int serverSocket  ) const = 0;
            /*!
            * \brief Read parameters of command
            * \param[in, out] Strm_CmdsList - stream containing parameters to be read
            * \retval true - read was successfull
            * \retval false - read was not successfull
            */
            virtual bool ReadParams(std::istream& Strm_CmdsList) = 0;
            /*!
            * \brief Get the name of object beeing moved
            * \return Name of object
            */
            virtual std::string GetObjName() = 0;
    };




#endif
