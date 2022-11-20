#include "CppUnitTest.h"
#include "../app/app.h"

#include <type_traits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;
using namespace std::string_literals;

namespace all_tests
{
	TEST_CLASS(test_v07) 
	{
	public:

		TEST_METHOD(test_template_min)
		{
			Assert::AreEqual(12, minimum(12, 13));
			Assert::AreEqual(12u, minimum(12u, 13u));
			Assert::AreEqual(-10, minimum(-10, -5));
			Assert::AreEqual(3.5, minimum(3.5, 4.6));
			Assert::AreEqual(-4.56f, minimum(-1.23f, -4.56f));
			Assert::AreEqual("abc"s, minimum("abc"s, "de"s));
			Assert::AreEqual("DEF"s, minimum("DEF"s, "ab"s));
		}
		TEST_METHOD(test_template_array)
		{
			{
				fixed_array<int, 10> ar;
				Assert::AreEqual(10ull, ar.size());
				auto val = ar[0];
				Assert::IsTrue(std::is_same_v<int, decltype(val)>);
			}
			{
				fixed_array<double, 20> ar;
				Assert::AreEqual(20ull, ar.size());
				auto val = ar[1];
				Assert::IsTrue(std::is_same_v<double, decltype(val)>);
			}
			{
				fixed_array<point<double>, 30> ar;
				Assert::AreEqual(30ull, ar.size());
				auto val = ar[2];
				Assert::IsTrue(std::is_same_v<point<double>, decltype(val)>);
			}
		}
	};
}
