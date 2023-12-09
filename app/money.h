#pragma once
#include <iostream>

namespace vsite::oop::v7
{

	//DID_IT: u solution dodajte projekt za unit testove ("Native Unit Test Project")
	//DID_IT: u unit test projekt dodajte /app/money.h i /app/money.cpp
	//DID_IT: u UnitTest1.cpp (možete ga preimenovati) dodajte #include "money.h"
	//DID_IT: napišite što više testova i provjera (Assert-ova) koji pokrivaju barem funkcionalnost potrebnu za već napisani program (u main.cpp)
	//DID_IT: implementirajte public metode i potrebne operatore klase money


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
