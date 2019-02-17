//Naudoju vektorius, taip patogiau ir lyg uzd parasyta taip... reikia naudoti vektoriu. vektoriai = love;0
//Reikia pataisyt vardo ir pavardes isvedima, also kazkodel blogai isveda vidurki pazymiu, reik ir ta sutvarkyt
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include <time.h>
#include <random>
#include <string>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;
struct studentas{


string firstName;
string secondName;

vector<double> nd;
double visiNd = 0;
double egz = 0;



void data()
{
    //Storing information
    cout << "Studento vardas: ";
    cin >> firstName;
    cout << endl;
    cout << "Studento pavarde: ";
    cin >> secondName;
    cout << endl;
    //
    cout << "Ar noresite sugeneruoti random pazymius ir egzamino balus? Random - spauskite 1. Ivesties budu - spauskite 0: "<<endl;
            int b;
            cin >> b;

            if (b == 1)
            {
                randomNumbers();

            }
            else {
                numberInput();
                cout << "Iveskite studento egzamino rezultata: "<< endl;
                cin >> egz;
            }




}
// Generuoja random skaicius
void randomNumbers()
{
    cout << "Iveskite kiek norite sugeneruoti skaiciu!: "<< endl;
    cin >> visiNd;
    while (cin.fail()) {
       cout << "Blogas irasymas, bandykite dar karta: "<<endl;
       cin.clear();
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       cin >> visiNd;
   }
   nd.reserve(visiNd);
   const unsigned int seed = time(0);
   mt19937_64 rng(seed);
   uniform_real_distribution<double> random(1, 10);
   for (int i = 0; i<visiNd; i++)
   {
       nd.push_back((int)random(rng));
   }
egz = (int)random(rng);

}
//Rankiniu budu turi suvest nd ir egz
void numberInput()
{
    cout << "Iveskit namu darbu pazymius, norint pabaigti, iveskite ne skaiciu! "<<endl;
        int skc;
    while (cin >> skc)
    {
        if (!(skc >= 1 && skc <= 10)) {
                cout << "Pazymys turi buti tarp 1 ir 10! " << endl;
                    continue;
    }
    nd.push_back(skc);

}
visiNd  = nd.size();
cin.clear();
cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}
//Vidutinio skaiciavimas
double vid ()
{
    double vidutinis = 0;
    for (int i = 0; i < visiNd; i++)
    {
        vidutinis = vidutinis + nd[i];
    }
    vidutinis = vidutinis / visiNd;
    return vidutinis;

}

//Medianos skaiciavimas
double median (vector<double>set)
{
    sort(set.begin(), set.end());

return (set.size()% 2 == 0 ? (set[set.size()/2] + set[(set.size() / 2 ) - 1]) / 2 : set[set.size() / 2]);
}
double galutinioM()
{
    return 0.4 * median(nd) + 0.6 * egz;
}
double galutinioV()
{
    return 0.4 * vid() + 0.6 * egz;
}

};
void display(vector<string> virtuA, vector <studentas> st);
//main funkcija, skaito,prideda..
int main()
{
    ifstream fd ("studentai.txt");
    //Tikrinam, ar gezistuoja failas

        if (fd.fail()) {
            cout << "<studentai.txt> neagzistuoja, prasome sukurti faila";
            return 1;
    }




    //Pradedam skaitymo proceca
    vector<string>virtuA;
    vector<studentas>st;
    string virtuB;
    string virtuC;
    getline(fd, virtuB);

    //Tikrinam eilutes
    if (virtuB.empty()) {
        cout << "Pirmoje eiluteja nieko nera! ";
        return 2;
    }

    istringstream onLine(virtuB);

                while (onLine >> virtuC) {
                    virtuA.push_back(virtuC);
                        }
    const int visuNd = virtuA.size()-3;
     while (getline(fd, virtuB)) {
        istringstream onLine(virtuB);
        studentas s;
        onLine >> s.firstName >> s.secondName;
            for (int i = 0; i < visuNd; i++) {
            double notDB;
            onLine >> notDB;
            s.nd.push_back(notDB);
        }
        onLine >> s.egz;
        st.push_back(s);
     }
display(virtuA, st);
cin.get();
return 0;
}
//atspauzdint fukcija
void display (vector<string> virtuA, vector <studentas> st)
{
    //pirma reikia issortint, pagal vardus (arba) pavardes, kad eitu is eiles

    sort(st.begin(), st.end() , [](studentas kimo, studentas kima){return kimo.firstName<kima.firstName;});
    cout << left <<setw(10)<< virtuA[0] <<setw(10)<<virtuA[1]<<setw(20)<<"Galutinis(Vid.)"<< "Galutinis(Med.)"<<endl;
    cout << "-------------------------------------------------"<< endl;
    for (auto &s : st) {
        cout << fixed << setprecision(2) << left << setw(10)<< s.firstName <<  setw(10) <<s.secondName <<  setw(20) << s.galutinioV() << s.galutinioM() << endl;
    }



}

