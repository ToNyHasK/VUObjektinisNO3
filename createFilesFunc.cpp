#include "header.h"

void checkInput(int &input) {

    while (cin.fail() || (input !=1 && input !=0)){
            cout << "Blogas irasymas, bandykite dar karta: \n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> input;
    }

}

void createFiles(vector<studentas> s, vector<double> &vargsiukaiV, vector<double> &protingiejiV, int &pasirinkimas, vector<double> &vargsiukaiM, vector<double> &protingiejiM) {


    int visiStudentai = 1;
    int counter = 0;



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

        for (vector<studentas>::iterator it = s.begin(); it != s.end(); ++it){
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

            for (vector<studentas>::iterator it = s.begin(); it != s.end(); ++it){

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

void createFiles(deque<studentas> s, vector<double> &vargsiukaiV, vector<double> &protingiejiV, int &pasirinkimas, vector<double> &vargsiukaiM, vector<double> &protingiejiM) {


    int visiStudentai = 1;
    int counter = 0;

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

        for (deque<studentas>::iterator it = s.begin(); it != s.end(); ++it){
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

            for (deque<studentas>::iterator it = s.begin(); it != s.end(); ++it){

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

void createFiles(list<studentas> s, vector<double> &vargsiukaiV, vector<double> &protingiejiV, int &pasirinkimas, vector<double> &vargsiukaiM, vector<double> &protingiejiM) {


    int visiStudentai = 1;
    int counter = 0;

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

