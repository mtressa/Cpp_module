#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice: virtual public AMateria
{
public:
	Ice();
	Ice(const std::string&);
	Ice(const Ice&);
	Ice		&operator=(const Ice&);
	~Ice();

	virtual AMateria *clone() const;
	virtual void use(ICharacter& target);
};

#endif