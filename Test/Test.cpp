#include "../app/money.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;
using namespace std::string_literals;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		
		TEST_METHOD(Test_MoneyClass)
		{
			Assert::IsFalse(std::is_abstract_v<money>);
			Assert::IsTrue(std::is_class_v<money>);
			money M;
			Assert::IsFalse(std::is_empty_v<money>);
			Assert::IsTrue(std::is_same_v<money, decltype(M)>);
		}

		TEST_METHOD(Test_Addition_Under_100) {
			money M(4, 17);
			Assert::AreEqual(4, M.get_kn());
			Assert::AreEqual(17, M.get_lp());
			M += money(1, 33);
			Assert::AreEqual(5, M.get_kn());
			Assert::AreEqual(50, M.get_lp());
		}

		TEST_METHOD(Test_Addition_Over_100) {
			money M(4, 17);
			M += money(14, 85);
			Assert::AreEqual(19, M.get_kn());
			Assert::AreEqual(2, M.get_lp());
		}

		TEST_METHOD(Test_Addition_exactly_100) {
			money M(4, 17);
			M += money(0, 83);
			Assert::AreEqual(5, M.get_kn());
			Assert::AreEqual(0, M.get_lp());
		}


		TEST_METHOD(Test_Subtraction_Over_0) {
			money M(4, 17);
			M -= money(1, 13);
			Assert::AreEqual(3, M.get_kn());
			Assert::AreEqual(4, M.get_lp());
		}

		TEST_METHOD(Test_Subtraction_In_Minus) {
			money M(4, 17);
			M -= money(7, 13);
			Assert::AreEqual(-3, M.get_kn());
			Assert::AreEqual(4, M.get_lp());
		}

		TEST_METHOD(Test_Subtraction_Under_0) {
			money M(4, 17);
			Assert::AreEqual(4, M.get_kn());
			Assert::AreEqual(17, M.get_lp());
			M -= money(0, 83);
			Assert::AreEqual(3, M.get_kn());
			Assert::AreEqual(34, M.get_lp());
		}

		TEST_METHOD(Test_ConvertOperator) {
			money m(7, 53);
			Assert::AreEqual(1., m.to_eur());
			m -= money(0, 55);
			Assert::AreEqual(1., m.to_usd());
		}

		TEST_METHOD(Test_ToString) {
			std::stringstream ss;
			money m(3, 12);
			ss << m;
			Assert::AreEqual("3 kn, 12 lp"s, ss.str());
		}

		TEST_METHOD(Test_ToString_0kn) {
			std::stringstream ss;
			money m(0, 50);
			ss << m;
			Assert::AreEqual("50 lp"s, ss.str());
		}

		TEST_METHOD(Test_ToString_0lp) {
			std::stringstream ss;
			money m(5);
			ss << m;
			Assert::AreEqual("5 kn"s, ss.str());
		}

		TEST_METHOD(Test_Over100lp) {
			std::stringstream ss;
			money m(3, 130);
			ss << m;
			Assert::AreEqual("4 kn, 30 lp"s, ss.str());
		}

		TEST_METHOD(Test_Zero) {
			std::stringstream ss;
			money m;
			ss << m;
			Assert::AreEqual("0 kn"s, ss.str());
		}
	};
}