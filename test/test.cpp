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
			ss1 << money(0, 80);
			Assert::AreEqual("80 lp"s, ss1.str());

			std::stringstream ss2; 
			ss2 << money(1, 80);
			Assert::AreEqual("1 kn, 80 lp"s, ss2.str());

			std::stringstream ss3;
			ss3 << money(3, 00);
			Assert::AreEqual("3 kn"s, ss3.str());

			std::stringstream ss4;
			ss4 << money(3, 240);
			Assert::AreEqual("5 kn, 40 lp"s, ss4.str());

			std::stringstream ss5;
			ss5 << money(7, 5);
			Assert::AreEqual("7 kn, 05 lp"s, ss5.str());

			std::stringstream ss6;
			ss6 << money(7, 1205);
			Assert::AreEqual("19 kn, 05 lp"s, ss6.str());
		}

		TEST_METHOD(TestAddMoney)
		{
			money total(0);
			money m(0, 40);

			total += m;
			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("40 lp"s, ss1.str());
			
			total = total + money(20, 30);
			std::stringstream ss2;
			ss2 << total;
			Assert::AreEqual("20 kn, 70 lp"s, ss2.str());
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

		TEST_METHOD(TestSubMoney)
		{
			money total(0, 280);
			money m(0, 30);

			total -= m;
			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("2 kn, 50 lp"s, ss1.str());

			total = total - money(1, 20);
			std::stringstream ss2;
			ss2 << total;
			Assert::AreEqual("1 kn, 30 lp"s, ss2.str());
		}

		TEST_METHOD(TestUnderflow)
		{
			money total(0, 1439);

			total -= money(5, 89);
			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("8 kn, 50 lp"s, ss1.str());

			total -= money(0, 230);
			std::stringstream ss2;
			ss2 << total;
			Assert::AreEqual("6 kn, 20 lp"s, ss2.str());

			total -= money(0, 40);
			std::stringstream ss3;
			ss3 << total;
			Assert::AreEqual("5 kn, 80 lp"s, ss3.str());

			total -= money(5, 00);
			std::stringstream ss4;
			ss4 << total;
			Assert::AreEqual("80 lp"s, ss4.str());
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
