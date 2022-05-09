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
		long longestSpan() const;
		long shortestSpan() const;
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	private:
		int *_array;
		unsigned int _sizeMax;
		unsigned int _pos;
};

std::ostream &operator<<(std::ostream &out, Span const &rhs);
int findMin(int array[], int start, int end);
int findMax(int array[], int start, int end);

#endif
