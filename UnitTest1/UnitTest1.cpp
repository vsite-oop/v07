#include "CppUnitTest.h"
#include "../app/money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;
using namespace std::string_literals;

namespace UnitTest1
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(Overflow)
		{
			money total(10, 05);

			total += money(0, 70);
			std::stringstream t1;
			t1 << total;
			Assert::AreEqual("10 eur, 75 ct"s, t1.str());

			total += money(23, 25);
			std::stringstream t2;
			t2 << total;
			Assert::AreEqual("34 eur, 0 ct"s, t2.str());

			total += money(100, 99);
			std::stringstream t3;
			t3 << total;
			Assert::AreEqual("134 eur, 99 ct"s, t3.str());
		}

		TEST_METHOD(Underflow)
		{
			money total(90, 50);

			total -= money(10, 50);
			std::stringstream t1;
			t1 << total;
			Assert::AreEqual("80 eur, 0 ct"s, t1.str());

			total -= money(0, 33);
			std::stringstream t2;
			t2 << total;
			Assert::AreEqual("79 eur, 67 ct"s, t2.str());

			total -= money(90, 0);
			std::stringstream t3;
			t3 << total;
			Assert::AreEqual("-10 eur, -33 ct"s, t3.str());
		}

		TEST_METHOD(Overflow_and_Underflow)
		{
			money total(1, 50);
			total += money(23, 70);
			total -= money(4, 50);
			total -= money(21, 99);
			total += money(42, 10);
			total -= money(0, 05);

			std::stringstream t;
			t << total;
			Assert::AreEqual("40 eur, 76 ct"s, t.str());
		}

		TEST_METHOD(Overflow_a_lot_of_ct)
		{
			money total(1, 55);

			total += money(0, 100);
			std::stringstream t1;
			t1 << total;
			Assert::AreEqual("2 eur, 55 ct"s, t1.str());

			total += money(5, 222);
			std::stringstream t2;
			t2 << total;
			Assert::AreEqual("9 eur, 77 ct"s, t2.str());
		}

		TEST_METHOD(Underflow_a_lot_of_ct)
		{
			money total(10, 50);

			total -= money(0, 100);
			std::stringstream t1;
			t1 << total;
			Assert::AreEqual("9 eur, 50 ct"s, t1.str());

			total -= money(3, 333);
			std::stringstream t2;
			t2 << total;
			Assert::AreEqual("3 eur, 17 ct"s, t2.str());
		}

		TEST_METHOD(Zero_eur)
		{
			std::stringstream t;
			money m(0, 99);
			t << m;
			Assert::AreEqual("0 eur, 99 ct"s, t.str());
		}

		TEST_METHOD(Zero_ct)
		{
			std::stringstream t;
			money m(10, 0);
			t << m;
			Assert::AreEqual("10 eur, 0 ct"s, t.str());
		}

		TEST_METHOD(Zero)
		{
			std::stringstream t;
			money m(0);
			t << m;
			Assert::AreEqual("0 eur, 0 ct"s, t.str());
		}
	};
}
