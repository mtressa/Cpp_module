#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public Form
{
private:
	const str	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const str&);
	RobotomyRequestForm(const str& target, const str& name);
	RobotomyRequestForm(const RobotomyRequestForm&);
	~RobotomyRequestForm();
	RobotomyRequestForm	&operator=(const RobotomyRequestForm&);

	virtual void		execute(const Bureaucrat& executor) const;
	const str &getTarget() const;
};

#endif