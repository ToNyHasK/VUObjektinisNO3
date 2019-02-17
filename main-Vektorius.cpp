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
void display(studentas *s, int temporary);
int main()
{
cout << "Kiek noresite ivesti studentu ?"<< endl;
            int stud;
            cin >> stud;
             while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "Neteisingai ivedete, veskite dar karta! ";
        cin >> stud;
    }

    cout << endl;
    studentas *s = new studentas[stud];

for (int i=0; i<stud; i++){
    s[i].data();
}
display(s, stud);
 return 0;
}
void display(studentas *s, int temporary)
{
 //Displaying information

cout << "Jeigu norite skaiciuote galutini su vidurkiu spauskitine 0, jeigu su mediana, spauskite 1: "<< endl;
int tmp=0;
cin >> tmp;
if (tmp == 0){
        //Su vidurkiu
        cout << "Jusu pateikta informacija(pasirinkote skaiciuoti su vidurkiu): " << endl;

        cout << "Pavarde            Vardas          Galutinis(Vid.)" << endl;


        cout <<"------------------------------------------------------------"<<endl;


    for (int i = 0; i <temporary; ++i)
{
        cout << s[i].firstName << "         " << s[i].secondName << fixed<< setprecision(2) <<"         "<< s[i].galutinioV() << endl;
}
}
//Su mediana
else {
    cout << "Jusu pateikta informacija(pasirinkote skaiciuoti su mediana): " << endl;

        cout << "Pavarde            Vardas          Galutinis(Med.)" << endl;


        cout <<"------------------------------------------------------------"<<endl;



    for (int i = 0; i < temporary; ++i)
{
        cout << s[i].firstName << "         " << s[i].secondName << fixed<< setprecision(2) <<"         "<< s[i].galutinioM() << endl;
}
}
}

