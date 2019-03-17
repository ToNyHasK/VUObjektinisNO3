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
// paimta iš https://github.com/objprog/paskaitos2019/wiki/Laiko-matavimas
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

#endif
