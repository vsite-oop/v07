
#include "CppUnitTest.h"
#include "../app/money.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace all_tests
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			money a(1, 80);
			money b(2, 30);
			a += b;
			Assert::AreEqual(4, a.e());
			Assert::AreEqual(10, a.c());
		}
		TEST_METHOD(TestMethod2)
		{
			money a(5, 12);
			money b(2, 32);
			a += b;
			Assert::AreEqual(7, a.e());
			Assert::AreEqual(44, a.c());
		}
		TEST_METHOD(TestMethod3)
		{
			money a(0, 80);
			money b(2, 20);
			a += b;
			Assert::AreEqual(3, a.e());
			Assert::AreEqual(0, a.c());
		}
		TEST_METHOD(TestMethod4)
		{
			money a(51, 80);
			money b(72, 30);
			a += b;
			Assert::AreEqual(124, a.e());
			Assert::AreEqual(10, a.c());
		}
		TEST_METHOD(TestMethod5)
		{
			money a(3, 20);
			money b(2, 30);
			a -= b;
			Assert::AreEqual(0, a.e());
			Assert::AreEqual(90, a.c());
		}
		TEST_METHOD(TestMethod6)
		{
			money a(5, 80);
			money b(2, 30);
			a -= b;
			Assert::AreEqual(3, a.e());
			Assert::AreEqual(50, a.c());
		}
		TEST_METHOD(TestMethod7)
		{
			money a(0, 80);
			money b(2, 30);
			a -= b;
			Assert::AreEqual(-1, a.e());
			Assert::AreEqual(50, a.c());
		}
		TEST_METHOD(TestMethod11)
		{
			money a(0, 80);
			money b(5, 90);
			a -= b;
			Assert::AreEqual(-5, a.e());
			Assert::AreEqual(10, a.c());
		}
		TEST_METHOD(TestMethod12)
		{
			money a(0, 90);
			money b(5, 70);
			a -= b;
			Assert::AreEqual(-4, a.e());
			Assert::AreEqual(80, a.c());
		}
		TEST_METHOD(TestMethod8)
		{
			money total;
			money m(6, 80);
			total += m;
			money m2(7, 20);
			total += m2;
			money m3(12, 40);
			total += m3;
			money m4(-5, 50);
			total -= m4;
			money m5(10, 15);
			total += m5;
			Assert::AreEqual("31 eura 05 centi",total.ispis().c_str());
		}

		TEST_METHOD(TestMethod9)
		{
			money total;
			money m(INT_MAX - 100, 0);
			total += m;
			money m2(102, 0);
			Assert::ExpectException<std::overflow_error>([&] { total += m2; });
		}
		TEST_METHOD(TestMethod10)
		{
			money total;
			money m(INT_MIN + 100, 0);
			total -= m;
			money m2(102, 0);
			Assert::ExpectException<std::underflow_error>([&] { total -= m2; });
		}

	};
}
