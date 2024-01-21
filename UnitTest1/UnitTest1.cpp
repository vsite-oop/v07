#include "pch.h"
#include "..\app\money.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::string_literals;
using namespace vsite::oop::v7;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(Owerflow_Test)
		{
			money total(0, 50);

			total += money(0, 70);
			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("1 E i 20 c."s, ss1.str());

			total += money(0, 220);
			std::stringstream ss2;
			ss2 << total;
			Assert::AreEqual("3 E i 40 c."s, ss2.str());

			total += money(18, 78);
			std::stringstream ss3;
			ss3 << total;
			Assert::AreEqual("22 E i 18 c."s, ss3.str());
		}

		TEST_METHOD(Underflow_Test)
		{
			money total(0, 2000);

			total -= money(10, 50);
			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("9 E i 50 c."s, ss1.str());

			total -= money(0, 220);
			std::stringstream ss2;
			ss2 << total;
			Assert::AreEqual("7 E i 30 c."s, ss2.str());

			total -= money(0, 41);
			std::stringstream ss3;
			ss3 << total;
			Assert::AreEqual("6 E i 89 c."s, ss3.str());

			total -= money(6, 00);
			std::stringstream ss4;
			ss4 << total;
			Assert::AreEqual("89 c."s, ss4.str());
		}

		TEST_METHOD(NulaEuraIspis_Test)
		{
			std::stringstream ss;
			money m(0, 37);
			ss << m;
			Assert::AreEqual("37 c."s, ss.str());
		}

		TEST_METHOD(NulaCentaIspis_Test)
		{
			std::stringstream ss;
			money m(7);
			ss << m;
			Assert::AreEqual("7 E."s, ss.str());
		}

		TEST_METHOD(NulaSve_Test)
		{
			std::stringstream ss;
			money m;
			ss << m;
			Assert::AreEqual("0 E."s, ss.str());
		}

		TEST_METHOD(Primjer_Test)
		{
			money total(0);

			total += money(6, 80);
			total += money(7, 20);
			total += money(12, 40);
			total -= money(5, 50);
			total += money(10, 15);

			std::stringstream ss;
			ss << total;
			Assert::AreEqual("31 E i 5 c."s, ss.str());
		}
	};
}