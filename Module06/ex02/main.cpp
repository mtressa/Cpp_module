#include "Base.hpp"
Base* generate(){
	std::srand(time(0));
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else if (i == 2)
		return new C;
	return new A;
}

void identify(Base *p){

	if (dynamic_cast<A *>(p) != nullptr)
		std::cout << "Class A *" << std::endl;
	else if (dynamic_cast<B *>(p) != nullptr)
		std::cout << "Class B *" << std::endl;
	else if (dynamic_cast<C *>(p) != nullptr)
		std::cout << "Class C *" << std::endl;
	else
		std::cout << "Type does not exist" << std::endl;
}

void identify(Base& p){
	int err_count = 0;
	try
	{
		dynamic_cast<A*>(&p);
		std::cout << "Class A &" << std::endl;
		return;
	}
	catch (std::bad_cast&) ++err_count;
	try
	{
		dynamic_cast<B*>(&p);
		std::cout << "Class B &" << std::endl;
		return;
	}
	catch (std::bad_cast&) ++err_count;
	try
	{
		dynamic_cast<C*>(&p);
		std::cout << "Class C &" << std::endl;
		return;
	catch (std::bad_cast&) ++err_count;
	if (err_count == 3)
		std::cout << "Type does not exist" << std::endl;
}

int main(){

	Base *p = generate();

	identify(p);
	identify(*p);

	delete p;
	return 0;
}
