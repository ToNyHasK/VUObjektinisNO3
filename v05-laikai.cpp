#include "createFilesFunc.cpp"





int main() {

    int pasirinkimas = 0;
    cout << "Ar norite, kad faile butu galutinis su vidurkiu, ar su mediana? Virdurkis, spauskite 1, mediana 0\n";

        cin >> pasirinkimas;

    vector<studentas> a;
    deque<studentas> b;
    list<studentas> c;
    vector<double> vargsiukaiV;
    vector<double> protingiejiV;
    vector<double> vargsiukaiM;
    vector<double> protingiejiM;
    Timer t;
    createFiles(a, vargsiukaiV, protingiejiV, pasirinkimas, vargsiukaiM, protingiejiM);
    sortStud(vargsiukaiV, protingiejiV, pasirinkimas, vargsiukaiM, protingiejiM);
    cout << "Elapsed time(whole program) with vector: " << t.elapsed() << " s\n";
    vargsiukaiV.clear();
    protingiejiV.clear();
    vargsiukaiM.clear();
    protingiejiM.clear();
    t.reset();
    createFiles(b, vargsiukaiV, protingiejiV, pasirinkimas, vargsiukaiM, protingiejiM);
    sortStud(vargsiukaiV, protingiejiV, pasirinkimas, vargsiukaiM, protingiejiM);
    cout << "Elapsed time(whole program) with deque: " << t.elapsed() << " s\n";
    vargsiukaiV.clear();
    protingiejiV.clear();
    vargsiukaiM.clear();
    protingiejiM.clear();
    t.reset();
    createFiles(c, vargsiukaiV, protingiejiV, pasirinkimas, vargsiukaiM, protingiejiM);
    sortStud(vargsiukaiV, protingiejiV, pasirinkimas, vargsiukaiM, protingiejiM);
    cout << "Elapsed time(whole program) with list: " << t.elapsed() << " s\n";


    return 0;
}
