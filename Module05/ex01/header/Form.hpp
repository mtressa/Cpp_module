#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;
typedef std::string str;

class Form
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
private:
	const str	_name;
	bool		_bIsSigned;
	const int	_minGradeToSign;
	const int	_minGradeToExecute;
public:
	Form();
	Form(const str& name, int minSign, int minExec);
	Form(const Form&);
	Form &operator=(const Form&);
	~Form();

	static const int minGrade;
	static const int maxGrade;

	str const	&getName() const;
	bool		isSigned() const;
	int			getMinGradeToSign() const;
	int			getMinGradeToExecute() const;

	void		beSigned(const Bureaucrat&);
};

std::ostream &operator<<(std::ostream& os, const Form&);

#endif