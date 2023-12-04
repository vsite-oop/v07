#include "pch.h"
#include "CppUnitTest.h"
#include "../app/money.h"
#include "../app/money.cpp"

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
			Assert::AreEqual(0, m1.geteur());
			Assert::AreEqual(0, m1.getcent());
			Assert::AreEqual(1, m2.geteur());
			Assert::AreEqual(0, m2.getcent());
			Assert::AreEqual(0, m3.geteur());
			Assert::AreEqual(50, m3.getcent());
		}

		TEST_METHOD(money_IOoperators)
		{
			std::stringstream ss;
			std::istringstream is("2 50");
			money a;
			is >> a;
			ss << a;
			Assert::AreEqual("2 eur, 50 cent", ss.str().c_str());
		}
		TEST_METHOD(money_operators) 
		{
			money m1(10,10);
			money m2(1,10);
			m1 += m2;
			Assert::AreEqual(11, m1.geteur());
			Assert::AreEqual(20, m1.getcent());
			m1 -= m2;
			Assert::AreEqual(10, m1.geteur());
			Assert::AreEqual(10, m1.getcent());

		}
		TEST_METHOD(money_Overflow)
		{
			std::stringstream ss;
			money a(4, 90);
			money b(2, 20);
			money c(0, 1000);
			a += b;
			ss << a;
			Assert::AreEqual("7 eur, 10 cent", ss.str().c_str());
			ss.str("");
			ss << c;
			Assert::AreEqual("10 eur, 0 cent", ss.str().c_str());
			ss.str("");
		}
		TEST_METHOD(money_Underflow)
		{
			std::stringstream ss;
			money a(4, 90);
			money b(2, 20);
			money c(0, -1000);
			b -= a;
			ss << b;
			Assert::AreEqual("-2 eur, 70 cent", ss.str().c_str());
			ss.str("");
			ss << c;
			Assert::AreEqual("-10 eur, 0 cent", ss.str().c_str());
		}
	};
}
