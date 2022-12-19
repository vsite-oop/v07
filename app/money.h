#pragma once
#include <iostream>

namespace vsite::oop::v7 
{

class money 
{
private:
	int lipe;

	friend std::istream& operator>>(std::istream&, money&);
	friend std::ostream& operator<<(std::ostream&, const money&);

public:
	money(int kune = 0, int lipe = 0);
	money(const money& other);
	~money() = default;

	int get_kune() const;
	int get_lipe() const;

	auto operator<=>(const money& other) const = default;

	money& operator+=(const money& other);
	money& operator-=(const money& other);
};

}
