#ifndef VECTOR2D_HH
#define VECTOR2D_HH


#include <cassert>


/*!
 * \brief Dims of vector
 */
#define DIM2D 2

   /*!
    * \brief Class used to represent 2D Vector
    *
    *  Class used to represent a 2D Vector
    */
   class Vector2D {
      private:
         /*!
         * \brief Table containing vector coordinates of size 2
         *  Table containing vector coordinates of size 2
         */
         double _Wsp[DIM2D];
      public:  
         /*!
         * \brief Initialize all coorinates to 0
         */
         Vector2D() { for (double &Wsp : _Wsp)  Wsp = 0; }
         /*!
         * \brief Initialize coordinates to given x, y
         * \param[in] x - x-axis value
         * \param[in] y - y-axis value
         */
         Vector2D(double x, double y){_Wsp[0]=x; _Wsp[0]=y;}

         /*!
         * \brief Gives us chosen coordinates (read-only)
         *
         * \param[in]  Idx - index of chosen axis.
         *
         * \pre 0 <= Idx && Idx < DIM2D
         */
         double operator [] (int Idx) const 
         { assert(0 <= Idx && Idx < DIM2D); return _Wsp[Idx]; }
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
   };


#endif
