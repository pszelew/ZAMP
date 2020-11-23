#include "Simulation.hh"

bool Simulation::init(std::string cmdPath, std::string xmlPath)
{    
    parser = std::make_shared<Parser>(cmdPath, xmlPath);
    plugManager = std::make_shared<PluginManager>();
    
    serverSocket = 6217;

    scene = std::make_shared<Scene>();
    
    return true;
}

bool Simulation::exec()
{
    std::istringstream streamCmd;
    std::istringstream streamXml;

    if(!parser->ParseCmd(streamCmd))
    {
        std::cout << "Wystapil problem przy ladowaniu pliku cmd!!!"<< std::endl;
        return false; 
    }
    if(!parser->ParseXML(streamXml))
    {
        std::cout << "Wystapil problem przy ladowaniu pliku XML!!!"<< std::endl;
        return false; 
    }

    Configuration conf = this->parser->GetConf();


    if(!plugManager->init(conf.GetPluginPaths()))
    {
        std::cout << "Nie udalo sie zainicjowac Managera Pluginow!!!"<< std::endl;
        return false; 
    }
    
    // add all necessary mobile objects
    if(!this->AddCuboids())
    {
        std::cerr << "Nie udalo sie dodac obiektow!!!" << std::endl;
        return false;
    }

    if(!(plugManager->exec(streamCmd, scene, serverSocket)))
    {
        std::cout << "Wystapil problem przy uruchamianiu symulacji!!!"<< std::endl;
        return false;
    }
    return true;

}

bool Simulation::AddCuboids()
{
    Configuration conf = this->parser->GetConf();

    std::vector<std::string> names = conf.GetMobileName();
    std::vector<Vector3D> scales = conf.GetMobileScale();
    std::vector<Vector3D> colors = conf.GetMobileColor();

    for(unsigned int i = 0; i < names.size(); ++i)
    {
        std::shared_ptr<Cuboid> objectToAdd = std::make_shared<Cuboid>(names[i], Vector3D(0,0,0), Vector3D(0,0,0), scales[i], colors[i].x(), colors[i].y(), colors[i].z());
        this->scene->AddMobileObject(objectToAdd);
        // std::cout << objectToAdd->GetName();
    }
    return true;
}