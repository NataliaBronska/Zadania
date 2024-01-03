#include "pch.h"
#include "CppUnitTest.h"
#include "../Project32/dd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:
		
		

        TEST_METHOD(TestCzyUpowazniony)
        {
            //poprawne has³o
            stringstream input_stream("123");
            cin.rdbuf(input_stream.rdbuf());

            Assert::IsTrue(czy_upowazniony());

            //niepoprawne has³o
            stringstream input_stream2("456");
            cin.rdbuf(input_stream2.rdbuf());

            Assert::IsFalse(czy_upowazniony());
        }

        TEST_METHOD(TestZapiszDaneCennikaDoPliku)
        {
            const string nazwa_pliku = "test_zapis.txt";
            vector<Cennik> uslugi = { {"Test1", "Opis Testu 1", "50.00"}, {"Test2", "Opis Testu 2", "75.00"} };

            zapiszDaneCennikaDoPliku(nazwa_pliku, uslugi);

            vector<Cennik> c = wczytajDaneCennika(nazwa_pliku);
            Assert::AreEqual(static_cast<size_t>(2), c.size());
        }
        TEST_METHOD(TestWyswietlDaneCennika)
        {
            Cennik cennik = { "Test", "Opis Testu", "100.00" };

            //standardowe wyjœcie
            stringstream output_stream;
            streambuf* old_cout = cout.rdbuf();
            cout.rdbuf(output_stream.rdbuf());

          
            wyswietlDaneCennika(cennik);

            // Przywrócenie standardowego wyjœcia
            cout.rdbuf(old_cout);

            
            Assert::IsTrue(output_stream.str().find("Usluga: Test") != string::npos);
            Assert::IsTrue(output_stream.str().find("Opis uslugi: Opis Testu") != string::npos);
            Assert::IsTrue(output_stream.str().find("Cena: 100.00") != string::npos);
        }

        TEST_METHOD(TestWyswietlListeUslug)
        {
            vector<Cennik> uslugi = { {"Test1", "Opis Testu 1", "50.00"}, {"Test2", "Opis Testu 2", "75.00"} };

          
            stringstream output_stream;
            streambuf* old_cout = cout.rdbuf();
            cout.rdbuf(output_stream.rdbuf());
           
            wyswietlListeUslug(uslugi);

            cout.rdbuf(old_cout);

            Assert::IsTrue(output_stream.str().find("1. Test1") != string::npos);
            Assert::IsTrue(output_stream.str().find("2. Test2") != string::npos);
        }

       
	};
}
