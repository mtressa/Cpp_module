#ifndef CAT_HPP
#define CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: virtual public WrongAnimal
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