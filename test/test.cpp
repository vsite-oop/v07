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
			std::stringstream ss;
			money m;
			ss << m;
			Assert::AreEqual("0 kn", ss.str().c_str());
		}

		TEST_METHOD(constructor_initializes_to_zero) {
			std::stringstream ss;
			money m(0);
			ss << m;
			Assert::AreEqual("0 kn", ss.str().c_str());
		}

		TEST_METHOD(constructor_initializes_to_given_value) {
			std::stringstream ss;
			money m(5);
			ss << m;
			Assert::AreEqual("05 lp", ss.str().c_str());
		}

		TEST_METHOD(uninitialized_in_place_addition) {
			std::stringstream ss;
			money m, n;
			m += n;
			ss << m;
			Assert::AreEqual("0 kn", ss.str().c_str());
			ss.str(std::string());  // Clear stringstream (stackoverflow)
			n += m;
			ss << n;
			Assert::AreEqual("0 kn", ss.str().c_str());
		}

		TEST_METHOD(zero_initialized_in_place_addition) {
			std::stringstream ss;
			money m(0);
			money n(500);
			m += n;
			ss << m;
			Assert::AreEqual("5 kn", ss.str().c_str());
			ss.str(std::string());
			n += m;
			ss << n;
			Assert::AreEqual("10 kn", ss.str().c_str());
		}

		TEST_METHOD(non_zero_initialized_in_place_addition) {
			std::stringstream ss;
			money m(139);
			money n(500);
			m += n;
			ss << m;
			Assert::AreEqual("6 kn, 39 lp", ss.str().c_str());
			ss.str(std::string());
			n += m;
			ss << n;
			Assert::AreEqual("11 kn, 39 lp", ss.str().c_str());
		}

		TEST_METHOD(uninitialized_in_place_subtraction) {
			std::stringstream ss;
			money m, n;
			m -= n;
			ss << m;
			Assert::AreEqual("0 kn", ss.str().c_str());
			ss.str(std::string());
			n -= m;
			ss << n;
			Assert::AreEqual("0 kn", ss.str().c_str());
		}

		TEST_METHOD(zero_initialized_in_place_subtraction) {
			std::stringstream ss;
			money m(0);
			money n(500);
			m -= n;
			ss << m;
			Assert::AreEqual("0 kn", ss.str().c_str());
			ss.str(std::string());
			n -= m;
			ss << n;
			Assert::AreEqual("5 kn", ss.str().c_str());
		}

		TEST_METHOD(non_zero_initialized_in_place_subtraction) {
			std::stringstream ss;
			money m(500);
			money n(139);
			m -= n;
			ss << m;
			Assert::AreEqual("3 kn, 61 lp", ss.str().c_str());
			ss.str(std::string());
			n -= m;
			ss << n;
			Assert::AreEqual("0 kn", ss.str().c_str());
		}

		TEST_METHOD(zero_initialized_input_output) {
			std::stringstream ss;
			money m;
			ss << m;
			Assert::AreEqual(ss.str().c_str(), "0 kn");
		}

		TEST_METHOD(non_zero_initialized_input_output) {
			std::stringstream ss;
			money m(3105);
			ss << m;
			Assert::AreEqual(ss.str().c_str(), "31 kn, 05 lp");
		}

		TEST_METHOD(double_digit_subsidiary_currency_only_initialized_input_output) {
			std::stringstream ss;
			money m(99);
			ss << m;
			Assert::AreEqual(ss.str().c_str(), "99 lp");
		}

		TEST_METHOD(single_digit_subsidiary_currency_only_initialized_input_output) {
			std::stringstream ss;
			money m(1);
			ss << m;
			Assert::AreEqual(ss.str().c_str(), "01 lp");
		}

		TEST_METHOD(input_output_stream_single_value) {
			/*Ovo iz nekog razloga ne radi ako koristim isti
			stringstream kojeg samo "pocistim" sa "ss.str(std::string)"
			ili "ss.str("")" prije nego napravim "ss << m", nego
			moram imati dva.*/
			std::stringstream ss1;
			money m;
			ss1 << 5;
			ss1 >> m;
			std::stringstream ss2;
			ss2 << m;
			Assert::AreEqual("5 kn", ss2.str().c_str());
		}

		TEST_METHOD(input_output_stream_both_values) {
			std::stringstream ss1;
			money m;
			ss1 << 5 << " " << 5;
			ss1 >> m;
			std::stringstream ss2;
			ss2 << m;
			Assert::AreEqual("5 kn, 05 lp", ss2.str().c_str());
		}
	};
}

/*For clearing the contents of a stringstream, using:

	m.str("");

is correct, although using:

	m.str(std::string());

is technically more efficient, because you avoid invoking the
std::string constructor that takes const char*. But any compiler these
days should be able to generate the same code in both cases - so I
would just go with whatever is more readable.*/
