#include "CppUnitTest.h"
#include "../app/money.h"

#include <type_traits>
#include <iostream>
#include <format>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace v07unittests
{
	TEST_CLASS(v07unittests)
	{
	public:
		std::stringstream ss;
		TEST_METHOD(money_default_init_test)
		{
			money m{};
			ss << m;
			Assert::AreEqual("No cash", ss.str().c_str());
		}

		TEST_METHOD(money_parametered_init_test)
		{
			uint32_t k{ 2 }, l{ 5 };
			money m(k, l);
			ss << m;
			Assert::AreEqual("2 kn, 05 lp", ss.str().c_str());
		}

		TEST_METHOD(money_output_full_test)
		{
			money m{ 6, 66 };
			ss << m;
			Assert::AreEqual("6 kn, 66 lp", ss.str().c_str());
		}

		TEST_METHOD(money_output_kune_test)
		{
			money m{ 6 };
			ss << m;
			Assert::AreEqual("6 kn", ss.str().c_str());
		}

		TEST_METHOD(money_output_lipe_test)
		{
			money m{ 0, 66 };
			ss << m;
			Assert::AreEqual("66 lp", ss.str().c_str());
		}

		TEST_METHOD(money_add_operations_test)
		{
			money m{ 0 }, n{8, 90};
			m += n;
			ss << m;
			Assert::AreEqual("8 kn, 90 lp", ss.str().c_str());
		}

		TEST_METHOD(money_add_operations_zero_test)
		{
			money m{ 0 }, n{ 0 };
			m += n;
			ss << m;
			Assert::AreEqual("No cash", ss.str().c_str());
		}

		TEST_METHOD(money_add_operations_overflow_test)
		{
			money m{ 2, 30 }, n{ 8, 90 };
			m += n;
			ss << m;
			Assert::AreEqual("11 kn, 20 lp", ss.str().c_str());
		}

		TEST_METHOD(money_deduct_operations_test)
		{
			money m{ 1, 50 }, n{ 0, 10 };
			m -= n;
			ss << m;
			Assert::AreEqual("1 kn, 40 lp", ss.str().c_str());
		}

		TEST_METHOD(money_deduct_operations_zero_test)
		{
			money m{ 2 }, n{ 0, 0 };
			m -= n;
			ss << m;
			Assert::AreEqual("2 kn", ss.str().c_str());
		}

		TEST_METHOD(money_deduct_operations_underflow_test)
		{
			money m{ 1, 50 }, n{ 5 };
			m -= n;
			ss << m;
			Assert::AreEqual("No cash", ss.str().c_str());
		}
	};
}
