
#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <cstdint>

class Data {

private:
	int value;
public:
	Data();
	Data(const Data&);
	Data& operator=(const Data&);

	int getValue() const;
	void setValue(int value);

	~Data();
};

uintptr_t serialize(Data* ptr);
Data *deserialize(uintptr_t ptr);

#endif
