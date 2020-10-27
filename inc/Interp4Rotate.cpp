#include "Interp4Command.hh"



class Interp4Rotate: public Interp4Command
{
private:
    
public:
    Interp4Rotate();
    ~Interp4Rotate();
    void PrintCmd() const;
    void PrintSyntax() const;
    const char* GetCmdName();
    bool ExecCmd(ObiektMobilny *wObMob, int GniazdoDoSerwera) const;
    bool ReadParams(std::istream& Strm_CmdsList);
};

Interp4Rotate::Interp4Rotate(/* args */)
{
}

Interp4Rotate::~Interp4Rotate()
{
}

/*!* \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)*/

void Interp4Rotate::PrintCmd() const
{
   int i =0; /*Wyswietl postac biezacego polecenia -- nazwa oraz wartosci parametrow*/
}

/*!* \brief Wyświetla składnię polecenia*/

void Interp4Rotate::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
}

/*!* \brief Wyświetla nazwę polecenia*/

const char* Interp4Command::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
}

/*!* \brief Wykonuje polecenie oraz wizualizuje jego realizację*/

bool Interp4Command::ExecCmd(ObiektMobilny *wObMob, int GniazdoDoSerwera) const
{
   /* Wykonuje polecenie oraz wizualizuje jego realizacje */
}

/*!* 

\brief Czyta wartości parametrów danego polecenia

*/

bool ReadParams(std::istream& Strm_CmdsList)
{
    /*Czyta*/
}


extern ”C”
{
    const char * GetCmdName(void);
    void PrintSyntax(void);
    Interp4Command* CreateCmd(void);
}

const char* GetCmdName(void)
{
    return "Rotate";
}

void PrintSyntax(void) 
{
    Interp4Rotate::PrintSyntax();
}

Interp4Command* CreateCmd(void)
{
    return Interp4Rotate::CreateCmd();
}