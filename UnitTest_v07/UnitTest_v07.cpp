#include "CppUnitTest.h"
#include "..\app\money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace UnitTestv07
{
	TEST_CLASS(UnitTestv07)
	{
	public:
		
		TEST_METHOD(TestIsMoneyClass)
		{
			money m(0);
			Assert::IsTrue(std::is_class_v<money>);
			Assert::IsFalse(std::is_abstract_v<money>);
			Assert::IsTrue(std::is_same_v<money, decltype(m)>);
		}

		TEST_METHOD(TestMoneyInstance)
		{
			money m(5);
			Assert::AreEqual(5_EUR, m.get_value());
			Assert::AreEqual(5.23_EUR, m.add_value(0.23));
		}

		TEST_METHOD(TestMoneyConversion)
		{
			money n(1);
			Assert::AreEqual(7.53_HRK, n.convertToKn());
			Assert::AreEqual(1.08_USD, n.convertToUsd());
		}

		TEST_METHOD(TestAdditionOperator)
		{
			money m(5.35);
			auto a = m.get_value();
			auto ak = m.convertToKn();
			Assert::AreEqual(6.15_EUR, a += 0.80);
			Assert::AreEqual(46.33_HRK, ak += 0.80);
		}

		TEST_METHOD(TestCinOperator)
		{
			std::ostringstream ss;
			money m;
			ss << "5";
			Assert::AreEqual(5_EUR, m(ss));
		}

		TEST_METHOD(TestToString)
		{
			money ms(5.32);
			Assert::AreEqual("5 Eura, 32 Centa", ms.ToString());
			ms += 1.58;
			Assert::AreEqual("6 Eura, 90 Centa", ms.ToString());
		}
	};
}
