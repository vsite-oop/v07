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
			std::string test_string = "0 kn, 00 lp";
			Assert::AreEqual(test_string, ss.str());
		}

		TEST_METHOD(money_parametered_init_test)
		{
			uint32_t k{ 2 }, l{ 5 };
			money m(k, l);
			std::string test_string = std::format("{} kn, {:0>2} lp", k, l);
			ss << m;
			Assert::AreEqual(test_string, ss.str());
		}

		TEST_METHOD(money_add_operations_test)
		{
			money m{ 0 }, n{8, 90};
			std::string test_string1 = "8 kn, 90 lp";
			m += n;
			ss << m;
			Assert::AreEqual(test_string1, ss.str());
		}

		TEST_METHOD(money_add_operations_zero_test)
		{
			money m{ 0 }, n{ 0 };
			m += n;
			std::string test_string1 = "0 kn, 00 lp";
			ss << m;
			Assert::AreEqual(test_string1, ss.str());
		}

		TEST_METHOD(money_add_operations_overflow_test)
		{
			money m{ 2, 30 }, n{ 8, 90 };
			std::string test_string1 = "11 kn, 20 lp";
			m += n;
			ss << m;
			Assert::AreEqual(test_string1, ss.str());
		}

		TEST_METHOD(money_deduct_operations_test)
		{
			money m{ 1, 50 }, n{ 0, 10 };
			m -= n;
			ss << m;
			std::string test_string1 = "0 kn, 00 lp";
			std::string test_string2 = "1 kn, 40 lp";
			Assert::AreNotEqual(test_string1, ss.str());
			Assert::AreEqual(test_string2, ss.str());
		}

		TEST_METHOD(money_deduct_operations_zero_test)
		{
			money m{ 0 }, n{ 0, 0 };
			m -= n;
			ss << m;
			std::string test_string = "0 kn, 00 lp";
			Assert::AreEqual(test_string, ss.str());
		}

		TEST_METHOD(money_deduct_operations_underflow_test)
		{
			money m{ 1, 50 }, n{ 5 };
			m -= n;
			ss << m;
			std::string test_string1 = "-3 kn, 50 lp";
			std::string test_string2 = "0 kn, 00 lp";
			Assert::AreNotEqual(test_string1, ss.str());
			Assert::AreEqual(test_string2, ss.str());
		}
	};
}
