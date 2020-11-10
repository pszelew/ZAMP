#ifndef MOBILEOBJECT_HH
#define MOBILEOBJECT_HH
#include "Vector3D.hh"
#include "Vector2D.hh"
#include <string>
#include <iostream>


/*!
 * \file
 * \brief File contains definition of class MobileObj.
 *
 *  File contains definition of class MobileObj.
 * 
 */

    /*! 
    *   
    *   \brief Class used to represent a mobile object
    *
    *   Mobile object is an object that can move
    */
    class MobileObject
    {
        protected:
            /*! \brief Name of on object as std::string */
            std::string name;
            /*! \brief 3D rotation vector defined as (roll, pitch yaw) or (rotX, rotY, rotZ) in degrees*/
            Vector3D rot_deg;
            /*! \brief 3D positon vector defined as (x, y z) in meters*/
            Vector3D pos_m;
            
        public:
            /*!
            * \brief Mobile object contructor
            *
            * Mobile object contructor
            * \param[in] in_name - name of object as string
            * \param[in] in_rot_deg - rotation of object as Vector3D (roll, pitch, yaw). Values are in degrees
            * \param[in] in_pos_m - position of object as Vector3D (x, y, z). Values are in meters
            */
            MobileObject(std::string in_name, Vector3D in_rot_deg, Vector3D in_pos_m): name(in_name), rot_deg(in_rot_deg), pos_m(in_pos_m)  {};
            /*!
            * \brief Mobile object contructor
            *
            * Mobile object contructor
            */
            MobileObject(){};

            /*!
            * \brief Virtual destructor
            *
            *  
            */
            virtual ~MobileObject() {}
            /*!
            * \brief Gives us a value of \e roll angle.
            * 
            * Gives us a value of \e roll angle in degrees
            */
            double GetAng_Roll_deg() const { return rot_deg[0]; }
            /*!
            * \brief Gives us a value of \e pitch angle.
            *
            *
            * Gives us a value of \e pitch angle in degrees
            */
            double GetAng_Pitch_deg() const { return rot_deg[1]; }
            /*!
            * \brief Gives us a value of \e yaw angle.
            *
            *
            * Gives us a value of \e pitch yaw in degrees
            */
            double GetAng_Yaw_deg() const { return rot_deg[2]; }

            /*!
            * \brief Changes value of \e roll angle
            *
            * Changes value of \e roll angle
            * \param[in] Ang_Roll_deg - new value of \e roll angle in degrees
            */
            void SetAng_Roll_deg(double Ang_Roll_deg) { rot_deg[0] = Ang_Roll_deg; }
            /*!
            * \brief Changes value of \e pitch angle
            *
            * Changes value of \e pitch angle
            * \param[in] Ang_Pitch_deg - new value of \e pitch angle in degrees
            */
            void SetAng_Pitch_deg(double Ang_Pitch_deg) { rot_deg[1] = Ang_Pitch_deg; }
            /*!
            * \brief Changes value of \e yaw angle
            *
            * Changes value of \e yaw angle
            * \param[in] Ang_Yaw_deg - new value of \e yaw angle in degrees
            */
            void SetAng_Yaw_deg(double Ang_Yaw_deg) { rot_deg[2] = Ang_Yaw_deg; }

            /*!
            * \brief Gives us position of mobile object (read-only).
            *
            * Gives us position of mobile object (read-only).
            * Values of Vector3D in meters.
            * 
            */
            const Vector3D & GetPosition_m() const { return pos_m; }
            /*!
            * \brief Gives us position of mobile object (modify).
            *
            * Gives us position of mobile object (modify).
            * Values of Vector3D in meters.
            * 
            */
            Vector3D & UsePosition_m() { return pos_m; }
            /*!
            * \brief Set position of object
            * Set position of object (center of object)
            * \param[in] rPos_m - coordinates of new position in meters
            *                   
            */
            void SetPosition_m(const Vector3D &rPos_m) { pos_m = rPos_m; }


            /*!
            * \brief Changes name of object
            *
            *  Changes name of object
            *  \param[in] sName - new object name (const char*)
            */
            void SetName(const char* sName) { name = sName; }
            /*!
            * \brief Gives us name of object (read-only)
            *
            * Gives us name of object (read-only)
            */
            const std::string & GetName() const { return name; }

    };


#endif