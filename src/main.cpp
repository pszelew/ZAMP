#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <cstdio>
#include <sstream>
#include <string>
#include "Interp4Command.hh"
#include "Parser.hh"
#include "LibraryInterface.hh"


#define LINESIZE 300

using namespace std;


bool ExecProgram(istream  &rIStrm)
{
  string KeyWord;
  //0) Wtyczki mam juz wczytane. Przechowuje je w jakiejsc strukturze
  //1) wczytujemy slowo ze stromienia preprocesora (nazwa polecenia MOVE, ROTATE, ..,)  -- to jakies polecenie
  //2) Znajdz wtyczke obslugujaca dane polecenie w jakiejsc wczytanej strukturze
  //3) CZy operacja znalezienia wtyczki udala sie? Jesli nie to koncz program i elo! 
  rIStrm >> KeyWord;
  //4) Utworz instancje interpretera polecenia. Czy się udało>
  //5) Strumien przekazujemy do polecenia read params dla utworzonej instancji
  //6) Czy udalo sie wczytac parametry danego polecenia. Wszystko poszlo dobrze?
  //7) Wykonaj polecenie
  //8) Zniszcz interpreter polecenia
  while(true)
  {
    return true;
  }

  return true;
}


int main(int argc, char** argv)
{
  LibraryInterface lib;
  Parser par(argv[1], "");
  lib.init("Interp4Rotate.so");

  istringstream stream;
  
  if(argc < 2)
  {
    cout<< "Nie podano nazwy pliku cmd!!!";
    return 1;
  }

  //Interp4Command *pCmd = pCreateCmd_Rotate();
  Interp4Command *pCmd = lib.CreateCmd();
  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;
  
  delete pCmd;

  if(!par.parseCmd(stream))
  {
    cout << "Mamy problem z wczytaniem pliku. Na pewno podales dobra sciezke?!";
    return 1;
  }

  //pCmd->ReadParams(stream);
  //std::string line;
  //std::getline(stream, line);
  cout << stream.str()  <<endl << endl;
  
}
