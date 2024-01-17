#include "CppUnitTest.h"
#include "../app/money.h"
//#include "../UnitTest1/pch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;
using namespace std::string_literals;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestInitializeMoney)
		{
			std::stringstream test1;
			test1 << money(2, 5);
			Assert::AreEqual("02 kn, 05 lp"s, test1.str());

			std::stringstream test2;
			test2 << money(1, 0);
			Assert::AreEqual("01 kn"s, test2.str());

			std::stringstream test3;
			test3 << money(0, 50);
			Assert::AreEqual("50 lp"s, test3.str());

			std::stringstream test4;
			test4 << money(0);
			Assert::AreEqual("00 lp"s, test4.str());

			std::stringstream test5;
			test5 << money(0, 150);
			Assert::AreEqual("01 kn, 50 lp"s, test5.str());
		}

		TEST_METHOD(TestPlus)
		{
			auto test1m1 = money(2, 10);
			auto test1m2 = money(3, 25);
			auto res1 = test1m1 + test1m2;
			std::stringstream test1;
			test1 << res1;
			Assert::AreEqual("05 kn, 35 lp"s, test1.str());

			auto test2m1 = money(0, 45);
			auto test2m2 = money(6, 10);
			auto res2 = test2m1 + test2m2;
			std::stringstream test2;
			test2 << res2;
			Assert::AreEqual("06 kn, 55 lp"s, test2.str());
		}

		TEST_METHOD(TestPlusEquals)
		{
			auto test1m1 = money(2, 10);
			auto test1m2 = money(3, 25);
			test1m1 += test1m2;
			std::stringstream test1;
			test1 << test1m1;
			Assert::AreEqual("05 kn, 35 lp"s, test1.str());

			auto test2m1 = money(0, 45);
			auto test2m2 = money(6, 10);
			test2m1 += test2m2;
			std::stringstream test2;
			test2 << test2m1;
			Assert::AreEqual("06 kn, 55 lp"s, test2.str());
		}

		TEST_METHOD(TestPlusOverflow)
		{
			auto test1m1 = money(4, 25);
			auto test1m2 = money(0, 90);
			auto res1 = test1m1 + test1m2;
			std::stringstream test1;
			test1 << res1;
			Assert::AreEqual("05 kn, 15 lp"s, test1.str());

			auto test2m1 = money(0, 85);
			auto test2m2 = money(0, 75);
			test2m1 += test2m2;
			std::stringstream test2;
			test2 << test2m1;
			Assert::AreEqual("01 kn, 60 lp"s, test2.str());
		}

		TEST_METHOD(TestMinus)
		{
			auto test1m1 = money(3, 90);
			auto test1m2 = money(1, 25);
			auto res1 = test1m1 - test1m2;
			std::stringstream test1;
			test1 << res1;
			Assert::AreEqual("02 kn, 65 lp"s, test1.str());

			auto test2m1 = money(10, 45);
			auto test2m2 = money(6, 10);
			auto res2 = test2m1 - test2m2;
			std::stringstream test2;
			test2 << res2;
			Assert::AreEqual("04 kn, 35 lp"s, test2.str());
		}

		TEST_METHOD(TestMinusEquals)
		{
			auto test1m1 = money(3, 90);
			auto test1m2 = money(2, 25);
			test1m1 -= test1m2;
			std::stringstream test1;
			test1 << test1m1;
			Assert::AreEqual("01 kn, 65 lp"s, test1.str());

			auto test2m1 = money(5, 95);
			auto test2m2 = money(2, 20);
			test2m1 -= test2m2;
			std::stringstream test2;
			test2 << test2m1;
			Assert::AreEqual("03 kn, 75 lp"s, test2.str());
		}

		TEST_METHOD(TestMinusOverflow)
		{
			auto test1m1 = money(2, 25);
			auto test1m2 = money(0, 70);
			auto res1 = test1m1 - test1m2;
			std::stringstream test1;
			test1 << res1;
			Assert::AreEqual("01 kn, 55 lp"s, test1.str());

			auto test2m1 = money(1, 20);
			auto test2m2 = money(0, 75);
			test2m1 -= test2m2;
			std::stringstream test2;
			test2 << test2m1;
			Assert::AreEqual("45 lp"s, test2.str());
		}

		TEST_METHOD(TestMain)
		{
			money total(0);
			total += money(0, 15);
			total += money(2, 75);
			total += money(3, 10);
			total += money(1, 25);
			std::stringstream test1;
			test1 << total;
			Assert::AreEqual("07 kn, 25 lp"s, test1.str());
		}
	};
}
