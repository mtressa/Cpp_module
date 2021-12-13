#include "../header/MateriaSource.hpp"

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (AMateria** it = this->inventory.begin(); it != this->inventory.end(); ++it)
	{
		if ((*it)->getType() == type)
			return ((*it)->clone());
	}
	return (0);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (materia)
		this->inventory.add(materia);
}