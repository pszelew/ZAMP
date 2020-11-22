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
            * \brief RGB color of cuboid
            */
            Vector3D color;

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
            * \param[in] in_color - color as Vector3D (R, G, B). Each value in range [0, 255]
            */
            Cuboid(std::string in_name, Vector3D in_rot_deg, Vector3D in_pos_m, Vector3D in_scale, Vector3D in_color):
                                        MobileObject(in_name, in_rot_deg, in_pos_m), scale(in_scale), color(in_color) {};
            /*!
            * \brief Mobile object contructor
            *
            * Mobile object contructor
            */
            Cuboid(){};
    };


#endif