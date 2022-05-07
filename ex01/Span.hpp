#ifndef CPP_MODULE08_SPAN_HPP
#define CPP_MODULE08_SPAN_HPP

#include <vector>
#include <iostream>

class Span {

	public:
		Span();
		Span(unsigned int N);
		Span(Span const &src);
		~Span();

		Span &operator=(Span const &rhs);

		void addNumber(int nb);
		int getNumber(int n) const;
		unsigned int getSizeMax() const;

	private:
		int *_array;
		unsigned int _sizeMax;
		unsigned int _pos;
};

std::ostream &operator<<(std::ostream &out, Span const &rhs);

#endif
