#include "Czastka.h"
#include <string>
const int szer=256; //SZEROKOŒÆ LINII

void br() {cout<<"***********************************************\n";}

int main(int argc, char *argv[])
{
    cout << "Czytam pliku: " <<argv[1]<<endl; int lZderzen=stoi(argv[2]);
    cout<<"Liczba zderzenñ: "<<lZderzen<<endl;
    try
    {
        ifstream in(argv[1]); if(!in.good())    throw("Otwarcie pliku siê nie uda³o.");
//        vector<Czastka> **dane; //dane=new vector<Czastka>[lZderzen];
//        dane = new vector<Czastka> *[lZderzen];
//        for(int i=0;i<lZderzen;i++) dane[i] = new vector<Czastka> [rodzaj(neutron)];
        vector<Czastka> *dane; dane=new vector<Czastka> [rodzaj(neutron)+1]; //neutron ostatni w enumie        for(int i=0;i<lZderzen;i++)
        for(int i=0;i<lZderzen;i++)
        {
            int xNr; in>>xNr; //Wczytujemy numer zderzenia
            int nDoWczytania=0; in>>nDoWczytania; cout<<"Zderzenie "<<i+1<<" liczba cz¹stek: "<<nDoWczytania<<endl;
            for(int j=0;j<nDoWczytania;j++)
            {
                int id=0; in>>id; if(id!=j)    throw("B³¹d przy wczytywaniu");
                double wx, wy, wz, wpx, wpy, wpz, wpid; in>>wpid>>wpx>>wpy>>wpz>>wx>>wy>>wz;
                Czastka wCz(wpid,wx,wy,wz,wpx,wpy,wpz);
                //Teraz sprawdziwmy jakiego typu jest cz¹stka
                if(wpid==211)   dane[rodzaj(pion_d)].push_back(wCz); //Pion dodatni
                else if(wpid==-211)   dane[rodzaj(pion_u)].push_back(wCz); //ujemny
                else if(wpid==321)    dane[rodzaj(kaon_d)].push_back(wCz); //Kaon dodatni
                else if(wpid==-321)    dane[rodzaj(kaon_u)].push_back(wCz); //ujemny
                else if(wpid==2212)    dane[rodzaj(proton)].push_back(wCz); //Proton
                else if(wpid==-2212)    dane[rodzaj(antyproton)].push_back(wCz); //Antyproton
                else if(wpid==11)    dane[rodzaj(elektron)].push_back(wCz); //Elektron
                else if(wpid==-11)    dane[rodzaj(pozyton)].push_back(wCz); //Pozyton
                else if(wpid==2112)    dane[rodzaj(neutron)].push_back(wCz); //Neutron
//                wCz.zapisz(cout);
            }

        }
        br();
        for(int R=0;R<=rodzaj(neutron);R++)
        {
            cout<<"Liczba "<<coToJest(R)<<": "<<dane[R].size()<<endl;
            cout<<"Œredni pêd poprzeczny wynosi: "<<liczSrPt(dane[R])<<endl
                <<"Œredni promieñ poprzeczny wynosi: "<<liczSrRt(dane[R])<<endl
                <<"Œredni pêd wynosi: "<<liczSrP(dane[R])<<endl
                <<"Œrednia wartoœæ z wynosi: "<<liczSrZ(dane[R])<<endl;
        }
        br(); double suma_D = dane[rodzaj(pion_d)].size()+dane[rodzaj(kaon_d)].size()+dane[rodzaj(proton)].size()+dane[rodzaj(pozyton)].size();
        double suma_U = dane[rodzaj(pion_u)].size()+dane[rodzaj(kaon_u)].size()+dane[rodzaj(antyproton)].size()+dane[rodzaj(elektron)].size();
        cout<<"Stosunek czastek:\n"
        <<"p/p_bar: "<<(double) dane[rodzaj(proton)].size()/dane[rodzaj(pozyton)].size()<<endl
        <<"pi+/pi-: "<<(double) dane[rodzaj(pion_d)].size()/dane[rodzaj(pion_u)].size()<<endl
        <<"K+/K-: "<<(double) dane[rodzaj(kaon_d)].size()/dane[rodzaj(kaon_u)].size()<<endl
        <<"e/e_bar:"<<(double) dane[rodzaj(elektron)].size()/dane[rodzaj(pozyton)].size()<<endl
        <<"p/e: "<<(double) dane[rodzaj(proton)].size()/dane[rodzaj(elektron)].size()<<endl
        <<"pi+/K+: "<<(double) dane[rodzaj(pion_d)].size()/dane[rodzaj(kaon_d)].size()<<endl
        <<"p/n: "<<(double) dane[rodzaj(proton)].size()/dane[rodzaj(neutron)].size()<<endl
        <<"Cz+/Cz-:"<<(double) suma_D/suma_U<<endl;


        in.close();
    }
    catch(const char *msg)
    {
        cerr<<*msg<<endl;
    }
    return 0;
}
