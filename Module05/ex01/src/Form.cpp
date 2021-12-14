#include "../header/Form.hpp"

const int Form::minGrade = 150;
const int Form::maxGrade = 1;

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too high");
}

Form::Form(): _name("Default Form"),
			  _bIsSigned(false),
			  _minGradeToSign(Form::minGrade),
			  _minGradeToExecute(Form::minGrade)
{
	std::cout<<"Form Default Constructor\n";
}

Form::Form(const str& name, int minSign, int minExec)
: _name(name), _bIsSigned(false), _minGradeToSign(minSign), _minGradeToExecute(minExec)
{
	if (minSign < maxGrade || minExec < maxGrade) throw GradeTooHighException();
	if (minSign > minGrade || minExec > minGrade) throw GradeTooLowException();
	std::cout<<"Form(Name, MinGradeToSign, MinGradeToExec) Constructor\n";
}

Form::Form(const Form &copy): _name(copy._name),
							  _bIsSigned(copy._bIsSigned),
							  _minGradeToSign(copy._minGradeToSign),
							  _minGradeToExecute(copy._minGradeToExecute)
{
	std::cout<<"Form Copy Constructor\n";
}

Form::~Form()
{
	std::cout<<"Form Destructor\n";
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		this->_bIsSigned = copy._bIsSigned;
	}
	std::cout<<"Form Copy Assignation\n";
	return (*this);
}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_bIsSigned);
}

int Form::getMinGradeToSign() const
{
	return (_minGradeToSign);
}

int Form::getMinGradeToExecute() const
{
	return (_minGradeToExecute);
}

void Form::beSigned(const Bureaucrat &bc)
{
	if (bc.getGrade() <= _minGradeToSign)
		this->_bIsSigned = true;
	throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream& os, const Form& form)
{
	os<<form.getName()<<'\n'
	<<"is signed: "<<form.isSigned()<<'\n'
	<<"Minimum grade to sign: "<<form.getMinGradeToSign()<<'\n'
	<<"Minimum grade to execute: "<<form.getMinGradeToExecute()<<'\n';
	return (os);
}