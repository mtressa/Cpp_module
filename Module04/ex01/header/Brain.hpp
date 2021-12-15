#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain&);
	Brain	&operator=(const Brain&);
	~Brain();
	std::string ideas[100];

	void	setIdeas(const std::string[100]);
protected:
	Brain(const std::string[100]);
};

#endif