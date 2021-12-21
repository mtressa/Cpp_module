#include "../header/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("Cat")
{
	std::cout<<this->getType()<<" constructed ..mrr\n";
}

WrongCat::WrongCat(const WrongCat &cat): WrongAnimal(cat)
{
	std::cout<<this->getType()<<" copy constructed ..mrr\n";
}

WrongCat &WrongCat::operator=(const WrongCat &cat)
{
	this->setType(cat.getType());
	std::cout<<this->getType()<<" ..mrr copy assign constructed\n";
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout<<"mrr..mrr.. "<<this->getType()<< " destroyed\n";
}

void WrongCat::makeSound() const
{
	std::cout<<"..mrr Meow!\n";
}