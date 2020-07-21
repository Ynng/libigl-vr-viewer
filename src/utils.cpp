#include "utils.h"

using namespace std;


//-----------------------------------------------------------------------------
// Purpose: helper to convert an 3-float array into a vector string
//-----------------------------------------------------------------------------
string vftos(float v[3], int precision)
{
	stringstream stream;
	stream << "(" << ftos(v[0],precision) << "," << ftos(v[1],precision) << "," << ftos(v[2],precision) << ")";
	string f_str = stream.str();

	return f_str;
}

//-----------------------------------------------------------------------------
// Purpose: helper to convert an float into a string
//-----------------------------------------------------------------------------
string ftos(float f, int precision)
{
	stringstream stream;
	stream << fixed << setprecision(precision) << f;
	string f_str = stream.str();

	return f_str;
}