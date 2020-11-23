#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definition of class Interp4Move
 *
 * File contains definition of class Interp4Move
 */

    /*!
    * \brief Class used to represent move command
    *
    *  Class used to represent move command
    */
    class Interp4Move: public Interp4Command
    {
        private:
            /*! 
            * \brief Name of object to be moved
            *
            *  Name of object to be moved
            */
            std::string obj_name;
            /*! 
            * \brief Velocity of an object in meter/second (m/s)
            *
            *  Velocity of an object
            */
            int vel_ms;
            /*! 
            * \brief Distance to move an object
            *
            *  Distance to move an object in meters (m)
            */
            int dist_m;
        public:
            /*! 
            * \brief Constructor of move command class
            *
            *  Constructor of move command class
            */
            Interp4Move();
            /*! 
            * \brief Destructor of move command class
            *
            *  Destructor of move command class
            */
            ~Interp4Move();
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
            bool ExecCmd(std::shared_ptr<MobileObject> & wObMob,  std::shared_ptr<Scene> & pAccCtrl) const;
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
            * \brief Get the name of object beeing moved
            * 
            * Get the name of object beeing moved
            * 
            * \return Name of object
            */
            std::string GetObjName(){return obj_name;}
    };

#endif
