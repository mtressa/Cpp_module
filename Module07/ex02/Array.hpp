#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>

template<typename T>
class Array
{
private:
	T**		_array;
	size_t	_size;
public:
	Array() : _array(0), _size(0) {}
	Array(unsigned int n) : _size(n)
	{
		_array = new T*[n];
		for (size_t i = 0; i < n; ++i) _array[i] = new T();
	}
	Array(const Array& copy)
	{
		if (this != &copy)
		{
			_array = new T*[copy.size()];
			for (size_t i = 0; i < copy.size(); ++i) _array[i] = new T(copy[i]);
			_size = copy.size();
		}
	}
	Array &operator=(const Array& copy)
	{
		if (this != &copy)
		{
			if (_size == copy.size() && _size != 0)
			{
				for (size_t i = 0; i < _size; ++i)
				{
					delete _array[i];
					*(_array[i]) = copy[i];
				}
			}
			else
			{
				for (size_t i = 0; i < copy.size(); ++i) delete _array[i];
				delete [] _array;
				_array = new T*[copy.size()];
				for (size_t i = 0; i < copy.size(); ++i) _array[i] = new T(copy[i]);
			}
		}
		return (*this);
	}

	T	&operator[](size_t idx)
	{
		if (idx >= _size) throw std::exception();
		return (*(_array[idx]));
	}

	const T	&operator[](size_t idx) const
	{
		if (idx >= _size) throw std::exception();
		return (*(_array[idx]));
	}

	size_t	size() const
	{
		return (_size);
	}
};

#endif