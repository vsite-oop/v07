#include "pch.h"
#include "CppUnitTest.h"

#include "../app/money.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

//testovi za: overflow, underflow, ispis sa 0 kn, ispis sa 0 lp

namespace tests
{
	TEST_CLASS(test)
	{
	public:
		//
		//TEST_METHOD(default_constructor_initializes_to_zero)
		//{
		//	money m;
		//	Assert::AreEqual(0., m);
		//}

		//TEST_METHOD(constructor_with_one_argument)
		//{
		//	money m(10);
		//	Assert::AreEqual(10., m);
		//}

		//TEST_METHOD(constructor_with_two_arguments) {
		//	money m(10., 10.);
		//	Assert::AreEqual(10. 10., m);
		//}

		//TEST_METHOD(input_character) {
		//	//include iostream
		//	//inculte sstream
		//	void sest_input(std::istream& is) {
		//		int n; is >> n;

		//	}

		//	//u testu
		//	std::stringstream ss("123");
		//	test_input(ss);
		}
	};
}
