#include "CppUnitTest.h"
#include "..\app\money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::string_literals;
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



		TEST_METHOD(TestAdditionOperator)
		{
			money m(5, 35);
			money t(0, 80);
			m += t;
			Assert::AreEqual(615, m.get_value());
		}

		TEST_METHOD(TestToString)
		{
			std::stringstream ss;
			money ms(5, 32);
			ss << ms;
			Assert::AreEqual("5€ i 32 centa."s, ss.str());
			std::stringstream ssa;
			ms += money(1, 58);
			ssa << ms;
			Assert::AreEqual("6€ i 90 centa."s, ssa.str());
			std::stringstream ssb;
			ms -= money(1, 99);
			ssb << ms;
			Assert::AreEqual("4€ i 91 centa."s, ssb.str());
		}
    
		TEST_METHOD(TestMoneyInstance)
		{
			money m(5);
			Assert::AreEqual(500, m.get_value());
			m.add_value(0, 23);
			Assert::AreEqual(523, m.get_value());
		}
    
		TEST_METHOD(TestZeroEur)
		{
			std::stringstream ss;
			money m(0, 50);
			ss << m;
			Assert::AreEqual("50 centi."s, ss.str());
		}



		TEST_METHOD(TestZero)
		{
			std::stringstream ss;
			money m;
			ss << m;
			Assert::AreEqual("0 Eura."s, ss.str());
		}
    
    		TEST_METHOD(TestZeroCent)
		{
			std::stringstream ss;
			money m(5);
			ss << m;
			Assert::AreEqual("5 Eura."s, ss.str());
		}
	};
}
