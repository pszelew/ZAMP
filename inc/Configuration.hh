#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH
#include <vector>
#include "MobileObject.hh"
#include "Vector3D.hh"

class Configuration 
{
    private:
        /*!
        * \brief Vector of paths to plugins
        *
        *  Vector of paths to plugins
        */
        std::vector<std::string> plugPaths;

        /*!
        * \brief Vector of mobile objects names
        *
        *  Vector of names of objects to be add
        */
        std::vector<std::string> mobileName;

        /*!
        * \brief Vector of mobile objects scales
        *
        *  Vector of scales of objects to be add
        */
        std::vector<Vector3D> mobileScale;
        /*!
        * \brief Vector of mobile objects colors
        *
        *  Vector of colors of objects to be add
        */
        std::vector<Vector3D> mobileColor;
    
    public:
    
        /*!
        * \brief Get Vector of paths to plugins (read-only)
        *
        *  Get Vector of plugin paths to be add (read-only)
        *  \return vector of plugin paths
        */
        std::vector<std::string> GetPluginPaths() const { return plugPaths; }

        /*!
        * \brief Add plugin paths
        *
        *  Set Vector of plugin paths to be add
        *  \param[in] path - path for plugin
        */
        void AddPluginPaths(std::string path) { plugPaths.push_back(path); }


        /*!
        * \brief Get Vector of mobile objects names
        *
        *  Get Vector of mobile objects names
        *  \return Vector of mobile objects names
        */
        std::vector<std::string> GetMobileName() const { return mobileName; }
        /*!
        * \brief Add name to vector of mobile object names
        *
        *  Add name to vector of mobile object names
        *  \param[in] - name of mobile object to be add
        */
        void AddMobileName(std::string mobName) { mobileName.push_back(mobName); }

        /*!
        * \brief Get Vector of mobile objects scales
        *
        *  Get Vector of mobile objects scales
        *  \return Vector of mobile objects scales
        */
        std::vector<Vector3D> GetMobileScale()  const { return mobileScale; }
        /*!
        * \brief Add scale to vector of mobile object scales
        *
        *  Add scale to vector of mobile object scales
        */
        void AddMobileScale(Vector3D mobScale) { mobileScale.push_back(mobScale); }


        /*!
        * \brief Get Vector of mobile objects colors
        *
        *  Get Vector of mobile objects colors
        *  \return Vector of mobile objects colors
        */
        std::vector<Vector3D> GetMobileColor() const { return mobileColor; }
        /*!
        * \brief Add color to vector of mobile object colors
        *
        *  Add color to vector of mobile object colors
        */
        void AddMobileColor(Vector3D mobColor) { mobileColor.push_back(mobColor); }


};


#endif
