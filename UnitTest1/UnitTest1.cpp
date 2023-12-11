#include "CppUnitTest.h"
#include "../app/money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TEST1)
		{
			money a;
			Assert::AreEqual(0, a.getEuro());
			Assert::AreEqual(0, a.getCenti());

			money b(2);
			Assert::AreEqual(2, b.getEuro());
			Assert::AreEqual(0, b.getCenti());

			money c(4, 20);
			Assert::AreEqual(4, c.getEuro());
			Assert::AreEqual(20, c.getCenti());

			money d(-50, 0);
			Assert::AreEqual(-50, d.getEuro());
			Assert::AreEqual(0, d.getCenti());

			money e(0, -20);
			Assert::AreEqual(0, e.getEuro());
			Assert::AreEqual(-20, e.getCenti());

			money f(-42, 20);
			Assert::AreEqual(-42, f.getEuro());
			Assert::AreEqual(-20, f.getCenti());
		}

		TEST_METHOD(TEST2)
		{
			money a;

			a += money(10, 10);
			Assert::AreEqual(10, a.getEuro());
			Assert::AreEqual(10, a.getCenti());

			a -= money(5, 5);
			Assert::AreEqual(5, a.getEuro());
			Assert::AreEqual(5, a.getCenti());

			a += money(7, 30);
			Assert::AreEqual(12, a.getEuro());
			Assert::AreEqual(35, a.getCenti());
		}

		TEST_METHOD(TEST3)
		{
			money a(10, 10);
			money b = a;

			Assert::AreEqual(a.getEuro(), b.getEuro());
			Assert::AreEqual(a.getCenti(), b.getCenti());

			b += money(5, 5);
			Assert::AreEqual(15, b.getEuro());
			Assert::AreEqual(15, b.getCenti());
			Assert::AreNotEqual(a.getEuro(), b.getEuro());
			Assert::AreNotEqual(a.getCenti(), b.getCenti());
		}

		TEST_METHOD(TEST4)
		{
			std::stringstream ss;
			money a;
			ss << a;
			Assert::AreEqual("0 Eura, 0 centi", ss.str().c_str());
		}

		TEST_METHOD(TEST5)
		{
			std::stringstream ss;
			money a(10, 0);
			ss << a;
			Assert::AreEqual("10 Eura", ss.str().c_str());

			std::stringstream ss2;
			money b(-10, 0);
			ss2 << b;
			Assert::AreEqual("-10 Eura", ss2.str().c_str());
		}

		TEST_METHOD(TEST6)
		{
			std::stringstream ss;
			money a(0, 10);
			ss << a;
			Assert::AreEqual("10 centi", ss.str().c_str());

			std::stringstream ss2;
			money b(0, -10);
			ss2 << b;
			Assert::AreEqual("-10 centi", ss2.str().c_str());
		}

		TEST_METHOD(TEST7)
		{
			std::stringstream ss;
			money a(10, 10);
			ss << a;
			Assert::AreEqual("10 Eura, 10 centi", ss.str().c_str());

			std::stringstream ss2;
			a -= money(10, 15);
			ss2 << a;
			Assert::AreEqual("-5 centi", ss2.str().c_str());

			std::stringstream ss3;
			a -= money(1, 5);
			ss3 << a;
			Assert::AreEqual("-1 Eura, 10 centi", ss3.str().c_str());
		}
	};
}
