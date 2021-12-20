#include "iter.hpp"
#include <iostream>

template <typename T>
void doubler(T& n)
{
	n *= 2;
}

int main()
{
	int a[3] = {1, 2, 3};
	iter(a, 3, &doubler);
	for (int i = 0; i < 3; i++) std::cout<<a[i]<<" ";
	std::cout<<std::endl;

	float b[3] = {42.32f, 3.145f, 128.9876512f};
	iter(b, 3, &doubler);
	for (int i = 0; i < 3; ++i) std::cout<<b[i]<<" ";
	std::cout<<std::endl;
}