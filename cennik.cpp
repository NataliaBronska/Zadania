#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Cennik {
    string usluga;
    string opis_uslugi;
    string cena;
};

vector<Cennik> wczytajDaneCennika(const string& nazwa_pliku)
{
    vector<Cennik> cennik1;
    ifstream plik(nazwa_pliku);
    if (!plik.is_open()) {
        cerr << "Nie mozna otworzyc pliku: " << nazwa_pliku << endl;
        return cennik1;
    }

    string linia;
    Cennik c;
    while (getline(plik, linia)) {
        istringstream linia_strumien(linia);
        string klucz;
        string wartosc;

        getline(linia_strumien, klucz, ':');
        getline(linia_strumien, wartosc);

        if (klucz == "Usluga") {
            if (!c.usluga.empty()) {
                cennik1.push_back(c);
            }
            c = Cennik();
            c.usluga = wartosc;
        }
        else if (klucz == "Opis uslugi") {
            c.opis_uslugi = wartosc;
        }
        else if (klucz == "Cena") {
            c.cena = wartosc;
        }
    }

    if (!c.usluga.empty()) {
        cennik1.push_back(c);
    }

    plik.close();
    return cennik1;
}

void wyswietlListeUslug(const vector<Cennik>& uslugi) {
    cout << "Lista uslug:" << endl;
    for (size_t i = 0; i < uslugi.size(); i++) {
        cout << i + 1 << ". " << uslugi[i].usluga << endl;
    }
}

void wyswietlDaneCennika(const Cennik& c) {
    cout <<" Cennik: " << endl;
    cout << "Usluga: " << c.usluga << endl;
    cout << "Opis uslugi: " << c.opis_uslugi << endl;
    cout << "Cena: " << c.cena << endl;
}


void modyfikujCennik(vector<Cennik>& uslugi, int indeks) {
    if (indeks >= 1 && indeks <= uslugi.size()) {
        Cennik& usluga = uslugi[indeks - 1];


        cout << "Modyfikacja cennika:" << endl;
        cout << "1. Zmien usluge" << endl;
        cout << "2. Zmien opis uslugi" << endl;
        cout << "2. Zmien cene uslugi" << endl;
      
        int wybor;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
        case 1:
            cout << "Nowe nazwa uslugi: ";
            cin.ignore();
            getline(cin, usluga.usluga);
            break;
        case 2:
            cout << "Nowy opis uslugi: ";
            cin.ignore();
            getline(cin, usluga.opis_uslugi);
            break;
        default:
            cout << "Niepoprawny wybor." << endl;
        }
    }
    else {
        cout << "Niepoprawny indeks uslugi." << endl;
    }
}

void zapiszDaneCennikaDoPliku(const string& nazwa_pliku, const vector<Cennik>& uslugi) {
    ofstream plik(nazwa_pliku);

    if (plik.is_open()) {
        for (const Cennik& usluga : uslugi) {
            plik << "Usluga:" << usluga.usluga << endl;
            plik << "Opis uslugi:" << usluga.opis_uslugi << endl;
            plik << "Cena uslugi:" << usluga.cena << endl;
            plik << endl;
        }

        plik.close();
        cout << "Zmodyfikowane dane cennika zostaly zapisane do pliku." << endl;
    }
    else {
        cerr << "Nie mozna otworzyc pliku do zapisu: " << nazwa_pliku << endl;
    }
}

bool czy_upowazniony()
{
    string wprowadzone_haslo;
    cout << "Podaj haslo: ";
    cin >> wprowadzone_haslo;

    if (wprowadzone_haslo == "123") {
        cout << "Akceptacja, mozesz modyfikowac cennik" << endl;
        return true;
    }
    else {
        cout << "Niepoprawne haslo, nie mozesz modyfikowac cennika" << endl;
        return false;
    }
}

void obslugaCennika(vector<Cennik>& uslugi, const string& nazwa_pliku) {
    if (czy_upowazniony()) {
        wyswietlListeUslug(uslugi);
        int indeks_uslugi;
        cout << "Podaj indeks pacjenta do wy�wietlenia danych: ";
        cin >> indeks_uslugi;

        if (indeks_uslugi >= 1 && indeks_uslugi <= uslugi.size()) {
            wyswietlDaneCennika(uslugi[indeks_uslugi - 1]);

            cout << "Czy chcesz modyfikowa� cennik? (T/N): ";
            char wybor;
            cin >> wybor;

            if (wybor == 'T' || wybor == 't') {
                modyfikujCennik(uslugi, indeks_uslugi);
                zapiszDaneCennikaDoPliku(nazwa_pliku, uslugi);
            }
        }
        else {
            cout << "Niepoprawny indeks uslugi." << endl;
        }
    }
}
int main()
{
  
    const string nazwa_pliku = "csc:\\{S-1-5-21-2090416085-1661763139-3128312661-14389}\\KRYWAN\RedirectedUserFolders\\natbron2\\Pulpit\\cennik_plik.txt";
    vector<Cennik> c = wczytajDaneCennika(nazwa_pliku);

    obslugaCennika(c, nazwa_pliku);

    return 0;
}