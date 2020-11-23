#include "Scene.hh"


bool Scene::FindMobileObject (std::string name, std::shared_ptr<MobileObject> & tempMobileObject)
{
    std::map<std::string, std::shared_ptr<MobileObject>>::iterator it;
    
    it = mapMobileObjects.find(name);
    
    if(it == mapMobileObjects.end())
    {
        std::cout << "Nie znaleziono obiektu: " << name << std::endl;
        return false;
    }

    tempMobileObject = it->second;
    
    return true;
}

void Scene::AddMobileObject(std::shared_ptr<MobileObject> handler)
{
    mapMobileObjects.insert(std::make_pair(handler->GetName(), handler));
}
        



