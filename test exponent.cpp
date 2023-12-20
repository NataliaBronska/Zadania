#include "pch.h"
#include "CppUnitTest.h"
#include "../kalkulator/funkcje.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testexponent
{
	TEST_CLASS(testexponent)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1.0, exponent(0.0), 0.00001);
			Assert::AreEqual(0.36788, exponent(-1.0), 0.00001);
		}
	};
}
