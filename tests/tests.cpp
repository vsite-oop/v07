#include "CppUnitTest.h"
#include "../app/money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace tests
{
	TEST_CLASS(tests)
	{
	public:

		TEST_METHOD(TestInstantiate) 
		{
			money m1(1, 99);
			Assert::AreEqual(199, m1.get_total_cents());

			money m2(-124, -12);
			Assert::AreEqual(-12412, m2.get_total_cents());

			money m3(0, -12);
			Assert::AreEqual(-12, m3.get_total_cents());
		}
		
		TEST_METHOD(TestOwerflow)
		{
			money m1(3, 150);
			Assert::AreEqual(450, m1.get_total_cents());


			money m3(-1, 250);
			Assert::AreEqual(150, m3.get_total_cents());
		}

		TEST_METHOD(TestUnderflow)
		{
			money m1(-1, -250);
			Assert::AreEqual(-350, m1.get_total_cents());

		}

		TEST_METHOD(TestAdd) {
			money m1(5, 12);
			money m2(2, 88);

			m1 += m2;
			Assert::AreEqual(800, m1.get_total_cents());
		}

		TEST_METHOD(TestSubtract) {
			money m1(5, 12);
			money m2(2, 88);

			m1 -= m2;
			Assert::AreEqual(224, m1.get_total_cents());
		}

		TEST_METHOD(TestStreamOperatorInput) {
			money m1;
			std::istringstream input("2 152");

			input >> m1;

			Assert::AreEqual(352, m1.get_total_cents());
		}

		TEST_METHOD(TestOutputBoth) {
			money m1(12, 12);

			std::ostringstream output1;

			output1 << m1;

			Assert::AreEqual(std::string("12 eur, 12 cent"), output1.str());
		}

		TEST_METHOD(TestOutputCents) {
			money m1(0, 2);

			std::ostringstream output1;

			output1 << m1;

			Assert::AreEqual(std::string("02 cent"), output1.str());
		}

		TEST_METHOD(TestOutputEur) {
			money m1(2, 0);

			std::ostringstream output1;

			output1 << m1;

			Assert::AreEqual(std::string("2 eur"), output1.str());
		}

		TEST_METHOD(TestStreamOperatorsIntegration) {
			money m1;
			std::istringstream input("+ 6 80\n+ 7 20\n+ 12 40\n- 5 50\n+ 10 15\n");
			std::ostringstream output;

			char op;
			money total;
			while (input >> op >> m1) {
				if (op == '+') total += m1;
				else if (op == '-') total -= m1;
			}
			output << total;

			Assert::AreEqual(std::string("31 eur, 05 cent"), output.str());
		}
	};
}
