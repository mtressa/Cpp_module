#include "../header/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("Default Shrubbery Creation", 145, 137), _target("Default Shrubbery Target")
{
	std::cout<<"ShrubberyCreationForm Default Constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const str &target)
: Form("Default Shrubbery Creation", 145, 137), _target(target)
{
	std::cout<<"ShrubberyCreationForm(target) Constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const str &target, const str &name)
: Form(name, 145, 137), _target(target)
{
	std::cout<<"SrubberyCreationForm(params) Constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
: Form(copy), _target(copy._target)
{
	std::cout<<"ShrubberyCreationForm Copy Constructor\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"Shrubbery Destructor\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		Form::operator=(copy);
	}
	std::cout<<"ShrubberyCreationForm Copy Assignment\n";
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	checkGradeForExec(executor.getGrade());
	const str filename(_target + "_shrubbery");
	std::ofstream fs(filename.c_str(), std::ios::app);

	if (fs.is_open())
	{
		str tree = "     ccee88oo\n"
				   "  C8O8O8Q8PoOb o8oo\n"
				   " dOB69QO8PdUOpugoO9bD\n"
				   "CgggbU8OU qOp qOdoUOdcb\n"
				   "    6OuU  /p u gcoUodpP\n"
				   "      \\\\\\//  /douUP\n"
				   "        \\\\\\////\n"
				   "         |||/\\\n"
				   "         |||\\/\n"
				   "         |||||\n"
				   "   .....//||||\\....\n\n";
		fs << tree;
	}
	fs.close();
}

const str &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}