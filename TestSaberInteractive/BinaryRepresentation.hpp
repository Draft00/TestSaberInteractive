#include "BinaryRepresentation.h"

#include <type_traits>
#include <iostream>
#include <stack>


template<class T>
void BinaryRepresentation<T>::printBinaryRepresentation(T number)
{
	if constexpr (std::is_signed_v<T> && std::is_integral_v<T>) {
		std::cout << number << " is ";
		uint64_t len = sizeof(T) * 8;
		for (uint64_t i = (static_cast<uint64_t>(1) << len - 1); i > 0; i = i >> 1) {
			std::cout << ((number & i) ? 1 : 0);
		}
		std::cout << std::endl; 
		////if (number < 0)
		//const isNegative = number < 0;
		//std::stack<bool> bitStack; 
		//while (number >= 1) {
		//	bitStack.push(number & 1);
		//	number = number >> 1;
		//}
		//while (!bitStack.empty()) {
		//	std::cout << bitStack.top();
		//	bitStack.pop();
		//}
	}
	else {
		std::cout << "Non-signed non-integral value not supported yet." << std::endl; 
	}
}