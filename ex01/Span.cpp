#include "Span.hpp"
#include <cmath>

Span::Span() : _array(0), _sizeMax(0), _pos(0) {}

Span::Span(unsigned int N) : _sizeMax(N), _pos(0) {

	this->_array = new int[N];
	for (unsigned int i = 0; i < this->_sizeMax; i++) {
		this->_array[i] = 0;
	}
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

Span::~Span() {

	if (this->_array) {
		delete [] this->_array;
	}
}

void Span::addNumber(int nb) {

	if (_pos == _sizeMax) {
		std::cerr << "Array's max size reached" << std::endl;
	} else {
		this->_array[this->_pos] = nb;
		this->_pos++;
	}
}

long Span::longestSpan() const {

	int ans = findMax(this->_array, 0, this->_pos - 1);
	ans -= findMin(this->_array, 0, this->_pos - 1);

	return ans;
}

long Span::shortestSpan() const {

	int closestValues = std::abs(this->_array[0] - this->_array[1]);

	if (this->_pos - 1 == 0) {
		return 0;
	} else if (this->_pos - 1 == 1) {
		return std::abs(this->_array[0] - this->_array[1]);
	} else {
		for (unsigned int i = 0; i < this->_pos - 1; i++) {
			for (unsigned int j = 0; j < this->_pos - 1; j++) {
				if (j != i && std::abs(this->_array[i] - this->_array[j]) < closestValues) {
					closestValues = std::abs(this->_array[i] - this->_array[j]);
				}
			}
		}
	}
	return closestValues;
}

int findMin(int array[], int start, int end) {

	int min;
	if (start == end) {
		min = array[end];
	} else if (start + 1 == end) {
		if (array[start] < array[end]) {
			min = array[start];
		} else {
			min = array[end];
		}
	} else {
		int mid = start + (end - start) / 2;
		int left = findMin(array, start, mid);
		int right = findMin(array, mid + 1, end);

		if (left < right) {
			min = left;
		} else {
			min = right;
		}
	}
	int ans = min;
	return ans;
}

int findMax(int array[], int start, int end) {

	int max;
	if (start == end) {
		max = array[start];
	} else if (start + 1 == end) {
		if (array[start] < array[end]) {
			max = array[end];
		} else {
			max = array[start];
		}
	} else {
		int mid = start + (end - start) / 2;
		int left = findMin(array, start, mid);
		int right = findMin(array, mid + 1, end);

		if (left < right) {
			max = right;
		} else {
			max = left;
		}
	}
	int ans = max;
	return ans;
}

void Span::addRange(std::vector<int>::iterator begin,
					std::vector<int>::iterator end) {

	while (begin != end && this->_pos < this->_sizeMax) {
		this->_array[this->_pos] = *begin;
		begin++;
		_pos++;
	}
}
