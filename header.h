#ifndef HEADER_H

#define HEADER_H

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
// paimta is https://github.com/objprog/paskaitos2019/wiki/Laiko-matavimas
//Timer class
class Timer {
private:
    chrono::time_point<chrono::high_resolution_clock> start;
public:
    Timer() : start{chrono::high_resolution_clock::now()} {}
    void reset() {
        start = chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return chrono::duration<double>
                (chrono::high_resolution_clock::now() - start).count();
    }
};
//Base abstract class
class zmogus {
protected:
    // info about person
    string firstName;
    string secondName;
    zmogus (const string inpName, const string inpSName ) : firstName(inpName), secondName(inpSName) {}
public:
    // getters
    virtual string getName() const {return firstName;}
   virtual string getSurname() const {return secondName;}
    // setters
    virtual void setName(istream & stream) {stream >> firstName;}
    virtual void setSurname(istream & stream) {stream >> secondName;}

};
//Derived class
class studentas: public zmogus {
private:
    vector<int> nd;
    double egz;
    double allMarks;
    int haha; // used for creating random numbers
public:
    //Constructors
    studentas() : zmogus("Vardas", "Pavarde"), egz(0.0), allMarks(0.0), haha(0) {}
    ~studentas() {nd.clear();}
    // getters
    double getAllMarks() const {return allMarks;}
    // setters
    void setAllMarks(istream & stream) {stream >> allMarks;}
    // functions
    void randomNumbers(int haha);
    double vid();
    int median();
    double galutinioM();
    double galutinioV();
    // Operators
    bool operator>(const studentas& stud);
    bool operator>=(const studentas& stud);
    bool operator<(const studentas& stud);
    bool operator<=(const studentas& stud);
    studentas& operator=(const studentas& s);
    bool operator==(const studentas& stud);
    bool operator!=(const studentas& stud);
};
#endif