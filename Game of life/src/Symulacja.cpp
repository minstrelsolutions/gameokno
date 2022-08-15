#include "Symulacja.h"

Symulacja::Symulacja()
{
    //ctor
}

Symulacja::~Symulacja()
{
    delete plansza;
}

void Symulacja::start()
{
    system("cls");
    cout<<"Start symulacji"<<endl;
    plansza->pokaz();
    cout<<"Pokazano"<<endl;
    _getch();

}
