#ifndef  COMMAND4PAUSE_HH
#define  COMMAND4PAUSE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

class Interp4Pause: public Interp4Command
{
private:
  int time;
public:
    Interp4Pause();
    ~Interp4Pause();
    /*!* \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)*/
    void PrintCmd() const;
    /*!* \brief Wyświetla składnię polecenia*/
    void PrintSyntax() const;
    /*!* \brief Wyświetla nazwę polecenia*/
    const char* GetCmdName() const;
    /*!* \brief Wykonuje polecenie oraz wizualizuje jego realizację*/
    bool ExecCmd(std::shared_ptr<MobileObject>  wObMob,  int serverSocket) const;
    /*!* \brief Czyta wartości parametrów danego polecenia*/
    bool ReadParams(std::istream& Strm_CmdsList);
    /*!* \brief Tworzy obiekt polecenia*/
    static Interp4Command* CreateCmd();
    /*!* \brief Zwraca nazwe obiektu*/
    std::string GetObjName(){return "";}
};

#endif
