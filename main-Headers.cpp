#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include <random>
#include <string>
#include <fstream>
#include "structFunctions.h"

using namespace std;

void checkInput(int &input);
struct studentas;
void readFile (int &index, vector<studentas> &s);
void display(vector<studentas> s, int index);
bool mycomp(const studentas & s1, const studentas & s2);
void sortSbyName(vector<studentas> &s);

int main()
{
    vector<studentas> s;
    cout << "Ar norite nuskaityti studentus is failo, ar ivesti pats? 1 - jei pats, 0 - jei is failo\n";

    int pasirinkimas;
    cin >> pasirinkimas;
    //tikrinimas
    checkInput(pasirinkimas);

    int index = 0;

    if (pasirinkimas == 0) {
        readFile(index, s);
    } else if (pasirinkimas == 1) {
        cout << "Kiek noresite ivesti studentu ?" << endl;
        int stud;
        cin >> stud;
        while(cin.fail() || stud > 100000) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Neteisingai ivedete, veskite dar karta! ";
            cin >> stud;
        }
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        s.resize(stud);
        index = stud;

        cout << "\n";

        for (int i = 0; i < stud; i++) {
            s[i].data();
        }

    }


    sortSbyName(s);
    display(s, index);

    return 0;
}
