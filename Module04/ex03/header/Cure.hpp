#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure: virtual public AMateria
{
public:
	Cure();
	Cure(const Cure&);
	Cure(const std::string&);
	Cure	&operator=(const Cure&);
	~Cure();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif