#ifndef  COMMAND4SET_HH
#define  COMMAND4SET_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

class Interp4Set: public Interp4Command
{
private:
  int pos_x;
  int pos_y;
  int vel;
public:
    Interp4Set();
    ~Interp4Set();
    /*!* \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)*/
    void PrintCmd() const;
    /*!* \brief Wyświetla składnię polecenia*/
    void PrintSyntax() const;
    /*!* \brief Wyświetla nazwę polecenia*/
    const char* GetCmdName() const;
    /*!* \brief Wykonuje polecenie oraz wizualizuje jego realizację*/
    bool ExecCmd(ObiektMobilny *wObMob, int GniazdoDoSerwera) const;
    /*!* \brief Czyta wartości parametrów danego polecenia*/
    bool ReadParams(std::istream& Strm_CmdsList);
    /*!* \brief Tworzy obiekt polecenia*/
    static Interp4Command* CreateCmd();
};

#endif
