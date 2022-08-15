#ifndef INTERFEJS_H
#define INTERFEJS_H
#include <fstream>
#include <conio.h>
#include <iostream>
#include <string>
#include "Symulacja.h"

using namespace std;

const string CONFIG = "config.dat";

class Interfejs
{
    public:
        Interfejs();
        virtual ~Interfejs();
        void menu();
        void pokazUstawienia();
        void zmienUstawienia(bool zmien, short temp_H, short temp_L);
        short pobierzDane(short a, short b);
        void zainicjujSymulacje();
    protected:

    private:
        Symulacja* symulacja;
};

#endif // INTERFEJS_H
