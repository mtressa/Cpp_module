#include "../header/Animal.hpp"
#include <iostream>

Animal::Animal(): type("Animal")
{
	std::cout<<"Animal of type "<<this->getType()<<" constructed\n";
}

Animal::Animal(const std::string &newType): type(newType)
{
	std::cout<<"Animal of type "<<this->getType()<<" constructed with Type\n";
}

Animal::Animal(const Animal &animal): type(animal.type)
{
	std::cout<<"Animal of type "<<this->getType()<<" copy constructed\n";
}

Animal &Animal::operator=(const Animal &animal)
{
	this->setType(animal.type);
	std::cout<<"Animal of type "<<this->getType()<<" copy assign constructed\n";
	return (*this);
}

Animal::~Animal()
{
	std::cout<<"Animal of type "<<this->getType()<<" destructed\n";
}

const std::string &Animal::getType() const
{
	return (this->type);
}

void Animal::setType(const std::string &newType)
{
	this->type = newType;
}

void Animal::makeSound() const
{
	std::cout<<"Hakuna Matata!\n";
}