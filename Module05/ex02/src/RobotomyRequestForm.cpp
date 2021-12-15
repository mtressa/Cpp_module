#include "../header/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: Form("Default Robotomy Request", 72, 45), _target("Default Robotomy Target")
{
	std::cout<<"Default RobotomyRequestForm Constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const str &target)
: Form("Default Robotomy Request", 72, 45), _target(target)
{
	std::cout<<"RobotomyRequestFrom(target) Constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const str &target, const str &name)
: Form(name, 72, 45), _target(target)
{
	std::cout<<"RobotomyRequestForm(params) Constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
: Form(copy), _target(copy._target)
{
	std::cout<<"RobotomyRequestForm Copy Constructor\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		Form::operator=(copy);
	}
	std::cout<<"RobotomyRequestForm Copy Assignation\n";
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"RobotomyRequestForm Destructor\n";
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (isSigned())
	{
		checkGradeForExec(executor.getGrade());
		std::srand(std::time(0));
		int chance = 1 + std::rand() / ((RAND_MAX + 1u) / 100);
		if (chance > 50)
		{
			std::cout<<_target<<" has been robotomized successfully\n";
		}
		else
			std::cout<<_target<<"'s robotomization has benn failed\n";
	}
}

const str &RobotomyRequestForm::getTarget() const
{
	return (_target);
}