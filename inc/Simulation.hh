#ifndef SIMULATION_HH
#define SIMULATION_HH

#include "Parser.hh"
#include "PluginManager.hh"
#include "Scene.hh"
#include <sstream>

/*!
 * \file
 * \brief Definition of Simulation
 *
 *  File contains definition of Simulation
 */



    /*!
    * \brief Class used to represent a simulation
    *
    *  Class used to represent a simulation. Contains plugin manager, parser and scene
    */
    class Simulation
    {
        private:
            /*!
            * \brief Parser of cmd and xml files
            *
            *  Parser of cmd and xml files handler
            */
            std::shared_ptr<Parser> parser;
            /*!
            * \brief Plugin manager
            *
            *  Plugin manager handler
            */
            std::shared_ptr<PluginManager> plugManager;
            /*!
            * \brief Vector of paths to plugins
            *
            *  Vector of paths to plugins
            */
            std::vector<std::string> plugPaths;
            /*!
            * \brief Scene handler
            *
            *  Scene handler
            */
            std::shared_ptr<Scene> scene;
            /*!
            * \brief Server socket number
            *   
            *  Server socket number
            */   
            int serverSocket;

            
        public:
            /*!
            * \brief Initialize Simulation instance
            * 
            *  Initialize Simulation instance
            * \param[in] cmdPath - name of cmd file
            * \param[in] xmlPath - name of xml file
            */
            bool init(std::string cmdPath, std::string xmlPath);


            /*!
            * \brief Method template adding mobile object to scene
            * \param[in] in_name - name of mobile object to be added
            * \param[in] in_rot_deg - Vector of (roll, pitch, yaw) rotation. Values in degrees.
            * \param[in] in_pos_m - Vector of (x, y, z) position. Values in meters.
            */
            bool exec(); 
            template <typename T>
            bool AddMobileObject(std::string in_name, Vector3D in_rot_deg, Vector3D in_pos_m)
            {
                T mobileObjectTest;
                MobileObject* mobileTest;
                if(!(mobileTest = dynamic_cast< MobileObject* >(&mobileObjectTest)))
                {
                    std:: cout << "Podany typ " << typeid(mobileObjectTest).name() << "nie jest ObiektemMobilnym!!!"<< std::endl;
                    return false;
                }
                std::shared_ptr<T> objectToAdd = std::make_shared<T>(in_name, in_rot_deg, in_pos_m);
                scene->AddMobileObject(objectToAdd);

                return true;
            }

            
    };


#endif
