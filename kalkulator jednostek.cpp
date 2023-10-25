#include <iostream>

using namespace std;

void kalkulator_jednostek(double kilometry, double& mile_ladowe, double& mile_morskie) 
{
    mile_ladowe = kilometry * 0.621371;  
    mile_morskie = kilometry * 0.539957;
}

int main() {
    double kilometry, mile_ladowe, mile_morskie;

    cout << "Podaj odleglosc (km): ";
    cin >> kilometry;

    kalkulator_jednostek(kilometry, mile_ladowe, mile_morskie);

    cout << kilometry << "km to " << mile_ladowe <<" mil ladowych" << endl;
    cout << kilometry << "km to " << mile_morskie << " mil morskich" << endl;
   

    return 0;
}