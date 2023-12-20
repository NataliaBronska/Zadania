#include <iostream>
#include "funkcja.h"

using namespace std;

int main()
{
	double liczba;
	cout << "Podaj liczbe: " << endl;
	cin >> liczba;
	cout << "Logarytm dziesietny z " << liczba << " to: " << logarytm_dziesietny(liczba) << endl;

	return (0);
}