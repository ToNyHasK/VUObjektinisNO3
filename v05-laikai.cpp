#include "createFilesFunc.cpp"

int main() {

    int pasirinkimas = 0;
    cout << "Ar norite, kad faile butu galutinis su vidurkiu, ar su mediana? Virdurkis, spauskite 1, mediana 0\n";

        cin >> pasirinkimas;
        checkInput(pasirinkimas);

    vector <studentas> a;
    deque <studentas> b;
    list <studentas> c;

    vector <studentas> protV;
    deque <studentas> protD;
    list <studentas> protL;

    vector <studentas> vargV;
    deque <studentas> vargD;
    list <studentas> vargL;


    int index = 0;

    //Pirmoji strategija

    createFiles(a, pasirinkimas);
    Timer t;
    readFile (index, a);
    sortSbyName(a);
    vargProt(a, vargV, protV);
    sortStud(a, pasirinkimas, vargV, protV);
    cout << "Elapsed time(whole program, first strategy) with vector: " << t.elapsed() << " s\n";
    a.clear();
    protV.clear();
    vargV.clear();

    //createFiles(b, pasirinkimas);
    t.reset();
    readFile (index, b);
    sortSbyName(b);
    vargProt(b, vargD, protD);
    sortStud(b, pasirinkimas, vargD, protD);
    cout << "Elapsed time(whole program, first strategy) with deque: " << t.elapsed() << " s\n";
    b.clear();
    protD.clear();
    vargD.clear();

    //createFiles(c, pasirinkimas);
    t.reset();
    readFile (c);
    sortSbyName(c);
    vargProt(c, vargL, protL);
    sortStud(c, pasirinkimas, vargL, protL);
    cout << "Elapsed time(whole program, first strategy) with list: " << t.elapsed() << " s\n";
    c.clear();
    protL.clear();
    vargL.clear();
    t.reset();



    return 0;
}
