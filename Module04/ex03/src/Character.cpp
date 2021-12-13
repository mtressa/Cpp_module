#include "../header/Character.hpp"
#include <iostream>

Character::Character(const std::string& newName): name_(newName)
{
	std::cout<<"Character(Name) constructor\n";
}

Character::Character(const Character &character): inventory(character.inventory)
{
	this->name_ = character.getName();
	std::cout<<"Character Copy Constructor\n";
}

Character &Character::operator=(const Character &character)
{
	if (this != &character)
	{
		this->name_ = character.getName();
		this->inventory = character.inventory;
	}
}

const std::string &Character::getName() const
{
	return (this->name_);
}

void Character::equip(AMateria *materia)
{
	if (materia)
		this->inventory.add(materia);
}

void Character::unequip(int idx)
{
	this->inventory.removeAt(idx);
}

void Character::use(int idx, ICharacter &target)
{
	AMateria* materia = this->inventory.getMateriaAt(idx);
	if (materia)
		materia->use(target);
}