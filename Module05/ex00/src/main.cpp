#include "../header/Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat bc("John McClane", 42);
		bc.decrement();
		std::cout<<bc<<std::endl;
		Bureaucrat ebc("Calvine Clein", 150);
		ebc.decrement();
		Bureaucrat bc2("Cortney Love", 0);
		bc2 = bc;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout<<e.what()<<std::endl;
	}
}