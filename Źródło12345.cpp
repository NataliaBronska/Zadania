/*#include <iostream>
using namespace std;
int main()
{
    int AA[10];

    
    cout << "Wprowadz 10 liczb:\n";
    for (int i = 0; i < 10; i++) 
    {
        cout << "Liczba " << i + 1 << "  ";
        cin >> AA[i];
    }

    
    cout << "Liczby, ktore wprowadziles to:\n";
    for (int i = 0; i < 10; i++) 
    {
        cout << AA[i] << " ";
    }
    int* BB = new int[10];
    int ilosc_ujemnych=0;
    int  j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (AA[i] < 0)
        {
            ilosc_ujemnych++;
            AA[i] = BB[j];
            j++;
        }
    }

    cout << "ujemne liczby to:";
    for (int y = 0; y < ilosc_ujemnych; y++)
    {
        cout << BB[y] << endl;
    }
    delete[] BB;
	return 0;
}*/

#include <iostream>
using namespace std;

int main() {
    int AA[10];

    cout << "WprowadŸ 10 liczb:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Liczba " << i + 1 << ": ";
        cin >> AA[i];
    }

    cout << "Liczby, które wprowadzi³eœ to:\n";
    for (int i = 0; i < 10; i++) {
        cout << AA[i] << " ";
    }

    int* BB = new int[10];
    int ilosc_ujemnych = 0;

    for (int i = 0; i < 10; i++) {
        if (AA[i] < 0) {
            BB[ilosc_ujemnych] = AA[i];  
            ilosc_ujemnych++;
        }
    }

    if (ilosc_ujemnych > 0) {
        cout << "\nUjemne liczby to:";
        for (int y = 0; y < ilosc_ujemnych; y++) {
            cout << " " << BB[y];
        }
        cout << endl;
    }
    else {
        cout << "\nBrak ujemnych liczb." << endl;
    }

    delete[] BB;  
    return 0;
}