#include "span.hpp"
#include <iostream>
#include <vector>

class SequenceNums
{
private:
	int	_init;
public:
	SequenceNums(int n) : _init(n) {}
	int	operator()()
	{
		return (_init++);
	}
};

int main()
{
	Span sp = Span(5);
	sp.addNumber(1);
	sp.addNumber(5);
	sp.addNumber(124);
	sp.addNumber(3);
	sp.addNumber(18);
	std::cout<<sp.shortestSpan()<<std::endl;
	std::cout<<sp.longestSpan()<<std::endl;

	Span sp2 = Span(0);
	try
	{
		sp2.addNumber(14);
		std::cout<<sp2.longestSpan()<<std::endl;
		std::cout<<sp2.shortestSpan()<<std::endl;
	}
	catch (std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	Span sp3 = Span(1);
	try
	{
		sp3.addNumber(125);
		std::cout<<sp3.shortestSpan()<<std::endl;
		std::cout<<sp3.longestSpan()<<std::endl;
	}
	catch (std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}

	std::vector<int> v(10000);
	std::generate(v.begin(), v.end(), SequenceNums(1));
	Span sp4 = Span(10000);
	try
	{
		sp4.addNumber(v.begin(), v.end());
		std::cout<<sp4<<std::endl;
	}
	catch (std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
}