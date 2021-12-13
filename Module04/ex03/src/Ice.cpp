#include "../header/Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice")
{
	std::cout<<"Ice Default Constructor\n";
}

Ice::Ice(const std::string &type): AMateria(type)
{
	std::cout<<"Ice(string) Constructor\n";
}

Ice::Ice(const Ice &ice): AMateria(ice)
{
	std::cout<<"Ice Copy Constructor\n";
}

Ice::~Ice()
{
	std::cout<<"Ice Destructor\n";
}

Ice &Ice::operator=(const Ice &ice)
{
	(void) ice;
	std::cout<<"Ice operator=\n";
	return (*this);
}

AMateria *Ice::clone() const
{
	Ice *newIce = new Ice(this->getType());
	return (newIce);
}

void Ice::use(ICharacter &target)
{
	std::cout<<"shoots an ice bolt at "<<target.getName()<<'\n';
}