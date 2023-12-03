#include "pch.h"
#include "CppUnitTest.h"
#include "../app/money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(money_constructors)
		{
			money m1;
			money m2(1);
			money m3(0, 50);
			Assert::AreEqual(0u, m1.geteur());
			Assert::AreEqual(0u, m1.getcent());
			Assert::AreEqual(1u, m1.geteur());
			Assert::AreEqual(0u, m1.getcent());
			Assert::AreEqual(0u, m1.geteur());
			Assert::AreEqual(50u, m2.getcent());
		}

		TEST_METHOD(money_operators)
		{
			std::stringstream ss;
			money a;
			money b(2, 20);
			(2, 55) >> a;
			a -= b;
			ss << a;
			Assert::AreEqual("0 eur, 35 cent", ss.str().c_str());
			a += b;
			ss << a;
			Assert::AreEqual("2 eur, 55 cent", ss.str().c_str());
		}

		TEST_METHOD(money_UnderOverflow)
		{
			money a(4, 90);
			money b(2, 20);
			Assert::AreEqual((7, 10), a+=b);
		}
	};
}
