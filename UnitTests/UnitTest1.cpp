#include "../app/money.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;


namespace UnitTests
{
	TEST_CLASS(test_v7_money)
	{
	public:
		TEST_METHOD(initialisation)
		{
			money a;
			Assert::AreEqual(0, a.get_kune());
			Assert::AreEqual(0, a.get_lipe());

			money b(2);
			Assert::AreEqual(2, b.get_kune());
			Assert::AreEqual(0, b.get_lipe());

			money c(4, 20);
			Assert::AreEqual(4, c.get_kune());
			Assert::AreEqual(20, c.get_lipe());	
			
			money d(-50, 0);
			Assert::AreEqual(-50, d.get_kune());
			Assert::AreEqual(0, d.get_lipe());	
			
			money e(0, -20);
			Assert::AreEqual(0, e.get_kune());
			Assert::AreEqual(-20, e.get_lipe());

			money f(-42, 20);
			Assert::AreEqual(-42, f.get_kune());
			Assert::AreEqual(-20, f.get_lipe());
		}

		TEST_METHOD(addition_and_subtraction)
		{
			money a;

			a += money(10, 10);
			Assert::AreEqual(10, a.get_kune());
			Assert::AreEqual(10, a.get_lipe());

			a -= money(5, 5);
			Assert::AreEqual(5, a.get_kune());
			Assert::AreEqual(5, a.get_lipe());

			a += money(7, 30);
			Assert::AreEqual(12, a.get_kune());
			Assert::AreEqual(35, a.get_lipe());
		}

		TEST_METHOD(copy)
		{
			money a(10, 10);
			money b = a;

			Assert::AreEqual(a.get_kune(), b.get_kune());
			Assert::AreEqual(a.get_lipe(), b.get_lipe());

			b += money(5, 5);
			Assert::AreEqual(15, b.get_kune());
			Assert::AreEqual(15, b.get_lipe());
			Assert::AreNotEqual(a.get_kune(), b.get_kune());
			Assert::AreNotEqual(a.get_lipe(), b.get_lipe());
		}

		TEST_METHOD(output_empty)
		{
			std::stringstream ss;
			money a;
			ss << a;
			Assert::AreEqual("0 kn, 0 lp", ss.str().c_str());
		}

		TEST_METHOD(output_kune)
		{
			std::stringstream ss;
			money a(10, 0);
			ss << a;
			Assert::AreEqual("10 kn", ss.str().c_str());

			std::stringstream ss2;
			money b(-10, 0);
			ss2 << b;
			Assert::AreEqual("-10 kn", ss2.str().c_str());
		}

		TEST_METHOD(output_lipe)
		{
			std::stringstream ss;
			money a(0, 10);
			ss << a;
			Assert::AreEqual("10 lp", ss.str().c_str());

			std::stringstream ss2;
			money b(0, -10);
			ss2 << b;
			Assert::AreEqual("-10 lp", ss2.str().c_str());
		}

		TEST_METHOD(output_kune_and_lipe)
		{
			std::stringstream ss;
			money a(10, 10);
			ss << a;
			Assert::AreEqual("10 kn, 10 lp", ss.str().c_str());

			std::stringstream ss2;
			a -= money(10, 15);
			ss2 << a;
			Assert::AreEqual("-5 lp", ss2.str().c_str());

			std::stringstream ss3;
			a -= money(1, 5);
			ss3 << a;
			Assert::AreEqual("-1 kn, 10 lp", ss3.str().c_str());
		}
	};
}