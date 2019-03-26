#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "header.h"

void checkInput(int &input);
bool mycomp(const studentas & s1, const studentas & s2);
void sortSbyName(vector<studentas> & s);
void sortSbyName(deque<studentas> & s);
void sortSbyName(list<studentas> & s);
void createFiles(vector<studentas> s, int pasirinkimas);
void createFiles(deque<studentas> s, int pasirinkimas);
void createFiles(list<studentas> s, int pasirinkimas);
void readFile (int index, vector<studentas> &s);
void readFile (int index, deque<studentas> &s);
void readFile (list<studentas> &s);
void vargProt(vector <studentas> &s, vector <studentas> &vargsai, vector <studentas> &protingi);
void vargProt(deque <studentas> &s, deque <studentas> &vargsai, deque <studentas> &protingi);
void vargProt(list <studentas> &s, list <studentas> &vargsai, list <studentas> &protingi);
void sortStud(vector <studentas> s, int pasirinkimas, vector <studentas> vargsai, vector <studentas> protingi);
void sortStud(deque <studentas> s, int pasirinkimas, deque <studentas> vargsai, deque <studentas> protingi);
void sortStud(list <studentas> s, int pasirinkimas, list <studentas> vargsai, list <studentas> protingi);
void vargProt(vector <studentas> &s, vector <studentas> &protingi);
void vargProt(deque <studentas> &s, deque <studentas> &protingi);
void vargProt(list <studentas> &s, list <studentas> &protingi);
void sortStud(vector <studentas> s, int pasirinkimas, vector <studentas> protingi);
void sortStud(deque <studentas> s, int pasirinkimas, deque <studentas> protingi);
void sortStud(list <studentas> s, int pasirinkimas, list <studentas> protingi);

#endif
