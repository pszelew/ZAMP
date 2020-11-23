#include <iostream>
#include "Interp4Move.hh"

using namespace std;

Interp4Move::Interp4Move():  obj_name(""), vel_ms(0), dist_m(0)
{
}

Interp4Move::~Interp4Move()
{

}

Interp4Command* Interp4Move::CreateCmd()
{
    return new Interp4Move();
}



void Interp4Move::PrintCmd() const
{
   cout << this->GetCmdName() << " " << obj_name << " " << vel_ms << " " << dist_m << endl;
}


void Interp4Move::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
    cout << "   Move nazwa_obiektu vel[m/s] dist[m]" << endl;
}


const char* Interp4Move::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
    return "Move";
}

bool Interp4Move::ExecCmd(std::shared_ptr<MobileObject> & wObMob,  std::shared_ptr<Scene> & pAccCtrl) const
{
    Vector3D startPos = wObMob->GetPosition_m();
    double startRoll = wObMob->GetAng_Roll_deg();
    double startPitch = wObMob->GetAng_Pitch_deg();
    double startYaw = wObMob->GetAng_Yaw_deg();
    double new_x_m, new_y_m, new_z_m;
    new_x_m = new_y_m = new_z_m = 0;
    int n = 4;
    double dist_step_m = (double)dist_m/n;
    double time_step_us = (((double)this->dist_m/this->vel_ms)*1000000)/n;

    for(int i = 0; i<n; ++i)
    {
        pAccCtrl->LockAccess(); // Lock access to the scene to modify something :)
        // Tak jest dobrze.
        new_x_m += dist_step_m*cos(startPitch*M_PI/180)*cos(startYaw*M_PI/180);
        new_y_m += dist_step_m*(cos(startRoll*M_PI/180)*sin(startYaw*M_PI/180) + cos(startYaw*M_PI/180)*sin(startPitch*M_PI/180)*sin(startRoll*M_PI/180));
        new_z_m += dist_step_m*(sin(startRoll*M_PI/180)*sin(startYaw*M_PI/180) - cos(startRoll*M_PI/180)*cos(startYaw*M_PI/180)*sin(startPitch*M_PI/180));
        wObMob->SetPosition_m(Vector3D(new_x_m+startPos.x(), new_y_m+startPos.y(), new_z_m+startPos.z()));

        pAccCtrl->MarkChange();
        pAccCtrl->UnlockAccess();
        usleep(time_step_us);
    }
    
    
    std::cout<< "Polecenie Move wykonuje sie!!!"<< endl;
    
    //std::cout<< "new x: " << wObMob->GetPosition_m().x() << ", new y: " << wObMob->GetPosition_m().y() << ", new z" << wObMob->GetPosition_m().z() <<  endl;
    
    return true;

    /* Wykonuje polecenie oraz wizualizuje jego realizacje */
    
}

bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
    if(!(Strm_CmdsList >> obj_name))
    {
        std::cout << "Nie wczytano poprawnie nazwy obiektu ktory ma sie poruszyc"<< endl;
        return 1;
    }

    if(!(Strm_CmdsList >> vel_ms))
    {
        std::cout << "Nie wczytano poprawnie predkosci"<< endl;
        return 1;
    }

    if(!(Strm_CmdsList >> dist_m))
    {
        std::cout << "Nie wczytano poprawnie dystansu"<< endl;
        return 1;
    }
    

    return true;
}


////////////////////////////////////////////wtyczka/////////////////////////////////////////////


extern "C"
{
    /*! 
    * \brief Get command name
    *
    *  Get command name
    * \return Name of object
    */
    const char * GetCmdName(void);
    
    /*! 
    * \brief Returns pointer to instance of command
    *
    *  Returns pointer to instance of command
    * \return Pointer to instance of command
    */
    Interp4Command* CreateCmd(void);
}

const char* GetCmdName(void)
{
    return "Move";
}


Interp4Command* CreateCmd(void)
{
    return Interp4Move::CreateCmd();
}