#include <iostream>
#include "Interp4Rotate.hh"

using namespace std;

Interp4Rotate::Interp4Rotate():  obj_name(""), rotateSpeed(0), rotateDegrees(0)
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
   cout << this->GetCmdName() << " " << obj_name << " " << rotateSpeed  << " " << rotateDegrees << endl;
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

    if(!(Strm_CmdsList >> rotateSpeed))
    {
        std::cout << "Nie wczytano poprawnie predkosci obrotowej"<< endl;
        return 1;
    }

    if(!(Strm_CmdsList >> rotateDegrees))
    {
        std::cout << "Nie wczytano poprawnie kata obrotu"<< endl;
        return 1;
    }
    

    return true;
}


////////////////////////////////////////////wtyczka/////////////////////////////////////////////

extern "C"
{
    const char * GetCmdName(void);
    
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