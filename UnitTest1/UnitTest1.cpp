
#include "CppUnitTest.h"
#include "../app/money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(default_constructor_zero)
		{
			money a;
			Assert::AreEqual("00 kn", a.toString().c_str());
			a += money(104, 20);
			Assert::AreEqual("104 kn, 20 lp", a.toString().c_str());
			a += money(4, 80);
			Assert::AreEqual("109 kn", a.toString().c_str());
			a -= money(108, 20);
			Assert::AreEqual("80 lp", a.toString().c_str());
		}

		TEST_METHOD(one_argument_constructor) 
		{
			money a(5);
			Assert::AreEqual("05 kn", a.toString().c_str());
			money b = a + money(10, 99);
			Assert::AreEqual("15 kn, 99 lp", a.toString().c_str());
			b = b - money(18, 70);
			Assert::AreEqual("00 kn", b.toString().c_str());
			
		}

		TEST_METHOD(double_constructor)
		{
			money a(11.99);
			Assert::AreEqual("11 kn, 99 lp", a.toString().c_str());
		}

		TEST_METHOD(double_conversion)
		{
			money a(11, 99);
			Assert::AreEqual(11.99, double(a));
			money b = a + 4.99;
			Assert::AreEqual(16.98, double(b));
			b += 3.02;
			Assert::AreEqual(20., double(b));
			money c = b - 14.60;
			Assert::AreEqual(5.40, double(c));
			c -= 99.99;
			Assert::AreEqual(0., double(c));
		}
	};
}
