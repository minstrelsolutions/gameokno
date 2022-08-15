#include "Interfejs.h"

short H;
short L;

Interfejs::Interfejs()
{
    ifstream file;
    file.open(CONFIG);
    if(file.good())
    {
        file>>H;
        file>>L;
        file.close();
    }else{
        H=10;
        L=12;
        ofstream file;
        file.open(CONFIG);
        file<<H<<' '<<L;
        file.close();
    }
}

Interfejs::~Interfejs()
{
    //dtor
}

void Interfejs::menu()
{
    system("cls");
    cout << "GAME OF LIFE - 2022"<<endl<<endl;
    cout << "MENU GRY" << endl;
    pokazUstawienia();
    cout << "Co chcesz zrobic?"<<endl<<endl;
    cout << "\t1 - Rozpocznij"<<endl;
    cout << "\t2 - Zmien parametry"<<endl;
    cout << "\t3 - Wyjdz z programu"<<endl;

    char wybor;

    do
    {
        wybor = _getch();
    }
    while(wybor != '1' && wybor != '2' && wybor != '3');
    switch(wybor)
    {
    case '1':
        zainicjujSymulacje();
        menu();
        break;
    case '2':
        zmienUstawienia(false, H,L);
        menu();
        break;
    case '3':
        return;
    }
}

void Interfejs::pokazUstawienia()
{
    cout <<"__________________________________________"<<endl;
    cout << "Aktualne ustawienia:"<<endl;
    cout<<"Wysokosc planszy = "<<H<<"    Szerokosc planszy = "<<L<<endl;
    cout <<"__________________________________________"<<endl;
}


void Interfejs::zmienUstawienia(bool zmien, short temp_H, short temp_L)
{
    system("cls");
    pokazUstawienia();
    cout<<endl;
    cout<<"Co chcesz zrobic?"<<endl;
    cout<<"W - Zmien wysokosc planszy"<<endl;
    cout<<"S - Zmien szerokosc planszy"<<endl;
    cout<<"Z - Powrot do poprzedniego menu"<<endl;
    cout<<endl;
    char wybor;
    do{
        wybor = _getch();
        wybor = toupper(wybor);
    } while (wybor != 'W' && wybor !='S' && wybor != 'Z');

    switch(wybor)
    {
    case 'W':
        cout<<"Podaj wysokosc planszy:"<<endl;
        H = pobierzDane(5,30);
        zmienUstawienia(true, H,L);
        return;
    case 'S':
        cout<<"Podaj szerokosc planszy:"<<endl;
        L = pobierzDane(5,30);
        zmienUstawienia(true, H,L);
        return;
    case 'Z':
        if(zmien)
        {
            cout<<"Czy zapisac zmiany[T/N]"<<endl;
            do
            {
                wybor = _getch();
                wybor = toupper(wybor);
            }
            while(wybor != 'T'&& wybor!='N');
            if(wybor == 'T')
            {
                ofstream file;
                file.open(CONFIG);
                file << H<< ' '<<L;
                _getch();
            }else{
                cout <<"Powrot z przywroceniem poprzednich wartosci"<<endl;
                _getch();
            }
        }
        return;
    }

}

short Interfejs::pobierzDane(short a, short b)
{
    short out;
    cin>>out;
    while (out < a || out > b || cin.fail())
    {
        cout<<"Podana wartosc jest niepoprawana. Prosze podaj liczbe z przedzialu od "<<a<<" do "<<b<<": ";
        cin >> out;
        cin.clear();
        cin.ignore(9999,'\n');
    }
    cin.ignore(9999,'\n');
    return out;
}

void Interfejs::zainicjujSymulacje()
{
    symulacja = new Symulacja;
    symulacja->start();
    //delete symulacja;
}
