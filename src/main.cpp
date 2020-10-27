#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <cstdio>
#include <sstream>
#include <string>
#include "Interp4Command.hh"

#define LINESIZE 300

using namespace std;
// using std::cout;
// using std::cerr;
// using std::endl;
// using std::istringstream;
// using std::ostringstream;
// using std::string;


bool ExecPreprocesor(const char * NazwaPliku, istringstream & IStrm4Cmds )
{
  string Cmd4Preproc = "cpp -P ";
  char Line[LINESIZE];
  ostringstream OTmpStrm;
  Cmd4Preproc += NazwaPliku;
  FILE * pProc = popen(Cmd4Preproc.c_str(),"r");
  if(!pProc)
    return false;
  while(fgets(Line,LINESIZE,pProc))
  {
    OTmpStrm<<Line;
  }
  IStrm4Cmds.str(OTmpStrm.str());
  return pclose(pProc) == 0;
}


int main(int argc, char** argv)
{

  std::string file_path = " ";
  istringstream stream;
  if(argc  < 1)
  {
    cout<< "Nie podano nazwy pliku cmd!!!";
    return 1;
  }


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

  
  if(!ExecPreprocesor(argv[1], stream))
  {
    cout << "Mamy problem!";
    return 1;
  }

  //pCmd->ReadParams(stream);
  //std::string line;
  //std::getline(stream, line);
  cout << stream.str()  <<endl << endl;
  
}
