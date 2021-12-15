#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Form *form1 = 0;
	Form *form2 = 0;
	Form *form3 = 0;
	Form *form4 = 0;
	Form *form5 = 0;
	Form *form6 = 0;
	try
	{
		Bureaucrat bc1("John McClane", 1);
		form1 = new ShrubberyCreationForm(bc1.getName(), "SaveTree");
		bc1.signForm(form1);
		bc1.executeForm(form1);
		delete form1;

		Bureaucrat bc2("Makaley Kalkin", 2);
		form2 = new RobotomyRequestForm(bc2.getName(), "Robotico");
		bc2.signForm(form2);
		bc2.executeForm(form2);
		delete form2;

		Bureaucrat bc3("Robert De'Niro", 3);
		form3 = new PresidentialPardonForm(bc3.getName(), "Excuse");
		bc3.signForm(form3);
		bc3.executeForm(form3);
		delete form3;

		std::cout<<"[Case when executing not signed form]\n";
		Bureaucrat bc4("George Bush", 4);
		form4 = new PresidentialPardonForm(bc4.getName(), "Chapalak");
		bc4.executeForm(form4);
		delete form4;

		std::cout<<"[Case when trying to sign without enough grades]\n";
		Bureaucrat bc5("Lerroy Jankins", 73);
		form5 = new RobotomyRequestForm(bc5.getName(), "Cyborg");
		bc5.signForm(form5);
		bc5.executeForm(form5);
		delete form5;

		std::cout<<"[Case when trying to execute without enough grades]\n";
		Bureaucrat bc6("Peter Jackson", 138);
		form6 = new ShrubberyCreationForm(bc6.getName(), "Shrut");
		bc6.signForm(form6);
		bc6.executeForm(form6);
		delete form6;
	}
	catch (std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
}