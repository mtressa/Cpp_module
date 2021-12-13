#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "Inventory.hpp"

class Character: public ICharacter
{
private:
	Inventory	inventory;
	std::string	name_;
public:
	Character(const std::string&);
	Character(const Character&);
	Character	&operator=(const Character&);

	virtual std::string const & getName() const;
	virtual void equip(AMateria*);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif