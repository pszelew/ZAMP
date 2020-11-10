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
        public:
            /*!
            * \brief Cuboid constructor
            *
            * Mobile object constructor
            * \param[in] in_name - name of object as string
            * \param[in] in_rot_deg - rotation of object as Vector3D (roll, pitch, yaw). Values are in degrees
            * \param[in] in_pos_m - position of object as Vector3D (x, y, z). Values are in meters
            */
            Cuboid(std::string in_name, Vector3D in_rot_deg, Vector3D in_pos_m): MobileObject(in_name, in_rot_deg, in_pos_m) {};
            /*!
            * \brief Mobile object contructor
            *
            * Mobile object contructor
            */
            Cuboid(){};
    };


#endif