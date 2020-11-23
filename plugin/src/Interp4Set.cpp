#include <iostream>
#include "Interp4Set.hh"

using namespace std;

Interp4Set::Interp4Set():  obj_name(""), pos_x_m(0), pos_y_m(0), angle_z_deg(0)
{
}

Interp4Set::~Interp4Set()
{

}

Interp4Command* Interp4Set::CreateCmd()
{
  return new Interp4Set();
}



void Interp4Set::PrintCmd() const
{
   cout << this->GetCmdName() << " " << obj_name << " " << pos_x_m  << " " << pos_y_m << " " << angle_z_deg << endl;
}


void Interp4Set::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
    cout << "   Set obj_name pos_x[m]  pos_y[m] angle[deg]" << endl;
}


const char* Interp4Set::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
    return "Set";
}

bool Interp4Set::ExecCmd(std::shared_ptr<MobileObject> & wObMob,  std::shared_ptr<Scene> & pAccCtrl) const
{

    Vector3D startPos = wObMob->GetPosition_m();
    pAccCtrl->LockAccess(); // Lock access to the scene to modify something :)
    
    // Tak jest dobrze.
    wObMob->SetPosition_m(Vector3D(pos_x_m, pos_y_m, startPos.z()));
    wObMob->SetAng_Yaw_deg(angle_z_deg);
    
    pAccCtrl->MarkChange();
    pAccCtrl->UnlockAccess();
    
    return true;

    /* Wykonuje polecenie oraz wizualizuje jego realizacje */
}

bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
    if(!(Strm_CmdsList >> obj_name))
    {
        std::cout << "Nie wczytano poprawnie nazwy obiektu ktory ma sie ustawic"<< endl;
        return 1;
    }

    if(!(Strm_CmdsList >> pos_x_m))
    {
        std::cout << "Nie wczytano poprawnie pozycji x"<< endl;
        return 1;
    }

    if(!(Strm_CmdsList >> pos_y_m))
    {
        std::cout << "Nie wczytano poprawnie pozycji y"<< endl;
        return 1;
    }

    if(!(Strm_CmdsList >> angle_z_deg))
    {
        std::cout << "Nie wczytano poprawnie kata obrotu"<< endl;
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
    return "Set";
}


Interp4Command* CreateCmd(void)
{
    return Interp4Set::CreateCmd();
}