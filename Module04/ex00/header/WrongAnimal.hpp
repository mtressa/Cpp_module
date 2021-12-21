#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const std::string&);
	WrongAnimal(const WrongAnimal&);
	WrongAnimal	&operator=(const WrongAnimal&);
	virtual ~WrongAnimal();

	void makeSound() const;

	const	std::string &getType() const;
	void	setType(const std::string &newType);
protected:
	std::string	type;
};

#endif