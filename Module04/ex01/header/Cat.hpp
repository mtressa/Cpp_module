#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: virtual public Animal
{
public:
	Cat();
	Cat(const Cat&);
	Cat	&operator=(const Cat&);
	~Cat();

	void	makeSound() const;

private:
	Brain	*brain;
};

#endif