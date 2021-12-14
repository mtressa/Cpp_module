#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>

class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
public:
	class	GradeTooHighException : std::exception
	{
	public:
		virtual const char *what() const;
	};
	class	GradeTooLowException : std::exception
	{
	public:
		virtual const char *what() const;
	};

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
};

std::ostream &operator<<(std::ostream&, const Bureaucrat&);

#endif