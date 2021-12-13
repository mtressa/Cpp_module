#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "AMateria.hpp"

class Inventory
{
private:
	AMateria	**materias_;
	static const int maxSize_;
	size_t size_;
public:
	Inventory();
	Inventory(const Inventory&);
	Inventory &operator=(const Inventory&);
	~Inventory();

	void		add(AMateria*);
	void		removeAt(size_t idx);
	AMateria	*getMateriaAt(size_t idx);
	AMateria	**begin() const;
	AMateria	**end() const;
};

#endif