#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include "Inventory.hpp"

class MateriaSource: public IMateriaSource
{
private:
	Inventory	inventory;
public:
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};

#endif