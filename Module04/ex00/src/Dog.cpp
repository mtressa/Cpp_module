#include "../header/Dog.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog")
{
	std::cout<<this->getType()<<" ..Grrrr constructed\n";
}

Dog::Dog(const Dog &dog): Animal(dog)
{
	std::cout<<this->getType()<<" ..Grrrr copy constructed\n";
}

Dog &Dog::operator=(const Dog &dog)
{
	this->setType(dog.getType());
	std::cout<<this->getType()<<" ..Grrrr copy assign constructed\n";
	return (*this);
}

Dog::~Dog()
{
	std::cout<<this->getType()<<" ..Grrrr destroyed\n";
}

void Dog::makeSound() const
{
	std::cout<<"Grrrr.. Bark!\n";
}