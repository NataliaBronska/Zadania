#include "pch.h"
#include "CppUnitTest.h"
#include "../kalkulator/funkcje.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testjednostkowy
{
	TEST_CLASS(testjednostkowy)
	{
	public:
		
		TEST_METHOD(test_logarytm)
		{
			Assert::AreEqual(0.0, logarytm_naturalny(1.0));
			Assert::IsTrue(std::isnan(logarytm_naturalny(-1.0)));
			Assert::AreEqual(2.30259, logarytm_naturalny(10.0), 0.00001);
		}
	};
}
