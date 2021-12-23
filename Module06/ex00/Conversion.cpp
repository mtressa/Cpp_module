#include "Conversion.hpp"
#include <sstream>

Conversion::Conversion(const str& s) {
	if (char_type(s))
		return;
	if (literals(s))
		return;
	if (float_type(s))
		return;
	if (double_type(s))
		return;
	if (int_type(s))
		return;
}

bool Conversion::char_type(const str& s) {
	if (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
		return print_char(s[0]);
	else
		return (false);
}

bool Conversion::literals(const str& s)
{
	if (s == "nan" || s == "nanf")
	{
		std::cout<<"char: impossible\n"
				   "int: impossible\n"
				   "float: nanf\n"
				   "double: nan"<<std::endl;
	}
	else if (s == "inf" || s == "inff")
	{
		std::cout<<"char: impossible\n"
				   "int: impossible\n"
				   "float: inff\n"
				   "double: inf"<<std::endl;
	}
	else if (s == "-inf" || s == "-inff")
	{
		std::cout<<"char: impossible\n"
				   "int: impossible\n"
				   "float: -inff\n"
				   "double: -inf"<<std::endl;
	}
	else
		return false;
	return true;
}

bool Conversion::int_type(const str& s) {
	if ((s.find(".") != std::string::npos) )
		return false;
	std::istringstream(s) >> int_var;
	return print_int(int_var);
}

bool Conversion::float_type(const str& s) {
	if (s.find("f") == std::string::npos && s.find(".") == std::string::npos)
		return (false);
	std::istringstream(s) >> float_var;
	return print_float(float_var);
}

bool Conversion::double_type(const str& s) {
	if (s.find(".") == std::string::npos)
		return (false);
	std::istringstream(s) >> double_var;
	return print_double(double_var);
}

bool Conversion::print_char(char c) {
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float >(c) << "0.f"<< std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	return true;
}

bool Conversion::print_int(int i) {
	if (std::isprint(i))
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else if ( i >= CHAR_MIN && i <= CHAR_MAX )
		std::cout << "char: No displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float >(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" <<std::endl;
	return true;
}

bool Conversion::print_float(float f) {
	if (std::isprint(static_cast<int>(f)))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else if ( static_cast<int>(f) >= CHAR_MIN && static_cast<int>(f) <= CHAR_MAX )
		std::cout << "char: No displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (static_cast<int>(f) >= INT_MIN && static_cast<int>(f) <= INT_MAX)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (f == 0.0f)
		std::cout << "float: " << static_cast<float >(f) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float >(f) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) <<std::endl;
	return true;
}

bool Conversion::print_double(double d) {
	if ( std::isprint( static_cast<int>(d) ) )
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else if (static_cast<int>(d) >= CHAR_MIN && static_cast<int>(d) <= CHAR_MAX )
		std::cout << "char: No displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if ( static_cast<int>(d)>= INT_MIN && static_cast<int>(d)<= INT_MAX )
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if ( d < FLT_MIN || d > FLT_MAX )
		std::cout << "float: impossible" << std::endl;
	else if ( d - static_cast<int>(d) == 0 )
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	if ( d - static_cast<int>(d) == 0 )
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
	return true;
}

Conversion::Conversion() {
}
Conversion::Conversion(const Conversion &C) {
	*this = C;
}
Conversion &Conversion::operator=(const Conversion &) {
	return *this;
}
Conversion::~Conversion(){
}