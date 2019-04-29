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
class zmogus {
protected:
    // info about person
    string firstName;
    string secondName;
public:
   // zmogus (const zmogus& z) :  firstName(z.firstName), secondName(z.secondName) {}
    // getters
    virtual string getName() const {return firstName;}
   virtual string getSurname() const {return secondName;}
    // setters
    virtual void setName(istream & stream) {stream >> firstName;}
    virtual void setSurname(istream & stream) {stream >> secondName;}

};

class studentas: public zmogus {
private:
    vector<int> nd;
    double egz;
    double allMarks;
    int haha; // used for creating random numbers
public:
    studentas() : egz(0.0), allMarks(0.0), haha(0) {nd.clear();}
    //studentas(const studentas &s) : nd(s.nd), egz(s.egz), allMarks(s.allMarks) {}

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
    // Overloading Operators
    bool operator>(const studentas& stud);
    bool operator>=(const studentas& stud);
    bool operator<(const studentas& stud);
    bool operator<=(const studentas& stud);
    studentas& operator=(const studentas& stud);
    bool operator==(const studentas& stud);
    bool operator!=(const studentas& stud);
};
#endif