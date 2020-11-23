#include "Simulation.hh"
#include "Cuboid.hh"
#include "ConnectionManager.hh"

using namespace std;


void Fun_CommunicationThread(shared_ptr<ConnectionManager> con)
{
    con->Watching_and_Sending();
}


int main(int argc, char** argv)
{
    shared_ptr<Simulation> sim = make_shared<Simulation>();
    shared_ptr<ConnectionManager> con = make_shared<ConnectionManager>();
    
    
    if(argc < 2)
    {
        cout<< "Nie podano nazwy pliku cmd!!!";
        return 1;
    }

    if(argc < 3)
    {
        cout<< "Nie podano nazwy pliku xml!!!";
        return 1;
    }
    ///////////////////////////////////////
    ///////////////////////////////////////

    if(!sim->init(argv[1], argv[2]))
    // Inicjalizacja symulacji
    {
        cout << "Nie udalo sie zainicjowac Symulacji!!!"<<endl;
        return 1;
    }
    

    if(!con->init(sim))
    // Inicjalizacja symulacji
    {
        cout << "Nie udalo sie zainicjowac Symulacji!!!"<<endl;
        return 1;
    }


    thread Thread4Sending(Fun_CommunicationThread, con);

    

    if(!sim->exec())
    {
        cout << "Blad podczas wykonywania symulacji!!!"<<endl;
        return 1;
    }
    
    con->CancelCountinueLooping();
    Thread4Sending.join();
    
    cout << "Program zakonczyl dzialanie bez problemow" << endl;
    return 0;

}
