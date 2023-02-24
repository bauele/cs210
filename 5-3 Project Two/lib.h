#ifndef LIB_H
#define LIB_H

#include <string>
using namespace std;

string nCharString(size_t n, char c);
string centeredString(size_t, string s, char c);
string rightString(size_t n, string s, char c);

void setValueIfEmpty(string& s, string newValue);
double calculateMonthlyInterest(double initial, double rate, double deposit = 0.00);

#endif