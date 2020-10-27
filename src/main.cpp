#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "Interp4Command.hh"

using std::cout;
using std::cerr;
using std::endl;




int main()
{

  void *pLibHnd_Rotate = dlopen("Interp4Rotate.so",RTLD_LAZY);
  void *pLibHnd_Set = dlopen("Interp4Set.so",RTLD_LAZY);
  void *pLibHnd_Pause = dlopen("Interp4Pause.so",RTLD_LAZY);
  void *pLibHnd_Move = dlopen("Interp4Pause.so",RTLD_LAZY);
  
  Interp4Command *(*pCreateCmd_Rotate)(void);
  Interp4Command *(*pCreateCmd_Set)(void);
  Interp4Command *(*pCreateCmd_Pause)(void);
  Interp4Command *(*pCreateCmd_Move)(void);
  
  void *pFun;

  if (!pLibHnd_Rotate) {
    cerr << "!!! Brak biblioteki: Rotate.so" << endl;
    return 1;
  }
  
  if (!pLibHnd_Set) {
    cerr << "!!! Brak biblioteki: Set.so" << endl;
    return 1;
  }

  if (!pLibHnd_Pause) {
    cerr << "!!! Brak biblioteki: Pause.so" << endl;
    return 1;
  }

  if (!pLibHnd_Move) {
    cerr << "!!! Brak biblioteki: Move.so" << endl;
    return 1;
  }


  pFun = dlsym(pLibHnd_Rotate,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd dla Rotate.so" << endl;
    return 1;
  }
  pCreateCmd_Rotate = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);

  Interp4Command *pCmd = pCreateCmd_Rotate();

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;
  
  delete pCmd;

  dlclose(pLibHnd_Rotate);
}
