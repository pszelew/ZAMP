#ifndef CUBOID_HH
#define CUBOID_HH
#include "MobileObject.hh"

/*!
 * \file
 * \brief File contains definition of class Cubiod.
 *
 * File contains definition of class Cubiod.
 * 
 */

    /*! 
    *   
    *   \brief Class used to represent a cuboid mobile object
    *
    *   Cuboid is a funny struture
    */
    class Cuboid: public MobileObject
    {   
        private:
            /*!
            * \brief 3D vector of scale of cuboid
            */
            Vector3D scale;
            /*!
            * \brief R color of cuboid
            */
            int colorR;
            /*!
            * \brief G color of cuboid
            */
            int colorG;
            /*!
            * \brief B color of cuboid
            */
            int colorB;

        public:

            /*!
            * \brief Cuboid constructor
            *
            * Mobile object constructor
            * \param[in] in_name - name of object as string
            * \param[in] in_rot_deg - rotation of object as Vector3D (roll, pitch, yaw). Values are in degrees
            * \param[in] in_pos_m - position of object as Vector3D (x, y, z). Values are in meters
            */

            Cuboid(std::string in_name, Vector3D in_rot_deg, Vector3D in_pos_m):
                                        MobileObject(in_name, in_rot_deg, in_pos_m) {};
            /*!
            * \brief Cuboid constructor
            *
            * Mobile object constructor
            * \param[in] in_name - name of object as string
            * \param[in] in_rot_deg - rotation of object as Vector3D (roll, pitch, yaw). Values are in degrees
            * \param[in] in_pos_m - position of object as Vector3D (x, y, z). Values are in meters
            * \param[in] in_scale - scale of object as Vector3D (x, y, z).
            * \param[in] in_colorR - color red [0, 255]
            * \param[in] in_colorG - color green [0, 255]
            * \param[in] in_colorB - color blue [0, 255]
            */
            Cuboid(std::string in_name, Vector3D in_rot_deg, Vector3D in_pos_m, Vector3D in_scale, int in_colorR, int in_colorG, int in_colorB):
                                        MobileObject(in_name, in_rot_deg, in_pos_m), scale(in_scale), 
                                        colorR(in_colorR), colorG(in_colorG), colorB(in_colorB) {};
            /*!
            * \brief Mobile object contructor
            *
            * Mobile object contructor
            */
            Cuboid(){};

            const Vector3D & GetScale(){return scale;}; 

            const int & GetColorR(){return colorR;}
            const int & GetColorG(){return colorG;}
            const int & GetColorB(){return colorB;} 
    };


#endif