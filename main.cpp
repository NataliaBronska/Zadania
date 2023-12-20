#include <iostream>
#include "funkcje.h"
using namespace std;
int main()
{
	double x, y;
	cout << "Podaj 2 liczby: ";
	cin >> x >> y;
	cout << "Logarytm naturalny z pierwszej liczby to: " << logarytm_naturalny(x) << endl;
	cout << "Odchylenie standardowe z 2 podanych liczb wynosi: " << odchylenie_standardowe(x, y) << endl;
	cout << "Wartosc exponentu z pierwszej liczby to: " << exponent(x) << endl;
	return(0);

}