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
        *  A Vector of paths to plugins
        */
        std::vector<std::string> plugPaths;

        /*!
        * \brief Vector of mobile objects names
        *
        *  A Vector of names of objects to be add
        */
        std::vector<std::string> mobileName;

        /*!
        * \brief Vector of mobile objects scales
        *
        *  A Vector of scales of objects to be add
        */
        std::vector<Vector3D> mobileScale;
        /*!
        * \brief Vector of mobile objects colors
        *
        *  A Vector of colors of objects to be add
        */
        std::vector<Vector3D> mobileColor;
    
    public:
    
        /*!
        * \brief Get a Vector of the paths to plugins (read-only)
        *
        *  Get a Vector of the plugin paths to be add (read-only)
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
        * \brief Get the Vector of mobile objects names
        *
        *  Get the Vector of mobile objects names
        *  \return Vector of mobile objects names
        */
        std::vector<std::string> GetMobileName() const { return mobileName; }
        /*!
        * \brief Add name to vector of mobile object names
        *
        *  Add a name to the vector of mobile object names
        *  \param[in] mobName - name of mobile object to be add
        */
        void AddMobileName(std::string mobName) { mobileName.push_back(mobName); }

        /*!
        * \brief Get the Vector of mobile objects scales
        *
        *  Get the Vector of mobile objects scales
        *  \return The Vector of mobile objects scales
        */
        std::vector<Vector3D> GetMobileScale()  const { return mobileScale; }
        /*!
        * \brief Add scale to vector of mobile object scales
        *
        *  Add a scale to the vector of mobile object scales
        */
        void AddMobileScale(Vector3D mobScale) { mobileScale.push_back(mobScale); }


        /*!
        * \brief Get the Vector of mobile objects colors
        *
        *  Get a Vector of mobile objects colors
        *  \return Vector of mobile objects colors
        */
        std::vector<Vector3D> GetMobileColor() const { return mobileColor; }
        /*!
        * \brief Add a color to the vector of mobile object colors
        *
        *  Add a color to the vector of mobile object colors
        */
        void AddMobileColor(Vector3D mobColor) { mobileColor.push_back(mobColor); }


};


#endif
