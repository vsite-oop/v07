﻿#pragma once
#include <iostream>

namespace vsite::oop::v7
{

	class money {
		int total;

	public:
		// konstruktori
		money(int e = 0, int c = 0);

		// operatori
		money& operator +=(const money& m);
		money& operator -=(const money& m);

		friend std::istream& operator >> (std::istream& is, money& m);
		friend std::ostream& operator << (std::ostream& os, const money& m);

		// metode
		int get_value() const;
		void add_value(int addt, int dec);
		void sub_value(int subs, int dec);
	};

}
