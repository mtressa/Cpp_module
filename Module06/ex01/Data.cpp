#include "Data.hpp"
Data::Data() {
	//std::cout << "Data default constructor was called" << std::endl;
}

int Data::getValue() const {
	return this->value;
}

void Data::setValue(int value) {
	this->value = value;
}

Data::Data(const Data&D){
	*this = D;
}

Data &Data::operator=(const Data &D) {
	if (this != &D)
		this->setValue(D.getValue());
	return *this;
}

Data::~Data() {
	//std::cout << "Data default destructor was called" << std::endl;
}