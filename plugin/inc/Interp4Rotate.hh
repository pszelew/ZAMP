#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

class Interp4Rotate: public Interp4Command
{
private:
  std::string obj_name; 
  int rotateSpeed;
  int rotateDegrees;
public:
    Interp4Rotate();
    ~Interp4Rotate();
    /*!* \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)*/
    void PrintCmd() const;
    /*!* \brief Wyświetla składnię polecenia*/
    void PrintSyntax() const;
    /*!* \brief Wyświetla nazwę polecenia*/
    const char* GetCmdName() const;
    /*!* \brief Wykonuje polecenie oraz wizualizuje jego realizację*/
    bool ExecCmd(MobileObject *wObMob, int GniazdoDoSerwera) const;
    /*!* \brief Czyta wartości parametrów danego polecenia*/
    bool ReadParams(std::istream& Strm_CmdsList);
    /*!* \brief Tworzy obiekt polecenia*/
    static Interp4Command* CreateCmd();
};

#endif
