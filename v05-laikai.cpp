#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include <random>
#include <string>
#include <fstream>
#include <chrono>
#include <list>
#include <deque>


using namespace std;



struct studentas {

    vector<int> nd;
    double egz = 0;
    double visiNd = 0;
    string firstName = "Vardas";
    string secondName = "Pavarde";


    void randomNumbers(int haha) {

        visiNd = 10;

        const unsigned int seed = time(0) + haha;
        mt19937_64 rng(seed);
        uniform_real_distribution<> random(1, 10);

        for (int i = 0; i<visiNd; i++) {
            nd.push_back(random(rng));
//          cout << nd[i] << "\n";
        }

        egz = static_cast<int>(random(rng));
//      cout << "Egz: " << egz << "\n";
    }

    double vid () {

        double vidutinis = 0;

        for (auto &viens : nd) {
            vidutinis += viens;
        }

        vidutinis /= nd.size();

        return vidutinis;
    }
//Medianos skaiciavimas

    int median (vector<int>set) {
        sort(set.begin(), set.end());
        return (set.size()% 2 == 0 ? (set[set.size()/2] + set[(set.size() / 2 ) - 1]) / 2 : set[set.size() / 2]);
    }

    double galutinioM() {
        return 0.4 * median(nd) + 0.6 * egz;
    }

    double galutinioV() {
        return 0.4 * vid() + 0.6 * egz;
    }

};

void checkInput(int &input) {

    while (cin.fail() || (input !=1 && input !=0)){
            cout << "Blogas irasymas, bandykite dar karta: \n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> input;
    }

}


void createFiles(vector<double> &vargsiukaiV, vector<double> &protingiejiV, int &pasirinkimas, vector<double> &vargsiukaiM, vector<double> &protingiejiM) {

    list<studentas> s;
    int visiStudentai = 1;
    int counter = 0;

    cout << "Ar norite, kad faile butu galutinis su vidurkiu, ar su mediana? Virdurkis, spauskite 1, mediana 0\n";

        cin >> pasirinkimas;

    //tikrinimas
    checkInput(pasirinkimas);

    if (pasirinkimas == 1){

            for (int i = 1;  i <= 5; i++) {

        counter++;
        ofstream file;
        file.open ("studentai" + to_string(i) + ".txt");

        if (file.is_open())
        {
            file << "firstName"<< setw(20) <<"secondName"<< setw(20) <<"Galutinis(Vid.)\n";
            file << "\n";
        }

         visiStudentai *= 10;
         s.resize(visiStudentai);
         int ccounter = 0;

        for (list<studentas>::iterator it = s.begin(); it != s.end(); ++it){
            ccounter++;
            (*it).randomNumbers(counter+ccounter);

                if ((*it).galutinioV() >= 5){
                    protingiejiV.push_back((*it).galutinioV());
                }else{vargsiukaiV.push_back((*it).galutinioV());};

            if (file.is_open()){

                file << (*it).firstName << setw(20) << (*it).secondName << setw(20) << fixed << setprecision(2) << (*it).galutinioV()<<"\n";
            }
        }
        file.close();
        }

    }

    else {

        for (int i = 1;  i <= 5; i++) {

            counter++;
            ofstream file;
            file.open ("studentai" + to_string(i) + ".txt");

            if (file.is_open())
            {
                file << "firstName" << setw(20) << "secondName" << setw(20) << "Galutinis(Med.) \n";
                file << "\n";
            }

            visiStudentai *= 10;
            s.resize(visiStudentai);
            int ccounter = 0;

            for (list<studentas>::iterator it = s.begin(); it != s.end(); ++it){

            ccounter++;
            (*it).randomNumbers(counter+ccounter);

                if ((*it).galutinioM() >= 5){
                    protingiejiM.push_back((*it).galutinioM());
                } else{vargsiukaiM.push_back((*it).galutinioM());}

                if (file.is_open()){

                    file << (*it).firstName << setw(20) << (*it).secondName << setw(20) << fixed << setprecision(2) << (*it).galutinioM() << "\n";
                }
            }

            file.close();
        }
    }
}


void sortStud(vector<double> vargsiukaiV, vector<double> protingiejiV, int pasirinkimas, vector<double> vargsiukaiM, vector<double> protingiejiM) {

    ofstream naujas;
    naujas.open ("vargsiukai.txt");
    if(pasirinkimas == 1) {
        if (naujas.is_open())
        {
            naujas << "firstName"<< setw(20) <<"secondName"<< setw(20) <<"Galutinis(Vid.)\n";
            naujas << "\n";

            for (int i = 0; i < vargsiukaiV.size(); i++) {
                naujas << "Vardas" << setw(20) << "Pavarde" << setw(20) << vargsiukaiV[i] <<"\n";
            }
        }

    }
    else{

       if (naujas.is_open())
        {
            naujas << "firstName"<< setw(20) <<"secondName"<< setw(20) <<"Galutinis(Med.)\n";
            naujas << "\n";

            for (int i = 0; i < vargsiukaiM.size(); i++) {
                naujas << "Vardas" << setw(20) << "Pavarde" << setw(20) << vargsiukaiM[i] <<"\n";
            }
        }
    }
    naujas.close();

    ofstream naujausias;
    naujausias.open ("protingieji.txt");
    if(pasirinkimas == 1) {
        if (naujausias.is_open())
        {
            naujausias << "firstName"<< setw(20) <<"secondName"<< setw(20) <<"Galutinis(Vid.)\n";
            naujausias << "\n";

            for (int i = 0; i < protingiejiV.size(); i++) {
                naujausias << "Vardas" << setw(20) << "Pavarde" << setw(20) << protingiejiV[i] <<"\n";
            }
        }

    }
    else{

       if (naujausias.is_open())
        {
            naujausias << "firstName"<< setw(20) <<"secondName"<< setw(20) <<"Galutinis(Med.)\n";
            naujausias << "\n";

            for (int i = 0; i < protingiejiM.size(); i++) {
                naujausias << "Vardas" << setw(20) << "Pavarde" << setw(20) << protingiejiM[i] <<"\n";
            }
        }
    }
    naujausias.close();


}


int main() {


    int pasirinkimas = 0;
    vector<double> vargsiukaiV;
    vector<double> protingiejiV;
    vector<double> vargsiukaiM;
    vector<double> protingiejiM;
    auto start = std::chrono::high_resolution_clock::now();
    createFiles(vargsiukaiV, protingiejiV, pasirinkimas, vargsiukaiM, protingiejiM);
    sortStud(vargsiukaiV, protingiejiV, pasirinkimas, vargsiukaiM, protingiejiM);
    auto finish = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Elapsed time(whole program): " << elapsed.count() << " s\n";

    return 0;
}
