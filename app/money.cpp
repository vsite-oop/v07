#include "money.h"
#include <algorithm>

#include<iostream>
#include<iomanip>

namespace vsite::oop::v7
{
	money::money(int kune , int lipe) : kn(kune), lp(lipe) {};

	std::istream& operator>> (std::istream& is, money& m) {
		return is >> m.kn >> m.lp;
	}

	std::ostream& operator<< (std::ostream& os,const money& m) {
		
		/*os << m.kn << ' ' << "kn";
		if (m.lp)
			os << "," << ' ' << std::setw(2) << std::setfill('0') << m.lp << ' ' << "lp";
		return os;*/

		if(m.lp ==0)
			os << m.kn << ' ' << "kn";
		else if(m.kn ==0)
			os << std::setw(2) << std::setfill('0') << m.lp << ' ' << "lp";
		else
			os << m.kn << ' ' << "kn" << "," << ' ' << std::setw(2) << std::setfill('0') << m.lp << ' ' << "lp";

		return os;
	}
	

	money& money::operator+=(const money& other) {
		
		this->kn += other.kn;
		this->lp += other.lp;

		if (this->lp >= 100) {
			this->kn++;
			this->lp = this->lp % 100;
		}
		return *this;
	}

	money& money::operator-=(const money& other) {

		this->kn -= other.kn;

		if(this->lp < other.lp){
			this->kn--;
			this->lp = this->lp + 100 - other.lp;
		}
		else {
			this->lp = this->lp - other.lp;
		}
		return *this;
	}

	int money::kune() const {
		return kn;
	}

	int money::lipe() const {
		return lp;
	}
}