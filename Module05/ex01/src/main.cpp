#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat bc1("John McClane", 1);
		Form form1("Declaration", 120, 55);
		bc1.signForm(form1);
		Bureaucrat bc2("Bobik", 121);
		bc2.signForm(form1);
		Bureaucrat bc3("Errond", 8080);
		std::cout<<"After creating Bureaucrat Errond\n";
	}
	catch (std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
}