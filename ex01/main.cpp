#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main() {

	{
		std::cout << "\x1B[34m Basic tests \033[0m" << std::endl;
		Span foo(20);
		std::cout << foo << std::endl;
		foo.addNumber(-10);
		foo.addNumber(-2);
		foo.addNumber(140);
		int array[] = {10, -2, 0, 1234, -20, 10};
		int find = findMin(array, 0, 5);

		std::cout << "min = " << find << std::endl;

		std::cout << "longestSpan = " << foo.longestSpan() << std::endl;
		std::cout << "shortestSpan = " << foo.shortestSpan() << std::endl;
	}
	{
		std::cout << "\x1B[34m Span with huge size \033[0m" << std::endl;
		int size = 10000;
		Span foo (size);

		srand(time(0));
		for (int i = 0; i < size; i++) {
			foo.addNumber(rand());
		}
		std::cout << "longestSpan = " << foo.longestSpan() << std::endl;
		std::cout << "shortestSpan = " << foo.shortestSpan() << std::endl;
	}
	{
		std::cout << "\x1B[34m ADD RANGE \033[0m" << std::endl;
		std::vector<int> range;
		range.push_back(1);
		range.push_back(2);
		range.push_back(3);
		range.push_back(4);
		range.push_back(5);
		Span foo(10);

		std::vector<int>::iterator begin = range.begin();
		std::vector<int>::iterator end = range.end();
		foo.addRange(begin, end);
		std::cout << foo << std::endl;
	}

}