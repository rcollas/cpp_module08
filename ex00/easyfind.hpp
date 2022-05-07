#ifndef CPP_MODULE08_EASYFIND_HPP
#define CPP_MODULE08_EASYFIND_HPP

template <template <class, class> class T, class U, class V>
int easyfind(T<U, V> &haystack, int needle) {

	for (unsigned int i = 0; i < haystack.size(); i++) {
		if (haystack[i] == needle) {
			return haystack[i];
		}
	}
	return 0;
}

#endif