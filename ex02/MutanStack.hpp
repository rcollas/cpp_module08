#ifndef CPP_MODULE08_MUTANSTACK_HPP
#define CPP_MODULE08_MUTANSTACK_HPP

#include <stack>
#include <iostream>
#include <iterator>


template <typename T>
class MutantStack : public std::stack<T> {

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef std::stack<T>::container_type c;
		iterator begin() {
			return std::begin(c);
		}
		iterator end() {
			return std::begin(c);
		}
//		T *begin() {
//			return &this->top() - this->size();
//		};
//		T *end() {
//			return &this->top();
//		}
//	class iterator : public std::iterator<
//						std::input_iterator_tag,
//						int,
//						long,
//						const T*> {
//
//		};

};

#endif
