#include "Data.hpp"

int main()
{
	Data *d = new Data();

	d->setValue(100);
	uintptr_t unknown = serialize(d);
	Data *we_know = deserialize(unknown);
	std::cout << we_know->getValue() << std::endl;

	delete we_know;
	return 0;
}

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}