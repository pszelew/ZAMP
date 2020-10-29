#ifndef MOBILEOBJECT_HH
#define MOBILEOBJECT_HH
#include "Vector3D.hh"
#include "Vector2D.hh"
#include <string>



class MobileObject
{
    protected:
        std::string name;
        double rot_z;
        Vector3D pos;
        
    public:
        MobileObject(std::string in_name, double in_rot_z, Vector3D in_pos): name(in_name), rot_z(in_rot_z),pos(in_pos)  {};
        MobileObject() {};
        std::string Name() const { return name; }
        std::string& Name() { return name; }
        double Rot_z() const { return rot_z; }
        double& Rot_z()  { return rot_z; }
        Vector3D Pos() const { return pos; }
        Vector3D& Pos() { return pos; }

};


#endif