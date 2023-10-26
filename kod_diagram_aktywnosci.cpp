#include<iostream>
#include<fstream>
using namespace std;
struct Karta_pacjenta 
{
	string imie_nazwisko;
	int wiek;
	string diagnoza;
};
struct konto_uztkownika {
	string login;
	string haslo;
};

void modyfikacja(Karta_pacjenta& pacjent, const string& nowe_imie_nazwisko, int nowy_wiek, const string& nowa_diagnoza)
{
	pacjent.imie_nazwisko = nowe_imie_nazwisko;
	pacjent.wiek = nowy_wiek;
	pacjent.diagnoza = nowa_diagnoza;
}

void wyswietl()
{
	
}
int main()
{

	Karta_pacjenta p1;
	modyfikacja(p1, "Anna Kowalska", 12, "usuniecie osemki"); 
	ofstream output("dane.txt");
	if (output.is_open())
	{
		output << p1.imie_nazwisko << " " << p1.wiek << " " << p1.diagnoza;
			output.close();
			cout << "\nZaktualizowane dane uzytkownika";

	}
	else
	{
		cout << "Blad";
		return 1;

	}
		
	return 0;
}