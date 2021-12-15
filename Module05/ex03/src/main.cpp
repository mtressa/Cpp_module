#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"
#include "../header/Intern.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	Form* rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}