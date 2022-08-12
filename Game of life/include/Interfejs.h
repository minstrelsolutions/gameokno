#ifndef INTERFEJS_H
#define INTERFEJS_H
#include <fstream>
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

const string CONFIG = "config.dat";

class Interfejs
{
    public:
        Interfejs();
        virtual ~Interfejs();
        void menu();
        void showConfig();
        void changeParams(bool change, short temp_H, short temp_L);
        short getData(short a, short b);
    protected:

    private:
};

#endif // INTERFEJS_H
