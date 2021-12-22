#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <iostream>
#include <algorithm>

typedef unsigned int uint;

//template <class T>
//class ClassFunctor
//{
//private:
//	T *_ptr;
//public:
//	ClassFunctor(T* ptr) : _ptr(ptr) {}
//	void operator()()
//};

class Span
{
private:
	unsigned int _capacity;
	unsigned int _size;
	int *arr;
public:
	Span();
	Span(uint N);
	Span(const Span& copy);
	Span &operator=(const Span& copy);

	class NotEnoughInts : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	void 	addNumber(int n);

	template <typename Iter>
	void	addNumber(Iter begin, Iter end)
	{
		for (Iter it = begin; it != end; ++it)
		{
			this->addNumber(*it);
		}
	}

	uint	shortestSpan() const;
	uint	longestSpan() const;
	uint	size() const;
	int		operator[](uint idx) const;
};

std::ostream& operator<<(std::ostream& os, const Span& span);

#endif