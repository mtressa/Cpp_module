#include "../header/Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout<<"Brain constructed\n";
}

Brain::Brain(const Brain &brain)
{
	if (this != &brain)
	{
		*this = brain;
	}
	std::cout<<"Brain copy constructed\n";
}

Brain::Brain(const std::string *ideas)
{
	this->setIdeas(ideas);

	std::cout<<"Brain constructed from string array\n";
}

Brain &Brain::operator=(const Brain &brain)
{
	if (this != &brain)
	{
		this->setIdeas(brain.ideas);
	}
	std::cout<<"Brain copy assign constructed\n";
	return (*this);
}

Brain::~Brain()
{
	std::cout<<"Brain destructed\n";
}

void Brain::setIdeas(const std::string *ideas)
{
	for (int i = 0; i < 100; ++i) (this->ideas)[i] = ideas[i];
}