#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog: virtual public Animal
{
public:
	Dog();
	Dog(const Dog&);
	Dog		&operator=(const Dog&);
	~Dog();

	void	makeSound(void) const;
};

#endif