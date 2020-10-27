#include <iostream>
#include "Interp4Move.hh"

using namespace std;

Interp4Move::Interp4Move():  vel_x(0), vel_y(0)
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
   cout << this->GetCmdName() << " " << vel_x << " " << vel_y << endl;
}


void Interp4Move::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
    cout << "   Move vel_x[m/s] vel_y[m/s]" << endl;
}


const char* Interp4Move::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
    return "Move";
}

bool Interp4Move::ExecCmd(ObiektMobilny *wObMob, int GniazdoDoSerwera) const
{
   /* Wykonuje polecenie oraz wizualizuje jego realizacje */
   return true;
}

bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
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
    return "Move";
}


Interp4Command* CreateCmd(void)
{
    return Interp4Move::CreateCmd();
}