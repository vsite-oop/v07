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
			std::stringstream s1;
			s1 << money(0, 50);
			Assert::AreEqual("50 cent"s, s1.str());

			std::stringstream s2;
			s2 << money(1, 40);
			Assert::AreEqual("1 eur, 40 cent"s, s2.str());

			std::stringstream s3;
			s3 << money(5, 00);
			Assert::AreEqual("5 eur"s, s3.str());

			std::stringstream s4;
			s4 << money(9, 330);
			Assert::AreEqual("12 eur, 30 cent"s, s4.str());

			std::stringstream s5;
			s5 << money(4, 4);
			Assert::AreEqual("4 eur, 04 cent"s, s5.str());
		}

		TEST_METHOD(TestAddMoney)
		{
			money total(0);
			money m(0, 50);

			total += m;
			std::stringstream s1;
			s1 << total;
			Assert::AreEqual("50 cent"s, s1.str());

			total = total + money(2, 40);
			std::stringstream s2;
			s2 << total;
			Assert::AreEqual("2 eur, 90 cent"s, s2.str());
		}

		TEST_METHOD(TestOverflow)
		{
			money total(0, 60);

			total += money(0, 90);
			std::stringstream s1;
			s1 << total;
			Assert::AreEqual("1 eur, 50 cent"s, s1.str());

			total += money(0, 370);
			std::stringstream s2;
			s2 << total;
			Assert::AreEqual("5 eur, 20 cent"s, s2.str());

			total += money(10, 90);
			std::stringstream s3;
			s3 << total;
			Assert::AreEqual("16 eur, 10 cent"s, s3.str());
		}

		TEST_METHOD(TestSubMoney)
		{
			money total(0, 250);
			money m(0, 40);

			total -= m;
			std::stringstream s1;
			s1 << total;
			Assert::AreEqual("2 eur, 10 cent"s, s1.str());

			total = total - money(1, 05);
			std::stringstream s2;
			s2 << total;
			Assert::AreEqual("1 eur, 05 cent"s, s2.str());
		}

		TEST_METHOD(TestUnderflow)
		{
			money total(0, 1950);

			total -= money(6, 80);
			std::stringstream s1;
			s1 << total;
			Assert::AreEqual("12 eur, 70 cent"s, s1.str());

			total -= money(0, 390);
			std::stringstream s2;
			s2 << total;
			Assert::AreEqual("8 eur, 80 cent"s, s2.str());

			total -= money(0, 90);
			std::stringstream s3;
			s3 << total;
			Assert::AreEqual("7 eur, 90 cent"s, s3.str());

		}

		TEST_METHOD(TestMain)
		{
			money total(0);

			total += money(6, 80);
			total += money(7, 20);
			total += money(12, 40);
			total -= money(5, 50);
			total += money(10, 15);

			std::stringstream s1;
			s1 << total;
			Assert::AreEqual("31 eur, 05 cent"s, s1.str());
		}
	};
}