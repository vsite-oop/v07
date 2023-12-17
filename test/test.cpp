#include "CppUnitTest.h"
#include "../app/money.h"

using namespace std::string_literals;
using namespace vsite::oop::v7;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:		
		TEST_METHOD(TestMoney)
		{
			std::stringstream ss1;
			ss1 << money(0, 69);
			Assert::AreEqual("69 lp"s, ss1.str());

			std::stringstream ss2; 
			ss2 << money(3, 69);
			Assert::AreEqual("3 kn, 69 lp"s, ss2.str());

			std::stringstream ss3;
			ss3 << money(5, 00);
			Assert::AreEqual("5 kn"s, ss3.str());

			std::stringstream ss4;
			ss4 << money(3, 169);
			Assert::AreEqual("4 kn, 69 lp"s, ss4.str());
		}


		TEST_METHOD(TestMain)
		{
			money total(0);

			total += money(6, 80);
			total += money(7, 20);
			total += money(12, 40);
			total -= money(5, 50);
			total += money(10, 15);

			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("31 kn, 05 lp"s, ss1.str());
		}


		TEST_METHOD(TestOverflow)
		{
			money total(0, 50);

			total += money(0, 80);
			std::stringstream ss1;
			ss1 << total; 
			Assert::AreEqual("1 kn, 30 lp"s, ss1.str());

			total += money(0, 230);
			std::stringstream ss2;
			ss2 << total; 
			Assert::AreEqual("3 kn, 60 lp"s, ss2.str());

			total += money(12, 35);
			std::stringstream ss3;
			ss3 << total; 
			Assert::AreEqual("15 kn, 95 lp"s, ss3.str());
		}

		TEST_METHOD(TestUnderflow)
		{
			money total(0, 6969);

			total -= money(50, 91);
			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("18 kn, 78 lp"s, ss1.str());

			total -= money(0, 289);
			std::stringstream ss2;
			ss2 << total;
			Assert::AreEqual("15 kn, 89 lp"s, ss2.str());

			total -= money(5, 20);
			std::stringstream ss3;
			ss3 << total;
			Assert::AreEqual("10 kn, 69 lp"s, ss3.str());

			total -= money(10, 00);
			std::stringstream ss4;
			ss4 << total;
			Assert::AreEqual("69 lp"s, ss4.str());
		}



		TEST_METHOD(TestOperatorPlusEq)
		{
			auto a = money(6, 80);
			auto b = money(7, 20);

			a += b;

			std::stringstream ss1;
			ss1 << a;
			Assert::AreEqual("14 kn"s, ss1.str());
		}		
		
		TEST_METHOD(TestOperatorPlus)
		{
			auto a = money(6, 80);
			auto b = money(7, 20);

			auto c = a + b;

			std::stringstream ss1;
			ss1 << a;
			Assert::AreEqual("6 kn, 80 lp"s, ss1.str());

			std::stringstream ss2;
			ss2 << c;
			Assert::AreEqual("14 kn"s, ss2.str());
		}

		TEST_METHOD(TestOperatorMinusEq)
		{
			auto a = money(7, 20);
			auto b = money(6, 80);

			a -= b;

			std::stringstream ss1;
			ss1 << a;
			Assert::AreEqual("40 lp"s, ss1.str());
		}

		TEST_METHOD(TestOperatorMinus)
		{
			auto a = money(7, 20);
			auto b = money(6, 80);

			auto c = a - b;

			std::stringstream ss1;
			ss1 << a;
			Assert::AreEqual("7 kn, 20 lp"s, ss1.str());

			std::stringstream ss2;
			ss2 << c;
			Assert::AreEqual("40 lp"s, ss2.str());
		}


	};
}


		

