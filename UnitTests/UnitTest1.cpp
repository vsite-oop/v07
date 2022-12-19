#include "../app/money.h"
#include "CppUnitTest.h"
//#include <type_traits>
//#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;


namespace UnitTests
{
	TEST_CLASS(test_v7_money)
	{
	public:
		TEST_METHOD(default_ctor_init_to_zero)
		{
			money a;
			Assert::AreEqual(0, a.get_kune());
			Assert::AreEqual(0, a.get_lipe());

		}

		TEST_METHOD(ctor_init_one_argument)
		{
			money a(0);
			Assert::AreEqual(0, a.get_kune());
			Assert::AreEqual(0, a.get_lipe());
		}

		TEST_METHOD(ctor_init_two_arguments)
		{
			money a(2, 40);
			Assert::AreEqual(2, a.get_kune());
			Assert::AreEqual(40, a.get_lipe());
		}

		TEST_METHOD(copy_ctor)
		{
			money a(2, 60);
			money b = a;

			Assert::AreEqual(a.get_kune(), b.get_kune());
			Assert::AreEqual(a.get_lipe(), b.get_lipe());
		}

		TEST_METHOD(compare_operator)
		{
			money a(4, 40);
			money b(2, 60);
			money c = b;

			Assert::IsTrue(a > b);
			Assert::IsFalse(a < b);
			Assert::IsTrue(a != b);
			Assert::IsTrue(c == b);
		}

		TEST_METHOD(plus_equals_operator)
		{
			money a(4, 40);
			money b(2, 60);
			a += b;

			Assert::AreEqual(700, a.get_kune() * 100 + a.get_lipe());
		}

		TEST_METHOD(minus_equals_operator)
		{
			money a(4, 40);
			money b(2, 60);
			a -= b;

			Assert::AreEqual(180, a.get_kune() * 100 + a.get_lipe());
		}

		TEST_METHOD(cin_operator_overload)
		{
			money a;
			money b(2, 40);
			std::stringstream ss;
			ss << "2 40";
			ss >> a;

			Assert::AreEqual(a.get_kune() * 100 + a.get_lipe(), b.get_kune() * 100 + b.get_lipe());
		}

		TEST_METHOD(money_cout_operator)
		{
			money a(2, 40);
			std::stringstream ss;
			ss << a;

			Assert::AreEqual("2 kn, 40 lp", ss.str().c_str());
		}

		TEST_METHOD(kune_cout_operator)
		{
			money a(2);
			std::stringstream ss;
			ss << a;

			Assert::AreEqual("2 kn", ss.str().c_str());
		}

		TEST_METHOD(lipe_cout_operator)
		{
			money a(0, 40);
			std::stringstream ss;
			ss << a;

			Assert::AreEqual("40 lp", ss.str().c_str());
		}
	};
}