#ifndef OBIEKTMOBILNY_HH
#define OBIEKTMOBLINY_HH
#include "Vector3D.hh"
#include "Vector2D.hh"


class MobileObject
{
    private:
        std::string name;
        double rot_z;
        Wektor3D pos;
        
    public:
        std::string Name() const { return name; }
        std::string& Name() { return name; }
        double Rot_z() const { return rot_z; }
        double& Rot_z()  { return rot_z; }
        Wektor3D Pos() const { return pos; }
        Wektor3D& Pos() { return pos; }

};


#endif