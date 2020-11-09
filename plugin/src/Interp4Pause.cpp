#include <iostream>
#include "Interp4Pause.hh"

using namespace std;

Interp4Pause::Interp4Pause():  time_s(0)
{
}

Interp4Pause::~Interp4Pause()
{

}

Interp4Command* Interp4Pause::CreateCmd()
{
  return new Interp4Pause();
}



void Interp4Pause::PrintCmd() const
{
   cout << this->GetCmdName() << " " << time_s << endl;
}


void Interp4Pause::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
    cout << "   Pause time[s]" << endl;
}


const char* Interp4Pause::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
    return "Pause";
}

bool Interp4Pause::ExecCmd(std::shared_ptr<MobileObject>  wObMob,  int serverSocket) const
{
   /* Wykonuje polecenie oraz wizualizuje jego realizacje */
   std::cout<< "Polecenie Pause wykonuje sie!!!"<< endl;
   return true;
}

bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
    if(!(Strm_CmdsList >> time_s))
    {
        std::cout << "Nie wczytano poprawnie czasu"<< endl;
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
    return "Pause";
}


Interp4Command* CreateCmd(void)
{
    return Interp4Pause::CreateCmd();
}