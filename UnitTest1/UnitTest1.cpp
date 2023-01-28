
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

		TEST_METHOD(single_digit_lp)
		{
			money a(0, 9);
			Assert::AreEqual("09 lp", a.toString().c_str());
			a += money(4, 90);
			Assert::AreEqual("04 kn, 99 lp", a.toString().c_str());
			a -= money(4, 94);
			Assert::AreEqual("05 lp", a.toString().c_str());
		}

		TEST_METHOD(test_input)
		{
			std::stringstream ss("6 40  3 60  9 99");
			money a, b, c;
			ss >> a >> b >> c;
			Assert::AreEqual("06 kn, 40 lp", a.toString().c_str());
			Assert::AreEqual("03 kn, 60 lp", b.toString().c_str());
			Assert::AreEqual("09 kn, 99 lp", c.toString().c_str());
		}

		TEST_METHOD(test_output)
		{
			std::stringstream ss;
			money m;
			m += money(7, 90);
			m -= money(7, 45);
			ss << m;
			Assert::AreEqual("45 lp", ss.str().c_str());
		}
	};
}
