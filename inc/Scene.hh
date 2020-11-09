#ifndef SCENE_HH
#define SCENE_HH
#include "MobileObject.hh"
#include <map>
#include <iostream>
#include <iterator>
#include <string>
#include <memory>

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
    class Scene
    {
        private:
            /*!
            * \brief Map of all mobile objects
            *
            *  Map of all mobile objects
            */
            std::map<std::string, std::shared_ptr<MobileObject>> mapMobileObjects;
        public:
            /*!
            * \brief Run given commands 
            * \param[in, out] name - name of an object to be found
            * \param[out] tempMobileObject - empty pointer to an object. If object found it will be returned here
            * \retval true - object has been found
            * \retval false - object has not been found
            */
            bool FindMobileObject (std::string name, std::shared_ptr<MobileObject> tempMobileObject);
            /*!
            * \brief Add mobile object to the scene
            * \param[in] handler - pointer to mobile object to be added to scene
            * 
            */
            void AddMobileObject(std::shared_ptr<MobileObject> handler);
    };


#endif