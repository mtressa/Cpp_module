#include "span.hpp"

std::ostream& operator<<(std::ostream& os, const Span& span)
{
	for (uint i = 0; i < span.size(); i++)
		std::cout<<span[i]<<" ";
	return (os);
}

const char *Span::NotEnoughInts::what() const throw()
{
	return ("not enough numbers");
}

Span::Span() : _capacity(0) ,_size(0), arr(0) {}

Span::Span(uint N) : _capacity(N), _size(0), arr(new int[N])
{
	std::fill_n(arr, N, 0);
}

Span::Span(const Span &copy) : _capacity(copy._capacity), _size(copy._size), arr(new int[copy._capacity])
{
	for (size_t i = 0; i < _capacity; ++i) arr[i] = (copy.arr)[i];
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		if (_capacity == copy._capacity)
		{
			std::copy(copy.arr, copy.arr + _capacity, arr);
			_size = copy._size;
		}
		else
		{
			delete [] arr;
			_capacity = copy._capacity;
			_size = copy._size;
			arr = new int[_capacity];
			std::copy(copy.arr, copy.arr + _capacity, arr);
		}
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_size == _capacity) throw std::out_of_range("exceeded number capacity");
	arr[_size] = n;
	++_size;
}

uint Span::longestSpan() const
{
	if (_size < 2) throw Span::NotEnoughInts();
	uint result = -1;
	uint temp;
	for (size_t i = 0; i < _size - 1; ++i)
	{
		temp = (arr[i] < arr[i + 1]) ? (arr[i + 1] - arr[i]) : (arr[i] - arr[i + 1]);
		if (temp < result)
			result = temp;
	}
	return (result);
}

uint Span::shortestSpan() const
{
	if (_size < 2) throw Span::NotEnoughInts();
	uint result = 0;
	uint temp;
	for (size_t i = 0; i < _size; ++i)
	{
		temp = (arr[i] < arr[i + 1]) ? (arr[i + 1] - arr[i]) : (arr[i] - arr[i + 1]);
		if (temp > result)
			result = temp;
	}
	return (result);
}

uint Span::size() const
{
	return (_size);
}

int Span::operator[](uint idx) const
{
	return (*(arr + idx));
}