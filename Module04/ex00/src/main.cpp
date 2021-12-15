#include "../header/Animal.hpp"
#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout<<"\n[Testing Wrong Animals]\n\n";

	const WrongAnimal *Wrongo = new WrongCat();
	std::cout<<Wrongo->getType()<<" "<<std::endl;
	std::cout<<std::endl;
	Wrongo->makeSound();
	std::cout<<std::endl;

	delete Wrongo;
}