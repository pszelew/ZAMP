#ifndef MOBILEOBJECT_HH
#define MOBILEOBJECT_HH
#include "Vector3D.hh"
#include "Vector2D.hh"
#include <string>
#include <iostream>


class MobileObject
{
    protected:
        std::string name;
        Vector3D rot;
        Vector3D pos;
        
    public:
        MobileObject(std::string in_name, Vector3D in_rot, Vector3D in_pos): name(in_name), rot(in_rot), pos(in_pos)  {};
        MobileObject() {};
        virtual std::string Name() const { return name; }
        virtual std::string& Name() { return name; }
        virtual Vector3D Rot() const { return rot; }
        virtual Vector3D& Rot()  { return rot; }
        virtual Vector3D Pos() const { return pos; }
        virtual Vector3D& Pos() { return pos; }

};


#endif