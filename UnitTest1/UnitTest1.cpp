
#include "CppUnitTest.h"
#include"../app/money.h"

using namespace std::string_literals;
using namespace vsite::oop::v7;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			std::stringstream ss1;
			ss1 << money(0, 80);
			Assert::AreEqual("80 lp"s, ss1.str());

			std::stringstream ss2;
			ss2 << money(1, 50);
			Assert::AreEqual("1 kn, 50 lp"s, ss2.str());


		}
		TEST_METHOD(Test2)
		{

			std::stringstream ss1;
			ss1 << money(10, 240);
			Assert::AreEqual("12 kn, 40 lp"s, ss1.str());

		}

		TEST_METHOD(Test3)
		{
			money total(0);
			money m1(0, 40);

			total += m1;
			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("40 lp"s, ss1.str());

			money m2(50, 00);

			total += m2;
			std::stringstream ss2;
			ss2 << total;
			Assert::AreEqual("50 kn, 40 lp"s, ss2.str());

			money m3(00, 61);

			total += m3;
			std::stringstream ss3;
			ss3 << total;
			Assert::AreEqual("51 kn, 01 lp"s, ss3.str());


		}

		TEST_METHOD(Test4)
		{
			money total(0, 280);
			money m(0, 30);

			total -= m;
			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("2 kn, 50 lp"s, ss1.str());

			total = total - money(1, 20);
			std::stringstream ss2;
			ss2 << total;
			Assert::AreEqual("1 kn, 30 lp"s, ss2.str());

			
		}
	};
}
