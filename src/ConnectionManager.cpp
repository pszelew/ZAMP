#include "ConnectionManager.hh"

std::string ConnectionManager::CreateMessage(Cuboid mob)
{
    std::string temp = "";
    temp += "Cube ";
    temp += std::to_string(mob.GetScale().x()) + " ";
    temp += std::to_string(mob.GetScale().y()) + " ";
    temp += std::to_string(mob.GetScale().z()) + " ";
    temp += std::to_string(mob.GetPosition_m().x()) + " ";
    temp += std::to_string(mob.GetPosition_m().y()) + " ";
    temp += std::to_string(mob.GetPosition_m().z()) + " ";
    temp += std::to_string(mob.GetAng_Roll_deg()) + " ";
    temp += std::to_string(mob.GetAng_Pitch_deg()) + " ";
    temp += std::to_string(mob.GetAng_Yaw_deg()) + " ";
    temp += std::to_string(mob.GetColorR()) + " ";
    temp += std::to_string(mob.GetColorG()) + " ";
    temp += std::to_string(mob.GetColorB()) + "\n";

    return temp;
}


bool ConnectionManager::init(std::shared_ptr<Simulation> sim)
{
    this->mySim = sim;

    struct sockaddr_in  DaneAdSerw;

    bzero((char *)&DaneAdSerw,sizeof(DaneAdSerw));

    DaneAdSerw.sin_family = AF_INET;
    DaneAdSerw.sin_addr.s_addr = inet_addr("127.0.0.1");
    DaneAdSerw.sin_port = htons(PORT);


    socket_manager = socket(AF_INET,SOCK_STREAM,0);

    if (socket_manager < 0) {
        std::cerr << "*** Blad otwarcia gniazda." << std::endl;
        return false;
    }

    if (connect(socket_manager,(struct sockaddr*)&DaneAdSerw,sizeof(DaneAdSerw)) < 0)
    {
        std::cerr << "*** Brak mozliwosci polaczenia do portu: " << PORT << std::endl; 
        return false;
    }
    return true;
}


void ConnectionManager::Watching_and_Sending() 
    {
        std::shared_ptr<Scene> & myScene = mySim->GetScene();
        while (ShouldCountinueLooping()) 
        {
        if (!myScene->IsChanged())  
        { 
            usleep(10000); continue; 
        }
        myScene->LockAccess();
       
        //------- Przeglądanie tej kolekcji to uproszczony przykład
       
        this->Send("Clear\n"); // To jest konieczne, aby usunąć wcześniejsze obiekty.
        std::cout << "Clear\n";

        std::map<std::string, std::shared_ptr<MobileObject>>::iterator it;   
        for (it = myScene->GetMapMobileObjects().begin(); it != myScene->GetMapMobileObjects().end(); it++)    
        {
            std::shared_ptr<Cuboid> myCub = std::dynamic_pointer_cast<Cuboid>(it->second);
            this->Send(CreateMessage(*myCub).c_str()); // Tu musi zostać wywołanie odpowiedniej
                                            // metody/funkcji gerującej polecenia dla serwera.

        }

        //
        this->Send("Display\n"); // To jest konieczne, aby zobaczyć zmiany
        std::cout << "Display\n";
        
        myScene->CancelChange();
        myScene->UnlockAccess();
        }
    }




int ConnectionManager::Send(const char *sMesg)
{
    ssize_t  IlWyslanych;
    ssize_t  IlDoWyslania = (ssize_t) strlen(sMesg);

    while ((IlWyslanych = write(socket_manager,sMesg,IlDoWyslania)) > 0) 
    {
        IlDoWyslania -= IlWyslanych;
        sMesg += IlWyslanych;
    }
    if (IlWyslanych < 0) 
    {
        std::cerr << "*** Blad przeslania napisu." << std::endl;
    }
    return 0;
}