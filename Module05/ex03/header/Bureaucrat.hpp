#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
private:
	std::string	_name;
	int			_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string&, int);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat	&operator=(const Bureaucrat&);
	~Bureaucrat();

	static const int minGrade;
	static const int maxGrade;

	const std::string	&getName() const;
	int					getGrade() const;
	void				increment();
	void				decrement();

	void				signForm(Form&);
	void				executeForm(const Form& form);
};

std::ostream &operator<<(std::ostream&, const Bureaucrat&);

#endif