#ifndef DOG_HPP
#define DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: virtual public WrongAnimal
{
public:
	Dog();
	Dog(const Dog&);
	Dog		&operator=(const Dog&);
	~Dog();

	void	makeSound(void) const;

private:
	Brain	*brain;
};

#endif