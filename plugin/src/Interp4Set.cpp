#include <iostream>
#include "Interp4Set.hh"

using namespace std;

Interp4Set::Interp4Set():  pos_x(0), pos_y(0), vel(0)
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
   cout << this->GetCmdName() << " " << pos_x  << " " << pos_y << "" << vel << endl;
}


void Interp4Set::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
    cout << "   Set pos_x[m]  pos_y[m] vel[m/s]" << endl;
}


const char* Interp4Set::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
    return "Set";
}

bool Interp4Set::ExecCmd(ObiektMobilny *wObMob, int GniazdoDoSerwera) const
{
   /* Wykonuje polecenie oraz wizualizuje jego realizacje */
   return true;
}

bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
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
    return "Set";
}


Interp4Command* CreateCmd(void)
{
    return Interp4Set::CreateCmd();
}