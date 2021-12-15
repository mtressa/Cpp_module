#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "Form.hpp"

typedef sd::string str;
typedef Form *(*memFunc)(const str& target, const str& name);

class MyPair
{
	const str	key;
	memFunc		generator;
public:
	MyPair(const str& key, memFunc mf);
	memFunc	operator[](const str& key);
};

class Intern
{
private:
	Form	*makeShrubberyForm(const str& target, const str& name);
	Form	*makeRobotomyForm(const str& target, const str& name);
	Form	*makePresidentialForm(const str& target, const str& name);
	memFunc	getFormGenerator(const str& name) const;
public:

	class NoFormFound : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	static const MyPair generators[3];

	Form	*makeForm(const str& name, const str& target);
};

#endif