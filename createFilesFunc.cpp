#include "header.h"
// Student
///////////////////////////////////////////////////////////////////////////////////////
// Functions
void studentas::randomNumbers(int haha) {

    const unsigned int seed = time(0) + haha;
    mt19937_64 rng(seed);
    uniform_real_distribution<> random(1, 10);

    for (int i = 0; i<10; i++) {
        nd.push_back(random(rng));
//          cout << nd[i] << "\n";
    }

    egz = random(rng);
//      cout << "Egz: " << egz << "\n";
}

double studentas::vid () {

    double vidutinis = 0;

    for (auto &viens : nd) {
        vidutinis += viens;
    }

    vidutinis /= nd.size();

    return vidutinis;
}

int studentas::median () {
    sort(nd.begin(), nd.end());
    return (nd.size()% 2 == 0 ? (nd[nd.size()/2] + nd[(nd.size() / 2 ) - 1]) / 2 : nd[nd.size() / 2]);
}

double studentas::galutinioM() {
    return 0.4 * median() + 0.6 * egz;
}

double studentas::galutinioV() {
    return 0.4 * vid() + 0.6 * egz;
}
// Overloaded operators

studentas& studentas::operator=(const studentas& s) {

    if (&s == this) return *this;
    nd.clear();
    firstName = s.getName();
    secondName = s.getSurname();
    allMarks = s.getAllMarks();
    return *this;
}

 bool studentas::operator>(const studentas& s) {
    return allMarks > s.getAllMarks();
}

bool studentas::operator<(const studentas& s) {
    return allMarks < s.getAllMarks();
}
bool studentas::operator>=(const studentas& s) {
    return allMarks >= s.getAllMarks();
}
bool studentas::operator<=(const studentas& s) {
    return allMarks <= s.getAllMarks();
}
bool studentas::operator==(const studentas& s) {
    return allMarks == s.getAllMarks();
}
bool studentas::operator!=(const studentas& s) {
    return allMarks != s.getAllMarks();
}

///////////////////////////////////////////////////////////////////////////////////////
void checkInput(int &input) {

    while (cin.fail() || (input !=1 && input !=0)){
            cout << "Blogas irasymas, bandykite dar karta: \n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> input;
    }

}
bool mycomp(const studentas & s1, const studentas & s2) {
    return (s1.getName() < s2.getName());
}
void sortSbyName(vector<studentas> & s){
    sort(s.begin(), s.end(), mycomp);
}
//Second strategy
//______________________________________________________________________________________________________________________________________________________________
//Create file functions
void createFiles(vector<studentas> s, int pasirinkimas) {


    int visiStudentai = 1000;
    int counter = 0;

    if (pasirinkimas == 1){

        for (int i = 1;  i <= 2; i++) {

            counter++;
            ofstream file;
            file.open ("studentai" + to_string(i) + ".txt");
            if (file.is_open())
            {
                file << "firstName"<< setw(20) <<"secondName"<< setw(20) <<"Galutinis(Vid.)\n";
            }

            visiStudentai *= 10;
            s.resize(visiStudentai);
            int ccounter = 0;

            for (vector<studentas>::iterator it = s.begin(); it != s.end(); ++it){
                ccounter++;
                (*it).randomNumbers(counter + ccounter);

                if (file.is_open()){

                    file << "Vardas" + to_string(ccounter) << setw(20) << "Pavarde" + to_string(ccounter) << setw(20) << fixed << setprecision(2) << (*it).galutinioV()<<"\n";
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

            for (vector<studentas>::iterator it = s.begin(); it != s.end(); ++it){

                ccounter++;
                (*it).randomNumbers(counter + ccounter);

                if (file.is_open()){

                    file << "Vardas" + to_string(ccounter) << setw(20) << "Pavarde" + to_string(ccounter) << setw(20) << fixed << setprecision(2) << (*it).galutinioM() << "\n";
                }
            }

            file.close();
        }
    }
}
//Read file functions
void readFile (int index, vector<studentas> &s) {

    string line;
    string x = "studentai";
    string xB = "studentai";
    string y = ".txt";
    for (int i = 1; i <= 2; i++) {
        x.append(to_string(i));
        x.append(y);
        ifstream file_(x);

        getline(file_, line); //pirmas

        while (getline(file_, line)) {
            istringstream pirmi(line);
            s.push_back(studentas());
            s[index].setName(pirmi);
            s[index].setSurname(pirmi);
            s[index].setAllMarks(pirmi);

            index++;
        }
        x = xB;
    }
}
//Allocating marks
void vargProt(vector <studentas> &s, vector <studentas> &protingi) { //Pvz paimta is http://www.cplusplus.com/reference/algorithm/stable_partition/
                                                                    // Ir is https://www.youtube.com/watch?v=kf67rbbR6nk
   auto bound = stable_partition(s.begin(), s.end(), [&](const auto &tmp){return!(tmp.getAllMarks() >= 5);});

   protingi.insert(protingi.end(), make_move_iterator(bound), make_move_iterator(s.end()));
   s.erase(bound, s.end());
}
//Sort to two files functions
void sortStud(vector <studentas> s, int pasirinkimas, vector <studentas> protingi) {

    ofstream naujas;
    naujas.open ("vargsaiV2.txt");
    if(pasirinkimas == 1) {
        if (naujas.is_open())
        {
            naujas << "firstName"<< setw(20) <<"secondName"<< setw(20) <<"Galutinis(Vid.)\n";
            naujas << "\n";

            for (vector<studentas>::iterator it = s.begin(); it != s.end(); ++it){

                naujas << (*it).getName() << setw(20) << (*it).getSurname() << setw(20) << fixed << setprecision(2) << (*it).getAllMarks() << "\n";
            }
        }

    }

    else{

       if (naujas.is_open())
        {
            naujas << "firstName"<< setw(20) <<"secondName"<< setw(20) <<"Galutinis(Med.)\n";
            naujas << "\n";

            for (vector<studentas>::iterator it = s.begin(); it != s.end(); ++it){

                naujas << (*it).getName() << setw(20) << (*it).getSurname() << setw(20) << fixed << setprecision(2) << (*it).getAllMarks() <<"\n";
            }
        }
    }
    naujas.close();

    ofstream naujausias;
    naujausias.open ("protingiV2.txt");
    if(pasirinkimas == 1) {
        if (naujausias.is_open())
        {
            naujausias << "firstName"<< setw(20) <<"secondName"<< setw(20) <<"Galutinis(Vid.)\n";
            naujausias << "\n";

            for (vector<studentas>::iterator it = protingi.begin(); it != protingi.end(); ++it){

               naujausias << (*it).getName() << setw(20) << (*it).getSurname() << setw(20) << fixed << setprecision(2) << (*it).getAllMarks() <<"\n";
            }
        }

    }
    else{

       if (naujausias.is_open())
        {
            naujausias << "firstName"<< setw(20) <<"secondName"<< setw(20) <<"Galutinis(Med.)\n";
            naujausias << "\n";

            for (vector<studentas>::iterator it = protingi.begin(); it != protingi.end(); ++it){

                naujausias << (*it).getName() << setw(20) << (*it).getSurname() << setw(20) << fixed << setprecision(2) << (*it).getAllMarks() <<"\n";
            }
        }
    }
    naujausias.close();
}