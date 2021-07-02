#ifndef CENTRALNOSC_H
#define CENTRALNOSC_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
class Centralnosc
{
    public:
        Centralnosc(int klasa);
        virtual ~Centralnosc();
        void wypisz(ostream &,int);
        int giveCzastek();

    protected:

    private:
        int nCzastek;
};

//Czêœæ do wczytywania pliku

struct fHead
{
    string fWyjscie;
    double fPed, fPolozenie;
    int fZderzen, fCentralnosc;
    bool fGlosnosc;
    void wypisz();
};

void wczytaj(ifstream &,fHead &);
#endif // CENTRALNOSC_H
