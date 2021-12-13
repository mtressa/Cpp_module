#include "../header/Inventory.hpp"

const int Inventory::maxSize_ = 4;

Inventory::Inventory(): size_(0)
{
	this->materias_ = new AMateria*[Inventory::maxSize_];
	for (size_t i = 0; i < Inventory::maxSize_; ++i)
	{
		(this->materias_)[i] = 0;
	}
}

Inventory::Inventory(const Inventory &inventory)
{
	this->materias_ = new AMateria*[Inventory::maxSize_];
	(*this) = inventory;
}

Inventory &Inventory::operator=(const Inventory &inventory)
{
	if (this != &inventory)
	{
		for (size_t i = 0; i < Inventory::maxSize_; ++i)
		{
			delete (this->materias_)[i];
			(this->materias_)[i] = (inventory.materias_)[i];
		}
		this->size_ = inventory.size_;
	}
	return (*this);
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->size_; ++i)
	{
		delete (this->materias_)[i];
	}
	delete [] this->materias_;
}

void Inventory::add(AMateria *newMateria)
{
	if (this->size_ < Inventory::maxSize_ && newMateria)
	{
		(this->materias_)[this->size_] = newMateria;
		++(this->size_);
	}
}

void Inventory::removeAt(size_t idx)
{
	if (idx >= 0 && idx < this->size_ && this->size_ > 0)
	{
		for (size_t i = idx; i < this->size_ - 1; ++i)
		{
			(this->materias_)[i] = (this->materias_)[i + 1];
		}
		(this->materias_)[this->size_ - 1] = 0;
	}
}

AMateria *Inventory::getMateriaAt(size_t idx)
{
	return ((this->materias_)[idx]);
}

AMateria **Inventory::begin() const
{
	return (this->materias_);
}

AMateria **Inventory::end() const
{
	return (this->materias_ + Inventory::maxSize_);
}