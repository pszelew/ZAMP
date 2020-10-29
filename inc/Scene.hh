#ifndef SCENE_HH
#define SCENE_HH
#include "MobileObject.hh"
#include <map>
#include <iostream>
#include <iterator>
#include <string>
#include <memory>
class Scene
{
    private:
        std::map<std::string, std::shared_ptr<MobileObject>> mapMobileObjects;
    public:
        bool FindMobileObject (std::string name, std::shared_ptr<MobileObject> tempMobileObject);
        void addMobileObject(std::shared_ptr<MobileObject> handler);
};


#endif