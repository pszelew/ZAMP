#ifndef CONNECTIONMANAGER_HH
#define CONNECTIONMANAGER_HH
#include "Port.hh"
#include "Simulation.hh"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <vector>


/*!
 * \file
 * \brief Contains the definition of a class ConnectionManager
 */


/*!
 * \brief Containst info about connection between a simulation and a server
 *
 */
class ConnectionManager 
{
    private:
        /*!
        * \brief Secket descriptor, to send data
        */
        int socket_manager = 0;
        /*!
        * \brief Bool value that decides whether continue sending thread
        * 
        * If \p true then loop in a sending thread in continued. If \p false it stops.
        */
        volatile bool _ContinueLooping = true;
        /*!
        * \brief Pointer to the simulation manager is connecting to
        *
        * 
        */
        std::shared_ptr<Simulation> mySim;
    public:
        /*!
        * \brief Non-parametrized constructor of our class
        *
        *
        */
        ConnectionManager(){}
        /*!
        * \brief Destructor of our class
        *
        * Destructor that closes connection to the server
        *
        */
        ~ConnectionManager(){Send("Close\n"); close(socket_manager);}
        /*!
        * \brief Initiazlizes connection manager
        * 
        * 
        */
        bool init(std::shared_ptr<Simulation> sim);
          /*!
        * \brief Checks if czy the loop in the thread should be continued
        * 
        * Checks if czy the loop in the thread should be continued.
        * \retval true - the loop should be continued
        * \retval false - otherwise
        */
        bool ShouldCountinueLooping() const { return _ContinueLooping; }
        /*!
        * \brief Stop the loop in the thread
        *
        * Stop the loop in the thread
        * \warning Reaction is not immediate
        */
        void CancelCountinueLooping() { _ContinueLooping = false; }

        /*!
        * \brief Just the sending thread
        *
        * If something was changed in the scene it sends all the data to the server.
        *   
        */

        void Watching_and_Sending();

        /*!
        * \brief Creates message about the state of a cuboid
        *   
        * Creates message about the state of a cuboid
        * 
        * \param[in] mob - the message will describe this object
        * \return Created message as string
        */
        std::string CreateMessage(Cuboid mob);

        /*!
        * \brief Sends a text message to the server
        *
        * Sends a text message to the server
        * 
        * \param[in] sMesg - text message to be send
        * \retval true - Sending successful
        * \retval false - Otherwise
        */
        bool Send(const char *sMesg);

};


#endif
