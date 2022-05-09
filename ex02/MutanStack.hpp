#ifndef CPP_MODULE08_MUTANSTACK_HPP
#define CPP_MODULE08_MUTANSTACK_HPP

#include <stack>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <deque>


template <typename T>
class MutantStack : public std::stack<T> {

	public:
		typedef typename std::deque<T>::iterator iterator;
		MutantStack() : std::stack<T>() {};
		MutantStack(MutantStack const &src) {
			*this = src;
		}
		virtual ~MutantStack() {};

		MutantStack &operator=(MutantStack const &rhs)  {
			std::stack<T>::operator=(rhs);
			return *this;
		}

		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
};

#endif
