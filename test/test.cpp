#include "CppUnitTest.h"

#include "../app/money.h"

#include <string>;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace test
{
	TEST_CLASS(test)
	{
	public:

		TEST_METHOD(default_constructor_initializes_to_zero) {
			money m;
			Assert::AreEqual(0, m.get());
		}

		TEST_METHOD(constructor_initializes_to_zero) {
			money m(0);
			Assert::AreEqual(0, m.get());
		}

		TEST_METHOD(constructor_initializes_to_given_value) {
			money m(5);
			Assert::AreEqual(5, m.get());
		}

		TEST_METHOD(initialization_overflow) {
			money m(2147483648);
			Assert::AreEqual((int)2147483648, m.get());
		}

		TEST_METHOD(initialization_underflow) {
			money m(-2147483648);
			Assert::AreEqual((int)-2147483648, m.get());
		}

		TEST_METHOD(uninitialized_in_place_addition) {
			money m, n;
			m += n;
			Assert::AreEqual(0, m.get());
			n += m;
			Assert::AreEqual(0, n.get());
		}

		TEST_METHOD(zero_initialized_in_place_addition) {
			money m(0);
			money n(500);
			m += n;
			Assert::AreEqual(500, m.get());
			n += m;
			Assert::AreEqual(1000, n.get());
		}

		TEST_METHOD(non_zero_initialized_in_place_addition) {
			money m(139);
			money n(500);
			m += n;
			Assert::AreEqual(639, m.get());
			n += m;
			Assert::AreEqual(1139, n.get());
		}

		TEST_METHOD(overflowed_initialized_in_place_addition) {
			money m(1);
			money n(2147483647);
			m += n;
			Assert::AreEqual((int)-2147483648, m.get());
		}

		TEST_METHOD(uninitialized_in_place_subtraction) {
			money m, n;
			m -= n;
			Assert::AreEqual(0, m.get());
			n -= m;
			Assert::AreEqual(0, n.get());
		}

		TEST_METHOD(zero_initialized_in_place_subtraction) {
			money m(0);
			money n(500);
			m -= n;
			Assert::AreEqual(-500, m.get());
			n -= m;
			Assert::AreEqual(1000, n.get());
		}

		TEST_METHOD(non_zero_initialized_in_place_subtraction) {
			money m(500);
			money n(139);
			m -= n;
			Assert::AreEqual(361, m.get());
			n -= m;
			Assert::AreEqual(-222, n.get());
		}

		TEST_METHOD(underflowed_initialized_in_place_subtraction) {
			money m((int)-2147483648);
			money n(1);
			m -= n;
			Assert::AreEqual((int)2147483647, m.get());
		}

		TEST_METHOD(zero_initialized_input_output) {
			std::stringstream ss;
			money m;
			ss << m;
			Assert::AreEqual(ss.str(), (std::string)"0 kn, 00 lp");
		}

		TEST_METHOD(non_zero_initialized_input_output) {
			std::stringstream ss;
			money m(3105);
			ss << m;
			Assert::AreEqual(ss.str(), (std::string)"31 kn, 05 lp");
		}
	};
}
