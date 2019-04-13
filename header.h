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

class studentas {
private:
    vector<int> nd;
    double egz;
    double allMarks;
    string firstName;
    string secondName;
    int haha;
public:

    studentas() : egz(0.0), allMarks(0.0), haha(0) {nd.clear();}
    // getters
    string getName() const {return firstName;}
    string getSurname() const {return secondName;}
    double getAllMarks() const {return allMarks;}
    // setters
    void setName(istream & stream) {stream >> firstName;}
    void setSurname(istream & stream) {stream >> secondName;}
    void setAllMarks(istream & stream) {stream >> allMarks;}
    // functions
    void randomNumbers(int haha);
    double vid();
    int median();
    double galutinioM();
    double galutinioV();

};
#endif