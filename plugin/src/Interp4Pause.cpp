#include <iostream>
#include "Interp4Pause.hh"

using namespace std;

Interp4Pause::Interp4Pause():  time(0)
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
   cout << this->GetCmdName() << " " << time << endl;
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

bool Interp4Pause::ExecCmd(ObiektMobilny *wObMob, int GniazdoDoSerwera) const
{
   /* Wykonuje polecenie oraz wizualizuje jego realizacje */
   return true;
}

bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
    /*Czyta parametry*/
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
    return "Pause";
}


Interp4Command* CreateCmd(void)
{
    return Interp4Pause::CreateCmd();
}