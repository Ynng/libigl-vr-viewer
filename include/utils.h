#ifndef _UTILS_H
#define _UTILS_H

#include <iostream>
#include <iomanip> // setprecision
#include <sstream> // stringstream

using namespace std;

// SDL variables

string ftos(float f, int precision);	// float to string with 2-decimal precision
string vftos(float* v, int precision);	// float vector to string with 2-decimal precisions

#endif