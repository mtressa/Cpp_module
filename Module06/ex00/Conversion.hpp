#ifndef CONVERSION_HPP
#define CONVERSION_HPP

# include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cfloat>
#include <climits>

typedef std::string str;

class Conversion {
public:
	int  int_var;
	char char_var;
	float float_var;
	double double_var;

	Conversion();
	Conversion(const str&);
	Conversion(const Conversion&);
	Conversion& operator=(const Conversion&);

	bool char_type(const str&);
	bool int_type(const str&);
	bool float_type(const str&);
	bool double_type(const str&);
	bool literals(const str&);
	bool print_char(char);
	bool print_int(int);
	bool print_float(float);
	bool print_double(double);

	~Conversion();

};

#endif
