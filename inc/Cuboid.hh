#ifndef CUBOID_HH
#define CUBOID_HH
#include "MobileObject.hh"

class Cuboid: MobileObject
{
    private:
        std::string name;
        double rot_z;
        Wektor3D pos;
        
    public:
        Cuboid(std:: string in_name, double in_rot_z, Wektor3D in_pos): name(in_name), rot_z(in_rot_z),pos(in_pos)  {};
        std::string Name() { return name; }
        std::string& Name() { return name; }
        double rot_z() { return Rot_z; }
        double& rot_z() { return Rot_z; }
        Wektor3D Pos() { return Pos; }
        Wektor3D& Pos() { return Pos; }

};


#endif