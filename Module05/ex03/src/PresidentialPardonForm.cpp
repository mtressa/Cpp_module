#include "../header/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:Form("Default Presidential Pardon", 25, 5), _target("Default Presidential Target")
{
	std::cout<<"PresidentialPardonForm Default Constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const str &target)
: Form("Default Presidential Pardon", 25, 5), _target(target)
{
	std::cout<<"PresidentialPardonForm(target) Constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const str &target, const str &name)
: Form(name, 25, 5), _target(target)
{
	std::cout<<"PresidentialPardonForm(params) Constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: Form(copy), _target(copy._target)
{
	std::cout<<"PresidentialPardonForm Copy Constructor\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		Form::operator=(copy);
	}
	std::cout<<"PresidentialPardonForm Copy Assignation\n";
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardonForm Destructor\n";
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkGradeForExec(executor.getGrade());
	std::cout<<_target<<" has been pardoned by Zafod Beeblebrox\n";
}

const str &PresidentialPardonForm::getTarget() const
{
	return (_target);
}