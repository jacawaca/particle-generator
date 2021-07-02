#include "Czastka.h"

double Czastka::maxPed=1;
double Czastka::maxR=1;
bool Czastka::verbose=true;

void precyzja(double & x, int poPrz)
{
    int W = x*pow(10,poPrz);
    x=W/pow(10,poPrz);
}

void rzutowanie(Czastka &cz, double obP, double maxP, bool czyPed)
{
    //Funkcja zostaje losowo zrzutowana do dozwolonego przedzia³u
    // Zachowywane zostaj¹ proporcje miêdzy sk³adowymi pêdu
    // Pêd [ca³kowity] przybiera procent wartoœci maksymalnej
    double los= (double) (rand()%100+1)/100; double skala=1;
    skala = los*(maxP/obP);
    if(czyPed)
    {
        cz.px= cz.px*skala; precyzja(cz.px,1);
        cz.py= cz.py*skala; precyzja(cz.py,1);
        cz.pz= cz.pz*skala; precyzja(cz.pz,1);
    }
    else
    {
        cz.x= cz.x*skala; precyzja(cz.x,2);
        cz.y= cz.y*skala; precyzja(cz.y,2);
        cz.z= cz.z*skala; precyzja(cz.z,2);
    }

}

//Czastka::Czastka(double xx, double yy,double zz, double ppx,double ppy, double ppz):
//    x(xx),y(yy),z(zz),px(ppx),py(ppy),pz(ppz)
Czastka::Czastka(std::default_random_engine & eng, std::normal_distribution<double> & nDis)  //
{
    px= (double) (rand()%101)/10; py= (double) (rand()%101)/10; pz= (double) (rand()%101)/10;
    x=nDis(eng);y=nDis(eng);z=nDis(eng);
    precyzja(x,2); precyzja(y,2); precyzja(z,2);
    /*
    Precyzja jest niezmieniona
    Wydaje mi siê, ¿e aby zmieniæ prec, trzeba by zmieniæ typ z double na inny
    https://stackoverflow.com/questions/13085219/reducing-the-digits-of-a-double-in-c
    Zrobiê zapis do pliku, który obetnie koñcówkê
    https://www.quora.com/How-can-I-round-a-double-number-to-3-decimal-digits-in-C++
    TAK
    */
    double Ped = sqrt(pow(px,2)+pow(py,2)+pow(pz,2));
    double Pro = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    if(Ped > maxPed) rzutowanie(*this,Ped,maxPed,true);
    if(Pro>maxR)   rzutowanie(*this,Pro,maxR,false);
    //Losowanie PIDu
    double losPID=(rand()%100+1); //Losuje 1-100
    if(losPID<=32)   PID=211; //Pion dodatni
    else if(losPID<=32+34)   PID=-211; //ujemny
    else if(losPID<=32+34+10)    PID=321; //Kaon dodatni
    else if(losPID<=32+34+10+8)    PID=-321; //ujemny
    else if(losPID<=32+34+10+8+5)    PID=2212; //Proton
    else if(losPID<=32+34+10+8+5+1)    PID=-2212; //Antyproton
    else if(losPID<=32+34+10+8+5+1+3)    PID=11; //Elektron
    else if(losPID<=32+34+10+8+5+1+3+3)    PID=-11; //Pozyton
    else   PID=2112; //Neutron


}

void Czastka::zapisz(ostream & out)
{
    out<<PID<<' '<<px<<' '<<py<<' '<<pz<<' '<<x<<' '<<y<<' '<<z<<endl;
}

Czastka::~Czastka()
{
    //dtor
}
