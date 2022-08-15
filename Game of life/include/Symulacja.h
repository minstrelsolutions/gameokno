#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "Plansza.h"

class Symulacja
{
    public:
        Symulacja();
        virtual ~Symulacja();
        void start();
    protected:

    private:
        Plansza* plansza;
};

#endif // SYMULACJA_H
