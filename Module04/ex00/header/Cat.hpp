#include "Animal.hpp"

class Cat: virtual public Animal
{
public:
	Cat();
	Cat(const Cat&);
	Cat	&operator=(const Cat&);
	~Cat();

	void	makeSound() const;
};