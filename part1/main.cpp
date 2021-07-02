#include "Czastka.h"
#include "Centralnosc.h"
const string nPlik="wejscie.txt"; //Domyślna nazwa pliku

int main(int argc, char *argv[])
{
    srand(time(0));
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    try
    {
        ifstream in;
        if(argc==2)     in.open(argv[1], std::ifstream::in);
        else    in.open(nPlik,std::ifstream::in); //Domyœlne wejœcie
        if(!in.good()) throw "Brak pliku wejściowego!";
        // Nagłówek pliku
        fHead Head; //info z pliku
        wczytaj(in,Head); //zamienić na składową fHead ??
//        Head.wypisz();
        Czastka::maxPed=Head.fPed;
        Czastka::maxR=Head.fPolozenie;
        Czastka::verbose=Head.fGlosnosc;
        ofstream out(Head.fWyjscie);
        if(!out.good()) throw "Nie udało się utworzyć pliku wyjściowego";
        for(int i=1;i<=Head.fZderzen;i++)
        {
            Centralnosc centr(Head.fCentralnosc);
            if(Czastka::verbose)  centr.wypisz(out,i);
            std::default_random_engine eng(seed);
            std::normal_distribution<double> norD(0,sqrt(10)); //wartość oczeki  wana = 0, odchylenie = sqrt(wariancja = 10)
            for(int j=0;j<centr.giveCzastek();j++)
            {
                Czastka cz(eng,norD);
                out<<j<<' ';
                cz.zapisz(out);
            }
        }
        out.close();
        in.close();
    }
    catch(const char *msg)
    {
        cerr<<msg<<endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
