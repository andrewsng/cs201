/*
	lambdas_main.cpp
	Andrew Ng
	Nov 4 2019
	main function for lab 26
	cs201
*/


/**
 * @file     lambdas.hpp
 * @author   Student Name
 * @date     Mar 21, 2019
 * John Quan
 *
 * Practice using lambda functions
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>

#include "lambdas.hpp"

using SizeStringPair = std::pair<size_t, std::string>;

int main() {

	// TODO: REQUIRED
	//       Create a vector<pair<size_t, string>> to enumerate
	//       each string in the WIKIPEDIA_CPP string vector.

	std::vector<SizeStringPair> text;
	for (const auto& s : WIKIPEDIA_CPP) {

		text.push_back(std::make_pair(s.size(), s));
	}


	// TODO: REQUIRED
	//       Use std::sort with a comparison lambda function that sorts
	//       the vector pairs with the first member in descending order.

	std::sort(text.begin(), text.end(),
		[](SizeStringPair a, SizeStringPair b) {
			return a.first > b.first;
		});


	// TODO: REQUIRED
	//       Use printVectorPairs() to print the vector

	std::cout << printVectorPairs(text.begin(), text.end()) << std::endl;


	// TODO: ADDITIONAL 1
	//       Use std::sort with a comparison lambda function that sorts
	//       the vector pairs with the second member in ascending order.

	std::sort(text.begin(), text.end(),
		[](SizeStringPair a, SizeStringPair b) {
			return a.second.compare(b.second) < 0;
		});


	// TODO: ADDITIONAL 1
	//       Use printVectorPairs() to print the vector

	std::cout << printVectorPairs(text.begin(), text.end()) << std::endl;


	// TODO: ADDITIONAL 2
	//       Use std::find_if with a comparison lambda function that prints
	//       the vector pairs where the pair's second.length() > 15.
	//       Print the vector as described in the lab.

	auto start = text.begin();
	while (true) {
		if (start == text.end()) {
			break;
		}
		auto iter = std::find_if(start, text.end(),
			[](SizeStringPair a) {
				return a.second.size() > 15;
			});
		if (iter == text.end()) {
			break;
		}
		std::cout << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
		start = iter + 1;
	}


	return 0;
}
