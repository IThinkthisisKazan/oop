#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <iomanip>

using namespace std;

void Readvector(istream& input, vector<double>& vect);
double FindMaxElement(vector<double>& vect);
void splitvector(vector<double>& vect, double num);
void PrintSortedVector(vector<double>& vect, ostream& output);


