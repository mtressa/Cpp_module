#include "../header/Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat")
{
	std::cout<<this->getType()<<" constructed ..mrr\n";
}

Cat::Cat(const Cat &cat): Animal(cat)
{
	std::cout<<this->getType()<<" copy constructed ..mrr\n";
}

Cat &Cat::operator=(const Cat &cat)
{
	this->setType(cat.getType());
	std::cout<<this->getType()<<" ..mrr copy assign constructed\n";
	return (*this);
}

Cat::~Cat()
{
	std::cout<<"mrr..mrr.. "<<this->getType()<< " destroyed\n";
}

void Cat::makeSound() const
{
	std::cout<<"..mrr Meow!\n";
}