#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int gen()
{
	return (1 + std::rand()/((RAND_MAX + 1u)/6));
}

int main()
{
	std::srand(0);
	std::vector<int> v1(9);
	std::generate(v1.begin(), v1.end(), gen);
	std::vector<int>::iterator a = easyfind(v1, 5);
	std::cout<<*a<<std::endl;
}