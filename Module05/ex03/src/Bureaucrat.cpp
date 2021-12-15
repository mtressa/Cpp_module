#include "../header/Bureaucrat.hpp"

const int Bureaucrat::maxGrade = 1;
const int Bureaucrat::minGrade = 150;

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

Bureaucrat::Bureaucrat(): _name("John Doe"), _grade(minGrade)
{
	std::cout<<"Bureaucrat Default Constructor\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	if (grade < maxGrade) throw GradeTooHighException();
	if (grade > minGrade) throw GradeTooLowException();
	std::cout<<"Bureaucrat("<<name<<", "<<grade<<") Constructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade)
{
	std::cout<<"Bureaucrat Copy Constructor\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<this->getName()<<" Bureaucrat Destructor\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		_name = copy.getName();
		_grade = copy.getGrade();
	}
	std::cout<<"Bureaucrat Copy Assignment\n";
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::increment()
{
	--_grade;
	if (_grade < maxGrade) throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
	++_grade;
	if (_grade > minGrade) throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout<<_name<<" signs "<<form.getName()<<std::endl;
	}
	catch (std::exception& e)
	{
		std::cout<<_name<<", cannot sign "<<form.getName()<<" because "<<e.what()<<std::endl;
	}
}

void Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
		std::cout<<(*this)<<" executes "<<form<<std::endl;
	}
	catch (std::exception& e)
	{
		std::cout<<(*this)<<" cant execute "<<form.getName()<<" because "<<e.what()<<std::endl;
	}
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bc)
{
	os<<bc.getName()<<", bureaucrat grade "<<bc.getGrade();
	return (os);
}