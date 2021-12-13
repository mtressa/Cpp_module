#include "../header/AMateria.hpp"
#include <iostream>

AMateria::AMateria(const std::string &type): type_(type)
{
	std::cout<<"AMateria Default Constructor\n";
}

AMateria::AMateria(const AMateria &materia)
{
	if (this != &materia)
	{
		this->type_ = materia.getType();
	}
	std::cout<<"AMateria Copy Constructor\n";
}

const std::string &AMateria::getType() const
{
	return (this->type_);
}

AMateria::~AMateria()
{
	std::cout<<"AMateria Default Destructor\n";
}

void AMateria::use(ICharacter &target)
{
	std::cout<<"Materia "<<target.getName()<<" use\n";
}

