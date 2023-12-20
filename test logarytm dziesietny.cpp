#include "pch.h"
#include "CppUnitTest.h"
#include"../logarytm dziesiętny/funkcja.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testlogarytmdziesietny
{
	TEST_CLASS(testlogarytmdziesietny)
	{
	public:

		TEST_METHOD(liczba_ujemna)
		{

		
			Assert::IsTrue(std::isnan(logarytm_dziesietny(-5.0)));
		}

		TEST_METHOD(jedynka)
		{
			Assert::AreEqual(0.0, logarytm_dziesietny(1.0));
		}

		TEST_METHOD(duza_liczba)
		{
			Assert::AreEqual(6.0, logarytm_dziesietny(1.0e6));
		}
	};
}
