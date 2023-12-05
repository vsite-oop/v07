#include <iostream>
#include "money.h"

using namespace vsite::oop::v7;

int main() {
	money total(0);
	char c; money m;
	while (std::cin >> c >> m) {
		if (c == '-')
			total -= m;
		else
			total += m;
	}
	std::cout << total << '\n';
}
