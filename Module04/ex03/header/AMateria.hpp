#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string		type_;
public:
	AMateria(const AMateria&);
	AMateria(std::string const & type);
	virtual ~AMateria();
//	[...]
	std::string const & getType() const; //Returns the materia type_
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif