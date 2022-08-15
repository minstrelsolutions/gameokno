#include "Plansza.h"

Plansza::Plansza()
{
    for (short i = 0; i <L; ++i)
    {
        plansza[i] = new char[H];
        for (short j = 0; j <H; ++j)
        {
            plansza[i][j] = ' ';
        }
    }
}

Plansza::~Plansza()
{
    for (short i = 0; i< L; ++i)
    {
        delete[] plansza[i];
    }
    delete[] plansza;
}

void Plansza::pokaz()
{
    cout<<"Start pokazu"<<endl;
    for (short i = 0; i<L+2;++i)
    {
        cout << granica_pozioma;
    }
    cout << endl;

    for (short j=0;j<H;++j)
    {
        cout <<granica_pozioma;

        for (short i=0; i<L;++i)
        {
            cout<<plansza[i][j];
        }
        cout <<granica_pozioma<<endl;
    }

    for (short i = 0; i<L+2;++i)
    {
        cout << granica_pozioma;
    }
    cout << endl;

}
