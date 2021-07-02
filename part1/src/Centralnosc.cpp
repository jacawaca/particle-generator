#include "Centralnosc.h"
using namespace std;
Centralnosc::Centralnosc(int klasa)
{
    switch(klasa)
    {
    case 0:
        nCzastek = rand()%201+400;
        break;
    case 1:
        nCzastek = rand()%201+200;
        break;
    case 2:
        nCzastek = rand()%101+100;
        break;
    case 3:
        nCzastek = rand()%51+50;
        break;
    case 4:
        nCzastek = rand()%50+1;
        break;
    }

}

Centralnosc::~Centralnosc()
{
    //dtor
}

void Centralnosc::wypisz(ostream & out,int id)
{
    out<<id<<' '<<nCzastek<<endl;
}
int Centralnosc::giveCzastek(){return nCzastek;}


// Funkcje do wczytywania pliku
const int szer=256; //do ignorowania w strumieniu

void wczytaj(ifstream & in,fHead &H)
{
    while(!in.eof())
        {
            string cmd;
            getline(in,cmd);
            if(cmd=="#centralnosc")
            {
                in>>H.fCentralnosc;
            }
            else if(cmd=="#ped")
            {
                in>>H.fPed;
            }
            else if(cmd=="#polozenie")
            {
                in>>H.fPolozenie;
            }
            else if(cmd=="#ilosc zderzen")
            {
                in>>H.fZderzen;
            }
            else if(cmd=="#plik wynikowy")
            {
                in>>H.fWyjscie;
            }
            else if(cmd=="#tryb glosny") // Mia³em problemy z polskimi znakami
            { //i zmodyfikowa³em wejsciowy
                in>>H.fGlosnosc;
            }
            in.ignore(szer,'\n');
        }
}
void fHead::wypisz()
{
    cout<<"#centralnosc\n"<<fCentralnosc<<"\n#ped\n"<<fPed<<"\n#polozenie\n"<<fPolozenie<<"\n#ilosc zderzen\n"<<fZderzen<<"\n#plik wynikowy\n"<<fWyjscie<<"\n#tryb\n"<<fGlosnosc<<endl;
}
