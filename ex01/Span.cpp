#include "Span.hpp"

Span::Span() : _array(0), _sizeMax(0) {}

Span::Span(unsigned int N) : _sizeMax(N) {

	this->_array = new int[N];
}

Span::Span(Span const &src) {

	*this = src;
}

Span &Span::operator=(const Span &rhs) {

	this->_array = rhs._array;
	this->_sizeMax = rhs._sizeMax;
	return *this;
}

int Span::getNumber(int n) const {

	return this->_array[n];
}

unsigned int Span::getSizeMax() const {

	return this->_sizeMax;
}

std::ostream &operator<<(std::ostream &out, Span const &rhs) {

	for (unsigned int i = 0; i < rhs.getSizeMax(); i++) {
		out << rhs.getNumber(i) << " ";
	}
	out << std::endl;
	return out;
}

Span::~Span() {}

void Span::addNumber(int nb) {

	if (_pos == _sizeMax) {
		std::cerr << "Array's max size reached" << std::endl;
	} else {
		this->_array[this->_pos] = nb;
		this->_pos++;
	}
}
