#include "../header/Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure")
{
	std::cout<<"Cure Default Constructor\n";
}

Cure::Cure(const std::string &type): AMateria(type)
{
	std::cout<<"Cure(string) Constructor\n";
}

Cure::Cure(const Cure &cure): AMateria(cure)
{
	std::cout<<"Cure Copy Constructor\n";
}

Cure::~Cure()
{
	std::cout<<"Cure Destructor\n";
}

Cure &Cure::operator=(const Cure &cure)
{
	(void) cure;
	std::cout<<"Cure operator=\n";
	return (*this);
}

AMateria *Cure::clone() const
{
	Cure *newCure = new Cure(this->getType());
	return (newCure);
}

void Cure::use(ICharacter &target)
{
	std::cout<<"heals "<<target.getName()<<"'s wounds\n";
}
