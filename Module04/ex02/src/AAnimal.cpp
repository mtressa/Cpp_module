#include "../header/AAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout<<"WrongAnimal of type "<<this->getType()<<" constructed\n";
}

WrongAnimal::WrongAnimal(const std::string &newType): type(newType)
{
	std::cout<<"WrongAnimal of type "<<this->getType()<<" constructed with Type\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal): type(animal.type)
{
	std::cout<<"WrongAnimal of type "<<this->getType()<<" copy constructed\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	this->setType(animal.type);
	std::cout<<"WrongAnimal of type "<<this->getType()<<" copy assign constructed\n";
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal of type "<<this->getType()<<" destructed\n";
}

const std::string &WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::setType(const std::string &newType)
{
	this->type = newType;
}

void WrongAnimal::makeSound() const
{
	std::cout<<"Hakuna Matata!\n";
}