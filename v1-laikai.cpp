#include "functions.h"

int main() {

    int pasirinkimas = 0;
    cout << "Ar norite, kad faile butu galutinis su vidurkiu, ar su mediana? Virdurkis, spauskite 1, mediana 0\n";

        cin >> pasirinkimas;
        checkInput(pasirinkimas);

    vector <studentas> a;

    vector <studentas> protV;


    int index = 0;
   //Antroji strategija
    Timer t;
    createFiles(a, pasirinkimas);
    readFile (index, a);
    sortSbyName(a);
    vargProt(a, protV);
    sortStud(a, pasirinkimas, protV);
    cout << "Elapsed time(whole program, second strategy) with vector: " << t.elapsed() << " s\n";
    a.clear();
    protV.clear();
    t.reset();
    return 0;
}