#ifndef VECTOR3D_HH
#define VECTOR3D_HH


#include <cassert>

/*!
 * \file
 * \brief Definition of Vector3D
 *
 *  Definition of Vector3D
 */


/*!
 * \brief Dims of vector
 */
#define DIM3D 3

   /*!
    * \brief Class used to represent 3D Vector
    *
    *  Class used to represent a 3D Vector
    */
   class Vector3D {
      private:
         /*!
         * \brief Table containing vector coordinates of size 3
         *  Table containing vector coordinates of size 3
         */
         double _Wsp[DIM3D];
      public:  
            /*!
            * \brief Initialize all coorinates to 0
            */
            Vector3D() { for (double &Wsp : _Wsp)  Wsp = 0; }
            /*!
            * \brief Initialize coordinates to given x, y, z
            * \param[in] x - x-axis value
            * \param[in] y - y-axis value
            * \param[in] z - z-axis value
            */
            Vector3D(double x, double y, double z){_Wsp[0]=x; _Wsp[1]=y; _Wsp[2]=z;}
            /*!
            * \brief Gives us chosen coordinates (read-only)
            *
            * \param[in]  Idx - index of chosen axis.
            *
            * \pre 0 <= Idx && Idx < DIM2D
            */
            double operator [] (int Idx) const 
            { assert(0 <= Idx && Idx < DIM3D); return _Wsp[Idx]; }
            /*!
            * \brief Gives us chosen coordinates (modify)
            *
            * \param[in]  Idx - index of chosen axis.
            *
            * \pre 0 =< Idx && Idx < DIM2D
            */
            double& operator [] (int Idx) { return _Wsp[Idx]; }

            /*!
            * \brief Gives us x coordinate (read-only).
            */
            double x() const { return _Wsp[0]; }
            /*!
            * \brief Gives us x coordinate (modify).
            */
            double& x() { return _Wsp[0]; }
            /*!
            * \brief Gives us y coordinate (read-only).
            */
            double y() const { return _Wsp[1]; }
            /*!
            * \brief Gives us y coordinate (modify).
            */
            double& y() { return _Wsp[1]; }

            /*!
            * \brief Gives us z coordinate (read-only).
            */
            double z() const { return _Wsp[2]; }
            /*!
            * \brief Gives us z coordinate (modify).
            */
            double& z() { return _Wsp[2]; }
};


#endif
