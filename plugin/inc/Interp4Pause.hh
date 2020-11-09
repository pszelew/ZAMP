#ifndef  COMMAND4PAUSE_HH
#define  COMMAND4PAUSE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif
#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definition of class Interp4Pause
 *
 * File contains definition of class Interp4Pause
 */



    /*!
    * \brief Class used to represent pause command
    *
    *  Class used to represent pause command
    */
    class Interp4Pause: public Interp4Command
    {
        private:
            /*! 
            * \brief Time of pause s
            *
            *  Time of pause s
            */
            int time_s;
        public:
            /*! 
            * \brief Constructor of move command class
            *
            *  Constructor of move command class
            */
            Interp4Pause();
            /*! 
            * \brief Destructor of move command class
            *
            *  Destructor of move command class
            */
            ~Interp4Pause();
            /*!
            * \brief Display name and parameters of command
            */
            void PrintCmd() const;
            /*!
            * \brief Print syntax of command
            */
            void PrintSyntax() const;
            /*!
            * \brief Return the name of command
            * \return Name of command
            */
            const char* GetCmdName() const;
            /*!
            * \brief Execute command
            * \retval true - executed without problems
            * \retval false - there was an error 
            */
            bool ExecCmd(std::shared_ptr<MobileObject>  wObMob,  int serverSocket) const;
            /*!
            * \brief Read parameters of command
            * \param[in, out] Strm_CmdsList - stream containing parameters to be read
            * \retval true - read was successfull
            * \retval false - read was not successfull
            */
            bool ReadParams(std::istream& Strm_CmdsList);
            /*!
            * \brief Static funtion creating instance of command,
            * 
            * Static funtion creating instance of command
            * \return Handler to command instance
            */
            static Interp4Command* CreateCmd();
            /*!
            * \brief Get the name of object
            * 
            * Get the name of object
            * 
            * \return Name of object
            */
            std::string GetObjName(){return "";}
    };

#endif
