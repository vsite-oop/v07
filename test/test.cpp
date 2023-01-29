#include "pch.h"
#include "CppUnitTest.h"

#include "../app/money.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace tests
{
	TEST_CLASS(test)
	{
	public:
		
		TEST_METHOD(default_constructor_initializes_to_zero)
		{
			money m;
			Assert::AreEqual(0,m.kune());
			Assert::AreEqual(0, m.lipe());
		}

		TEST_METHOD(constructor_with_one_argument)
		{
			money m(10);
			Assert::AreEqual(10, m.kune());
			Assert::AreEqual(0, m.lipe());
		}

		TEST_METHOD(constructor_with_two_arguments)
		{
			money m(10, 10);
			Assert::AreEqual(10, m.kune());
			Assert::AreEqual(10, m.lipe());
		}

		TEST_METHOD(constructor_with_one_argument_negative_value)
		{
			money m(-10);
			Assert::AreEqual(-10, m.kune());
			Assert::AreEqual(0, m.lipe());
		}

		TEST_METHOD(constructor_with_two_argument_negative_value)
		{
			money m(-10,15);
			Assert::AreEqual(-10, m.kune());
			Assert::AreEqual(15, m.lipe());
		}

		TEST_METHOD(output_not_initialized) {
			std::stringstream ss;
			money m;
			ss << m;
			
			Assert::AreEqual("0 kn", ss.str().c_str());
		}

		TEST_METHOD(output_one_argument_initialized) {
			std::stringstream ss;
			money m(10);
			ss << m;

			Assert::AreEqual("10 kn", ss.str().c_str());
		}

		TEST_METHOD(output_two_arguments_initialized) {
			std::stringstream ss;
			money m(10,10);
			ss << m;

			Assert::AreEqual("10 kn, 10 lp", ss.str().c_str());
		}

		TEST_METHOD(output_two_arguments_initialized_lipe) {
			std::stringstream ss;
			money m(0, 10);
			ss << m;

			Assert::AreEqual("10 lp", ss.str().c_str());
		}

		TEST_METHOD(adding) {
			money m(10);

			m += money(10, 10);
			Assert::AreEqual(20, m.kune());
			Assert::AreEqual(10, m.lipe());
		}

		TEST_METHOD(subtraction) {
			money m(20, 20);

			m -= money(10);
			Assert::AreEqual(10, m.kune());
			Assert::AreEqual(20, m.lipe());
		}

		TEST_METHOD(overflow) {
			money m(0, 70);

			m += money(0, 50);
			Assert::AreEqual(1, m.kune());
			Assert::AreEqual(20, m.lipe());
		}

		TEST_METHOD(underflow) {
			money m(5, 20);

			m -= money(0, 50);
			Assert::AreEqual(4, m.kune());
			Assert::AreEqual(70, m.lipe());
		}


		TEST_METHOD(example) {
			std::stringstream ss;
			money m;

			m += money(6, 80);
			m += money(7, 20);
			m += money(12, 40);
			m -= money(5, 50);
			m += money(10, 15);

			ss << m;

			Assert::AreEqual("31 kn, 05 lp", ss.str().c_str());
		}


	};
}
