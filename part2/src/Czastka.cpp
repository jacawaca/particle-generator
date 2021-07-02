#include "Czastka.h"

Czastka::Czastka(int pidd, double xx,double yy,double zz,double pxx,double pyy,double pzz)
    : PID(pidd), x(xx), y(yy), z(zz), px(pxx), py(pyy), pz(pzz)
{ }

double Czastka::dajP() {return sqrt(pow(px,2)+pow(py,2)+pow(pz,2));}
double Czastka::dajPT() {return sqrt(pow(px,2)+pow(py,2));}
double Czastka::dajRT() {return sqrt(pow(x,2)+pow(y,2));}
double Czastka::dajZ() {return z;}

double liczSrPt(vector<Czastka> Atm)
{
    double wynik=0;
    for(auto i: Atm)
    {
        wynik += i.dajPT();
    }
    return wynik;
}
double liczSrRt(vector<Czastka> Atm)
{
    double wynik=0;
    for(auto i: Atm)
    {
        wynik += i.dajRT();
    }
    return wynik;
}
double liczSrP(vector<Czastka> Atm)
{
    double wynik=0;
    for(auto i: Atm)
    {
        wynik += i.dajP();
    }
    return wynik;
}
double liczSrZ(vector<Czastka> Atm)
{
    double wynik=0;
    for(auto i: Atm)
    {
        wynik += i.dajZ();
    }
    return wynik;
}


void Czastka::zapisz(ostream & out)
{
    out<<PID<<' '<<px<<' '<<py<<' '<<pz<<' '<<x<<' '<<y<<' '<<z<<endl;
}

Czastka::~Czastka()
{
    //dtor
}

string coToJest(int x)
{
    switch(x)
    {
    case rodzaj(pion_d):

        return "Pion�w dodatnich";
    case rodzaj(pion_u):

        return "Pion�w ujemnych";
    case rodzaj(kaon_d):

        return "Kaon�w dodatnich";
    case rodzaj(kaon_u):

        return "Kaon�w ujemnych";
    case rodzaj(proton):

        return "Proton�w";
    case rodzaj(antyproton):

        return "Antyproton�w";
    case rodzaj(elektron):

        return "Elektron�w";
    case rodzaj(pozyton):

        return "Pozyton�w";
    case rodzaj(neutron):

        return "Neutron�w";
    }
}
