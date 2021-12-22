#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typedef typename T::iterator Iter;
	Iter it = std::find(container.begin(), container.end(), n);
	return (it);
}

#endif