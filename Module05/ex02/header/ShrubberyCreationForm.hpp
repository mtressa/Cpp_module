#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	const str	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const str&);
	ShrubberyCreationForm(const str& target, const str& name);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	~ShrubberyCreationForm();
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm& copy);

	virtual void execute(Bureaucrat const &executor) const;
	const str	&getTarget() const;
};

#endif
