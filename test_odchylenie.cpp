#include "pch.h"
#include "CppUnitTest.h"
#include "../kalkulator/funkcje.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testodchylenie
{
	TEST_CLASS(testodchylenie)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1.0, odchylenie_standardowe(1.0, 1.0));
			Assert::AreEqual(3.53553, odchylenie_standardowe(3.0, 4.0), 0.00001);
		}
	};
}
