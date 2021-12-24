#include "../header/Animal.hpp"
#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/Brain.hpp"
#include <iostream>


int main()
{
	const WrongAnimal* j = new Dog();
	const WrongAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	WrongAnimal *animals[10];
	for (int i = 0; i < 5; ++i)
	{
		animals[i] = new Dog();
	}
	for (int i = 5; i < 10; ++i)
	{
		animals[i] = new Cat();
	}

	for (int i = 0; i < 10; ++i)
	{
		delete animals[i];
	}
}
