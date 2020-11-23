#ifndef PLUGINMANAGER_HH
#define PLUGINMANAGER_HH

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <dlfcn.h>
#include <memory>
#include <map>
#include <vector>
#include "LibraryInterface.hh"
#include "Scene.hh"


/*!
 * \file
 * \brief Definition of PluginManager
 *
 *  File contains definition of PluginManager
 */




    /*!
    * \brief Class used to represent a manager for plugins
    *
    *  Class used to represent a manager for plugins. Contains all the instances and library interfaces 
    */
    class PluginManager
    {
        private:
            /*!
            * \brief Map of all loaded plugins
            *
            *  Map of all loaded plugins
            * 
            */

            std::map<std::string, std::shared_ptr<LibraryInterface>> mapLibraries;
            /*!
            * \brief Pointer to the current command instance
            *
            *  Pointer to the current command instance
            */
            Interp4Command* cmdInstance;
        public:
            /*!
            * \brief Initialize PluginManager instance
            * 
            *  Initialize PluginManager instance
            * \param[in] pluginPaths - vector containings paths to plugins
            */
            bool init(std::vector<std::string> pluginPaths);
            /*!
            * \brief Run given commansds 
            * \param[in, out] commandsStream - stream of commands 
            * \param[in] scene - scene containing all objects
            * \param[in] serverSocket - socket to server
            */
            bool exec(std::istream & commandsStream, std::shared_ptr<Scene> & scene ,  int serverSocket); 
    };


#endif
