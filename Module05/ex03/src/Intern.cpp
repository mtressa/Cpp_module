#include "../header/Intern.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"

const MyPair Intern::generators[3] =
{
	MyPair("robotomy request", &Intern::makeRobotomyForm),
	MyPair("shrubbery creation", &Intern::makeShrubberyForm),
	MyPair("presidential pardon", &Intern::makePresidentialForm)
};

MyPair::MyPair(const str &key, memFunc mf): key(key), generator(mf) {}

memFunc MyPair::operator[](const str &key) const
{
	if (this->key == key)
		return (this->generator);
	return (0);
}

const char *Intern::NoFormFound::what() const throw()
{
	return ("there is no such form");
}

Form *Intern::makeShrubberyForm(const str& target, const str& name)
{
	return (new ShrubberyCreationForm(target, name));
}

Form *Intern::makeRobotomyForm(const str &target, const str &name)
{
	return (new RobotomyRequestForm(target, name));
}

Form *Intern::makePresidentialForm(const str &target, const str &name)
{
	return (new PresidentialPardonForm(target, name));
}

memFunc Intern::getFormGenerator(const str &name) const
{
	memFunc	mf = 0;
	for (int i = 0; i < 3; i++)
	{
		mf = (generators[i])[name];
		if (mf)
			return (mf);
	}
	throw Intern::NoFormFound();
}

Form *Intern::makeForm(const str &name, const str &target)
{
	memFunc generator = 0;
	try
	{
		generator = getFormGenerator(name);
		return ((*generator)(target, name));
	}
	catch (Intern::NoFormFound& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}