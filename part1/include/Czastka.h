#ifndef CZASTKA_H
#define CZASTKA_H
#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <chrono>
//#include <ostream>
//#include <cstdlib>
void precyzja(double &,int);
using namespace std;
class Czastka
{
    public:
        Czastka(std::default_random_engine &, std::normal_distribution<double> &); //silnik i rozk³ad normalny
        virtual ~Czastka();
        static double maxPed;
        static double maxR;
        static bool verbose;
        void zapisz(ostream&);
        friend void rzutowanie(Czastka &,double,double,bool); //do zmniejszania wiêcej-ni¿-maksymalnego pêdu


    protected:

    private:
        int PID;
        double x, y, z, px, py, pz;
};

#endif // CZASTKA_H
