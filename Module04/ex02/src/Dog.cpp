#include "../header/Dog.hpp"
#include <iostream>

Dog::Dog(): WrongAnimal("Dog")
{
	this->brain = new Brain();
	std::cout<<this->getType()<<" ..Grrrr constructed\n";
}

Dog::Dog(const Dog &dog)
{
	if (this != &dog)
	{
		this->brain = new Brain(*(dog.brain));
	}
	std::cout<<this->getType()<<" ..Grrrr copy constructed\n";
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		this->setType(dog.getType());
		if (!this->brain)
			this->brain = new Brain();
		this->brain->setIdeas(dog.brain->ideas);
	}
	std::cout<<this->getType()<<" ..Grrrr copy assign constructed\n";
	return (*this);
}

Dog::~Dog()
{
	std::cout<<this->getType()<<" ..Grrrr destroyed\n";
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout<<"Grrrr.. Bark!\n";
}