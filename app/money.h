#pragma once

namespace vsite::oop::v7 
{

class money {
private:
	int kn;
	int lp;

public:
	money();
	money(int kn);
	money(int kn, int lp);

	friend std::istream& operator>> (std::istream&, money&);
	friend std::ostream& operator<< (std::ostream&, const money&);

	money& operator+= (const money&);
	money& operator-= (const money&);

	~money();
};

}
