#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "easyfind.hpp"

int main() {

	std::vector<int> foo(10);

	srand(time(0));
	for (int i = 0; i < 10; i++) {
		foo[i] = rand();
		std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
	}

	std::cout << easyfind<std::vector>(foo, foo[2]) << std::endl;

	return 0;
}