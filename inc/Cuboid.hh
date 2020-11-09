#ifndef CUBOID_HH
#define CUBOID_HH
#include "MobileObject.hh"

class Cuboid: public MobileObject
{        
    public:
        Cuboid(std::string in_name, Vector3D in_rot, Vector3D in_pos): MobileObject(in_name, in_rot, in_pos) {};
        Cuboid(){};
        // std::string Name() const { return name; }
        // std::string& Name() { std::cout<< "tuteeeeeej2"<<std::endl;return name; }
        // Vector3D Rot() const{ return rot; }
        // Vector3D& Rot() { return rot; }
        // Vector3D Pos() const { return pos; }
        // Vector3D& Pos() { return pos; }

};


#endif