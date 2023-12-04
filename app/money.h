#pragma once
#include<iostream>
#include<sstream>


namespace vsite::oop::v7 
{
	class money {
		int eur;
		int cent;
		friend std::istream& operator>>(std::istream& input, money& m);
		friend std::ostream& operator<<(std::ostream& output, const money& m);
		void overflow();
		void underflow();
	public:
		money(int e=0, int c=0);
		money(const money& other): eur(other.eur), cent(other.cent){}
		int const geteur()  { return eur; }
		int const getcent()  { return cent; }
		money& operator+=(const money& other);
		money& operator-=(const money& other);


};

}
