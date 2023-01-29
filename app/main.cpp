#include <iostream>
#include "money.h"

using vsite::oop::v7::money;

int main() {
	money total(0); //defaultni konstruktor
	char c; money m;
	while (std::cin >> c >> m) { //c -> +/- m->tip money
		if (c == '-')
			total -= m;
		else
			total += m;
	}
	std::cout << total << '\n';
}
