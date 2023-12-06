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
			Assert::AreEqual("80 lp"s, money(0, 80).to_string());
			Assert::AreEqual("1 kn, 80 lp"s, money(1, 80).to_string());
			Assert::AreEqual("3 kn"s, money(3, 00).to_string());
			Assert::AreEqual("5 kn, 40 lp"s, money(3, 240).to_string());
			Assert::AreEqual("7 kn, 05 lp"s, money(7, 5).to_string());
			Assert::AreEqual("19 kn, 05 lp"s, money(7, 1205).to_string());
		}

		TEST_METHOD(TestAddMoney)
		{
			money total(0);
			money m(0, 40);

			total += m;
			Assert::AreEqual("40 lp"s, total.to_string());
			
			total = total + money(20, 30);
			Assert::AreEqual("20 kn, 70 lp"s, total.to_string());
		}

		TEST_METHOD(TestOverflow)
		{
			money total(0, 50);

			total += money(0, 80);
			Assert::AreEqual("1 kn, 30 lp"s, total.to_string());

			total += money(0, 230);
			Assert::AreEqual("3 kn, 60 lp"s, total.to_string());

			total += money(12, 35);
			Assert::AreEqual("15 kn, 95 lp"s, total.to_string());
		}

		TEST_METHOD(TestSubMoney)
		{
			money total(0, 280);
			money m(0, 30);

			total -= m;
			Assert::AreEqual("2 kn, 50 lp"s, total.to_string());

			total = total - money(1, 20);
			Assert::AreEqual("1 kn, 30 lp"s, total.to_string());
		}

		TEST_METHOD(TestUnderflow)
		{
			money total(0, 1439);

			total -= money(5, 89);
			Assert::AreEqual("8 kn, 50 lp"s, total.to_string());

			total -= money(0, 230);
			Assert::AreEqual("6 kn, 20 lp"s, total.to_string());

			total -= money(0, 40);
			Assert::AreEqual("5 kn, 80 lp"s, total.to_string());

			total -= money(5, 00);
			Assert::AreEqual("80 lp"s, total.to_string());
		}

		TEST_METHOD(TestMain)
		{
			money total(0);

			total += money(6, 80);
			total += money(7, 20);
			total += money(12, 40);
			total -= money(5, 50);
			total += money(10, 15);

			Assert::AreEqual("31 kn, 05 lp"s, total.to_string());
		}
	};
}
