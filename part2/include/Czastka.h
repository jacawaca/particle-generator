#ifndef CZASTKA_H
#define CZASTKA_H
#include <iostream>
#include <fstream>
#include <cmath>
//#include <ostream>
//#include <cstdlib>
#include <vector>
using namespace std;
class Czastka
{
    public:
        virtual ~Czastka();
        Czastka(int, double, double, double, double, double, double);
        void zapisz(ostream&);
        //CZÊŒÆ II
        double dajPT(), dajRT(), dajP(), dajZ();
        friend double liczSrPt(vector<Czastka>);
        friend double liczSrRt(vector<Czastka>);
        friend double liczSrP(vector<Czastka>);
        friend double liczSrZ(vector<Czastka>);


    protected:

    private:
        int PID;
        double x, y, z, px, py, pz;
};

enum rodzaj
{
    pion_d, //0
    pion_u,
    kaon_d,
    kaon_u,
    proton,
    antyproton,
    elektron ,
    pozyton,
    neutron //8
};

string coToJest(int);

#endif // CZASTKA_H
