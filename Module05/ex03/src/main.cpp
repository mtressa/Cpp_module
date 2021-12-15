#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"
#include "../header/Intern.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	Form* rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Bureaucrat bc("Levi Ackerman", 130);
	try
	{
		bc.signForm(*rrf);
		bc.executeForm(*rrf);
	}
	catch (std::exception& e)
	{
		std::cout<<"Some error beacause "<<e.what()<<std::endl;
	}

	delete rrf;
}