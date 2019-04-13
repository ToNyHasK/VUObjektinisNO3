#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "header.h"

void checkInput(int &input);
bool mycomp(const studentas & s1, const studentas & s2);
void sortSbyName(vector<studentas> & s);
void createFiles(vector<studentas> s, int pasirinkimas);
void readFile (int index, vector<studentas> &s);
void vargProt(vector <studentas> &s, vector <studentas> &protingi);
void sortStud(vector <studentas> s, int pasirinkimas, vector <studentas> protingi);

#endif