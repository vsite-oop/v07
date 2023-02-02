#include "pch.h"
#include "CppUnitTest.h"
#include "../app/money.h"
#include "../app/money.cpp"

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

			money b(10);
			Assert::AreEqual(10, b.get_kune());
			Assert::AreEqual(0, b.get_lipe());

			money c(10, 20);
			Assert::AreEqual(10, c.get_kune());
			Assert::AreEqual(20, c.get_lipe());

			money e(0, 10);
			Assert::AreEqual(0, e.get_kune());
			Assert::AreEqual(10, e.get_lipe());

			money f(-10, 20);
			Assert::AreEqual(-10, f.get_kune());
			Assert::AreEqual(-20, f.get_lipe());
		}

		TEST_METHOD(add_and_sub)
		{
			money a;

			a += money(10, 10);
			Assert::AreEqual(10, a.get_kune());
			Assert::AreEqual(10, a.get_lipe());

			a -= money(10,0);
			Assert::AreEqual(0, a.get_kune());
			Assert::AreEqual(10, a.get_lipe());

			a += money(20, 20);
			Assert::AreEqual(20, a.get_kune());
			Assert::AreEqual(30, a.get_lipe());
		}

		TEST_METHOD(copy)
		{
			money a(10, 10);
			money b = a;

			Assert::AreEqual(a.get_kune(), b.get_kune());
			Assert::AreEqual(a.get_lipe(), b.get_lipe());

			b += money(20, 20);
			Assert::AreEqual(30, b.get_kune());
			Assert::AreEqual(30, b.get_lipe());
			Assert::AreNotEqual(a.get_kune(), b.get_kune());
			Assert::AreNotEqual(a.get_lipe(), b.get_lipe());
		}

		TEST_METHOD(default_output)
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
			money a(0, 50);
			ss << a;
			Assert::AreEqual("50 lp", ss.str().c_str());

			std::stringstream ss2;
			money b(0, -50);
			ss2 << b;
			Assert::AreEqual("-50 lp", ss2.str().c_str());
		}

		TEST_METHOD(output_kune_and_lipe)
		{
			std::stringstream ss;
			money a(11, 70);
			ss << a;
			Assert::AreEqual("11 kn, 70 lp", ss.str().c_str());

			std::stringstream ss2;
			a -= money(11, 50);
			ss2 << a;
			Assert::AreEqual("20 lp", ss2.str().c_str());

			std::stringstream ss3;
			a += money(1, 70);
			ss3 << a;
			Assert::AreEqual("1 kn, 90 lp", ss3.str().c_str());
		}
	};
}
