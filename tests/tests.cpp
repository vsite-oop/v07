#include "CppUnitTest.h"
#include "../app/money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

namespace tests
{
	TEST_CLASS(tests)
	{
	public:

		TEST_METHOD(TestInstantiate) {

			money m1(1, 99);
			Assert::AreEqual(1.99, m1.get_total_amount(), 1e-2);

			money m2(-124, -12);
			Assert::AreEqual(-124.12, m2.get_total_amount(), 1e-2);

			money m3(0, -12);
			Assert::AreEqual(-0.12, m3.get_total_amount(), 1e-2);

		}
		
		TEST_METHOD(TestOwerflowAndUnderflow)
		{
			money m1(3, 150);
			Assert::AreEqual(4.50, m1.get_total_amount(), 1e-2);

			money m2(-1, -250);
			Assert::AreEqual(-3.50, m2.get_total_amount(), 1e-2);

			money m3(-1, 250);
			Assert::AreEqual(-3.50, m2.get_total_amount(), 1e-2);

		}

		TEST_METHOD(TestAddAndSubtract) {
			money m1(5, 12);
			money m2(2, 88);
			money m3(5, 12);

			m1 += m2;
			Assert::AreEqual(8.0, m1.get_total_amount(), 1e-2);

			m3 -= m2;
			Assert::AreEqual(2.24, m3.get_total_amount(), 1e-2);
		}

		TEST_METHOD(TestStreamOperators) {
			money m1;
			std::istringstream input("+ 6 80\n+ 7 20\n+ 12 40\n- 5 50\n+ 10 15\n");
			std::ostringstream output;

			// Simulate the input/output scenario
			char op;
			money total;
			while (input >> op >> m1) {
				if (op == '+') total += m1;
				else if (op == '-') total -= m1;
			}
			output << total;

			Assert::AreEqual(std::string("31 eur, 5 cent"), output.str());
		}
	};
}
