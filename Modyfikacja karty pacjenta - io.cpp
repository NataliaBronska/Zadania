#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Pacjent {
    string imie_i_nazwisko;
    string data_urodzenia;
    string plec;
    string numer_telefonu;
    string historia_chorob;
    string aktualne_schorzenia;
    string wyniki_badan;
    string terapie_stomatologiczne;
};

vector<Pacjent> wczytajDanePacjentow(const string& nazwa_pliku) {
    vector<Pacjent> pacjenci;
    ifstream plik(nazwa_pliku);
    if (!plik.is_open()) {
        cerr << "Nie mozna otworzyc pliku: " << nazwa_pliku << endl;
        return pacjenci;
    }

    string linia;
    Pacjent pacjent;

    while (getline(plik, linia)) {
        istringstream linia_strumien(linia);
        string klucz;
        string wartosc;

        getline(linia_strumien, klucz, ':');
        getline(linia_strumien, wartosc);

        if (klucz == "Imie i nazwisko pacjenta") {
            if (!pacjent.imie_i_nazwisko.empty()) {
                pacjenci.push_back(pacjent);
            }
            pacjent = Pacjent();
            pacjent.imie_i_nazwisko = wartosc;
        }
        else if (klucz == "Data urodzenia") {
            pacjent.data_urodzenia = wartosc;
        }
        else if (klucz == "Plec") {
            pacjent.plec = wartosc;
        }
        else if (klucz == "Numer telefonu") {
            pacjent.numer_telefonu = wartosc;
        }
        else if (klucz == "Historia chorob stomatologicznych") {
            pacjent.historia_chorob = wartosc;
        }
        else if (klucz == "Aktualne schorzenia i diagnozy") {
            pacjent.aktualne_schorzenia = wartosc;
        }
        else if (klucz == "Wyniki badan stomatologicznych") {
            pacjent.wyniki_badan = wartosc;
        }
        else if (klucz == "Przeszle i obecne terapie stomatologiczne") {
            pacjent.terapie_stomatologiczne = wartosc;
        }
    }

    if (!pacjent.imie_i_nazwisko.empty()) {
        pacjenci.push_back(pacjent);
    }

    plik.close();
    return pacjenci;
}

bool czy_upowazniony()
{
    string wprowadzone_haslo;
    cout << "Podaj haslo: ";
    cin >> wprowadzone_haslo;

    if (wprowadzone_haslo == "123") {
        cout << "Akceptacja, mozesz modyfikowac karte pacjenta" << endl;
        return true;
    }
    else {
        cout << "Niepoprawne haslo, nie mozesz modyfikowac karty pacjenta" << endl;
        return false;
    }
}

void wyswietlListePacjentow(const vector<Pacjent>& pacjenci) {
    cout << "Lista pacjentow:" << endl;
    for (size_t i = 0; i < pacjenci.size(); i++) {
        cout << i + 1 << ". " << pacjenci[i].imie_i_nazwisko << endl;
    }
}
void wyswietlDanePacjenta(const Pacjent& pacjent) {
    cout << "Dane pacjenta:" << endl;
    cout << "Imie i nazwisko: " << pacjent.imie_i_nazwisko << endl;
    cout << "Data urodzenia: " << pacjent.data_urodzenia << endl;
    cout << "Plec: " << pacjent.plec << endl;
    cout << "Numer telefonu: " << pacjent.numer_telefonu << endl;
    cout << "Historia chorob: " << pacjent.historia_chorob << endl;
    cout << "Aktualne schorzenia: " << pacjent.aktualne_schorzenia << endl;
    cout << "Wyniki badan: " << pacjent.wyniki_badan << endl;
    cout << "Terapie stomatologiczne: " << pacjent.terapie_stomatologiczne << endl;
}
void modyfikujKartePacjenta(vector<Pacjent>& pacjenci, int indeks) {
    if (indeks >= 1 && indeks <= pacjenci.size()) {
        Pacjent& pacjent = pacjenci[indeks - 1];

        // Tutaj dodajesz logikê modyfikacji karty pacjenta.
        // Mo¿esz u¿yæ podobnego switch case, jak w poprzednich przyk³adach.

        cout << "Modyfikacja karty pacjenta:" << endl;
        cout << "1. Zmien imie i nazwisko" << endl;
        cout << "2. Zmien date urodzenia" << endl;
        cout << "3. Zmien plec" << endl;
        cout << "4. Zmien numer telefonu" << endl;
        cout << "5. Zmien historie chorob" << endl;
        cout << "6. Zmien aktualne schorzenia" << endl;
        cout << "7. Zmien terapie stomatologiczne" << endl;
        // Dodaj inne opcje modyfikacji...

        int wybor;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
        case 1:
            cout << "Nowe imie i nazwisko: ";
            cin.ignore();
            getline(cin, pacjent.imie_i_nazwisko);
            break;
        case 2:
            cout << "Nowa data urodzenia: ";
            cin.ignore();
            getline(cin, pacjent.data_urodzenia);
            break;
        case 3:
            cout << "Nowa plec: ";
            cin.ignore();
            getline(cin, pacjent.plec);
            break;
        case 4:
            cout << "Nowy numer telefonu: ";
            cin.ignore();
            getline(cin, pacjent.numer_telefonu);
            break;
        case 5:
            cout << "Nowa historia chorob: ";
            cin.ignore();
            getline(cin, pacjent.historia_chorob);
            break;
        case 6:
            cout << "Nowe aktualne schorzenia: ";
            cin.ignore();
            getline(cin, pacjent.aktualne_schorzenia);
            break;
        case 7:
            cout << "Nowe terapie stomatologiczne: ";
            cin.ignore();
            getline(cin, pacjent.terapie_stomatologiczne);
            break;
        default:
            cout << "Niepoprawny wybor." << endl;
        }
    }
    else {
        cout << "Niepoprawny indeks pacjenta." << endl;
    }
}
void zapiszDanePacjentowDoPliku(const string& nazwa_pliku, const vector<Pacjent>& pacjenci) {
    ofstream plik(nazwa_pliku);

    if (plik.is_open()) {
        for (const Pacjent& pacjent : pacjenci) {
            plik << "Imie i nazwisko pacjenta:" << pacjent.imie_i_nazwisko << endl;
            plik << "Data urodzenia:" << pacjent.data_urodzenia << endl;
            plik << "Plec:" << pacjent.plec << endl;
            plik << "Numer telefonu:" << pacjent.numer_telefonu << endl;
            plik << "Historia chorob stomatologicznych:" << pacjent.historia_chorob << endl;
            plik << "Aktualne schorzenia i diagnozy:" << pacjent.aktualne_schorzenia << endl;
            plik << "Wyniki badan stomatologicznych:" << pacjent.wyniki_badan << endl;
            plik << "Przeszle i obecne terapie stomatologiczne:" << pacjent.terapie_stomatologiczne << endl;
            plik << endl;
        }

        plik.close();
        cout << "Zmodyfikowane dane pacjentow zostaly zapisane do pliku." << endl;
    }
    else {
        cerr << "Nie mozna otworzyc pliku do zapisu: " << nazwa_pliku << endl;
    }
}
void obslugaKartyPacjenta(vector<Pacjent>& pacjenci, const string& nazwa_pliku) {
    if (czy_upowazniony()) {
        wyswietlListePacjentow(pacjenci);

        int indeks_pacjenta;
        cout << "Podaj indeks pacjenta do wyœwietlenia danych: ";
        cin >> indeks_pacjenta;

        if (indeks_pacjenta >= 1 && indeks_pacjenta <= pacjenci.size()) {
            wyswietlDanePacjenta(pacjenci[indeks_pacjenta - 1]);

            cout << "Czy chcesz modyfikowaæ kartê pacjenta? (T/N): ";
            char wybor;
            cin >> wybor;

            if (wybor == 'T' || wybor == 't') {
                modyfikujKartePacjenta(pacjenci, indeks_pacjenta);
                zapiszDanePacjentowDoPliku(nazwa_pliku, pacjenci);
            }
        }
        else {
            cout << "Niepoprawny indeks pacjenta." << endl;
        }
    }
}

int main() {
 
    const string nazwa_pliku = "C:\\Users\\natal\\OneDrive\\Pulpit\\Karta_pacjenta.txt";
    vector<Pacjent> pacjenci = wczytajDanePacjentow(nazwa_pliku);

    obslugaKartyPacjenta(pacjenci, nazwa_pliku);
    return 0;
}