#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal
{
public:
	Animal();
	Animal(const std::string&);
	Animal(const Animal&);
	Animal	&operator=(const Animal&);
	virtual ~Animal();

	virtual	void makeSound() const = 0;

	const	std::string &getType() const;
	void	setType(const std::string &newType);
protected:
	std::string	type;
};

#endif