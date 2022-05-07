#include "Span.hpp"

int main() {

	Span foo(20);
	foo.addNumber(5);
	foo.addNumber(5);
	foo.addNumber(5);
	foo.addNumber(5);
	foo.addNumber(5);
	std::cout << foo << std::endl;
}