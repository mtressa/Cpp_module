#include "../header/Cat.hpp"
#include <iostream>

Cat::Cat(): WrongAnimal("Cat")
{
	this->brain = new Brain();
	std::cout<<this->getType()<<" constructed ..mrr\n";
}

Cat::Cat(const Cat &cat)
{
	if (this != &cat)
	{
		this->brain = new Brain(*(cat.brain));
	}
	std::cout<<this->getType()<<" copy constructed ..mrr\n";
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->setType(cat.getType());
		if (!this->brain)
			this->brain = new Brain();
		this->brain->setIdeas(cat.brain->ideas);
	}
	std::cout<<this->getType()<<" ..mrr copy assign constructed\n";
	return (*this);
}

Cat::~Cat()
{
	std::cout<<"mrr..mrr.. "<<this->getType()<< " destroyed\n";
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout<<"..mrr Meow!\n";
}