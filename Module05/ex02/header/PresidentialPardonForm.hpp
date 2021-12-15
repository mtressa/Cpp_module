#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public Form
{
private:
	const str& _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const str&);
	PresidentialPardonForm(const str& target, const str& name);
	PresidentialPardonForm(const PresidentialPardonForm&);
	~PresidentialPardonForm();
	PresidentialPardonForm	&operator=(const PresidentialPardonForm&);

	virtual void execute(const Bureaucrat& executor) const;
	const str &getTarget() const;
};

#endif