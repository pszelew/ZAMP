#include <iostream>
#include "Interp4Rotate.hh"

using namespace std;

Interp4Rotate::Interp4Rotate():  obj_name(""), rot_speed_degs(0), rot_deg(0)
{
}

Interp4Rotate::~Interp4Rotate()
{

}

Interp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}



void Interp4Rotate::PrintCmd() const
{
   cout << this->GetCmdName() << " " << obj_name << " " << rot_speed_degs  << " " << rot_deg << endl;
}


void Interp4Rotate::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
    cout << "   Rotate obj_name rotate_speed[deg/s]  rotation[deg]" << endl;
}


const char* Interp4Rotate::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
    return "Rotate";
}

bool Interp4Rotate::ExecCmd(std::shared_ptr<MobileObject>  wObMob,  int serverSocket) const
{
   /* Wykonuje polecenie oraz wizualizuje jego realizacje */
   std::cout<< "Polecenie Rotate wykonuje sie!!!"<< endl;
   return true;
}

bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
    if(!(Strm_CmdsList >> obj_name))
    {
        std::cout << "Nie wczytano poprawnie nazwy obiektu ktory ma sie obrocic"<< endl;
        return 1;
    }

    if(!(Strm_CmdsList >> rot_speed_degs))
    {
        std::cout << "Nie wczytano poprawnie predkosci obrotowej"<< endl;
        return 1;
    }

    if(!(Strm_CmdsList >> rot_deg))
    {
        std::cout << "Nie wczytano poprawnie kata obrotu"<< endl;
        return 1;
    }
    

    return true;
}


////////////////////////////////////////////wtyczka/////////////////////////////////////////////

extern "C"
{   /*! 
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
    return "Rotate";
}


Interp4Command* CreateCmd(void)
{
    return Interp4Rotate::CreateCmd();
}