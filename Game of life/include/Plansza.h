#ifndef PLANSZA_H
#define PLANSZA_H
#include <iostream>
#include <conio.h>

using namespace std;

extern short L;
extern short H;

class Plansza
{
    public:
        Plansza();
        virtual ~Plansza();
        void pokaz();
    protected:

    private:
        char** plansza;
        char granica_pozioma = '_';
        char granica_pionowa = '|';
};

#endif // PLANSZA_H
