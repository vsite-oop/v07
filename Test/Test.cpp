#include "../app/money.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

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


		TEST_METHOD(Test_Subtraction_Under_100) {
			money M(4, 17);
			M -= money(1, 33);
			Assert::AreEqual(2, M.get_kn());
			Assert::AreEqual(84, M.get_lp());
		}

		TEST_METHOD(Test_Subtraction_In_Minus) {
			money M(4, 17);
			M -= money(7, 13);
			Assert::AreEqual(-3, M.get_kn());
			Assert::AreEqual(4, M.get_lp());
		}

		TEST_METHOD(Test_Subtraction_Over_100) {
			money M(4, 17);
			Assert::AreEqual(4, M.get_kn());
			Assert::AreEqual(17, M.get_lp());
			M -= money(0, 83);
			Assert::AreEqual(3, M.get_kn());
			Assert::AreEqual(34, M.get_lp());
		}

		TEST_METHOD(Test_ConvertOperator) {
			money m(7, 53);
			Assert::AreEqual(1_EUR, m.to_eur());
			m -= money(0, 57);
			Assert::AreEqual(1_USD, m.to_usd());
		}

		TEST_METHOD(Test_ToString) {
			std::stringstream ss;
			money m(3, 12);
			ss << m;
			Assert::AreEqual("3 kn, 12 lp"s, ss.str());
		}
	};
}