#include "pch.h"
#include <iostream>
#include "ModularGenetics.h"
#include <bitset>
#include <tuple>
#include <boost\dynamic_bitset.hpp>
#include <vector>

using namespace ModularGenetics;

int main()
{
	std::vector<int> test(100);
	test.push_back(999);

	std::for_each(test.begin(), test.end(), [](int element) {
		std::cout << element << std::endl;
	});

	std::cin.get();
}
