#include "MutanStack.hpp"
#include <iostream>

int main() {

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(10);
	mstack.push(15);
	std::cout << *mstack.begin() << std::endl;
//	std::cout << &mstack.top() << std::endl;
//	std::cout << mstack.end() << std::endl;
//	MutantStack<int>::iterator it = mstack.begin();
//	MutantStack<int>::iterator ite = mstack.end();
//	while (it != ite) {
//		std::cout << *it << std::endl;
//		it++;
//	}
}