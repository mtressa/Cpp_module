#include "Conversion.hpp"

int main(int argc, char **argv){

	if (argc != 2)
		return 1;
	std::string str = argv[1];
	Conversion c(str);
	return 0;
}