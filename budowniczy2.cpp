#include <iostream>
using namespace std;
class Cennik {
public:
    void setUsluga(const string& usluga) {
        usluga_ = usluga;
    }
    void setOpis_Uslugi(const string& opis_uslugi) {
        opis_uslugi_ = opis_uslugi;
    }
    void setCena(const string& cena) {
        cena_ = cena;
    }
    
    void display() {
       cout << "Usluga: " << usluga_ << endl;
       cout << "Opis uslugi: " << opis_uslugi_ <<endl;
       cout << "Cena: " << cena_ << endl;
    }
private:
   string usluga_;
   string opis_uslugi_;
   string cena_;
};
class CennikBuilder {
public:
    virtual void buildUsluga(const string& usluga) = 0;
    virtual void buildOpis_Uslugi(const string& opis_uslugi) = 0;
    virtual void buildCena(const string& cena) = 0;
    virtual Cennik getResult() = 0;
};

class Cennik_stomatologiczny_Builder : public CennikBuilder {
public:
    Cennik_stomatologiczny_Builder() {
        cennik_ = Cennik();
    }
    void buildUsluga(const string& usluga) override {
        cennik_.setUsluga(usluga);
    }
    void buildOpis_Uslugi(const string& opis_uslugi) override {
        cennik_.setOpis_Uslugi(opis_uslugi);
    }
    void buildCena(const string& cena) override {
        cennik_.setCena(cena);
    }
    Cennik getResult() override {
        return cennik_;
    }
private:
    Cennik cennik_;
};

class Usluga_cennika1 {
public:
	Cennik usluga_cennika(CennikBuilder& builder) {
		builder.buildUsluga("Ekstrakcja Osemki");
		builder.buildOpis_Uslugi("Usuniecie osemki");
		builder.buildCena("500 zl");
		return builder.getResult();
	}
};

class Usluga_cennika2 {
public:
    Cennik usluga_cennika(CennikBuilder& builder) {
        builder.buildUsluga("Zalozenie plomby");
        builder.buildOpis_Uslugi("--------------");
        builder.buildCena("300 zl");
        return builder.getResult();
    }
};
int main()
{
    Cennik_stomatologiczny_Builder uslugaBuilder;
    Usluga_cennika1 usluga_cennika;
    Cennik c = usluga_cennika.usluga_cennika(uslugaBuilder);
    cout << "Usluga cennika:" << endl;
    c.display();
    
    Cennik_stomatologiczny_Builder uslugaBuilder2;
    Usluga_cennika2 usluga_cennika2;
    Cennik c2 = usluga_cennika2.usluga_cennika(uslugaBuilder2);
    cout << "\nUsluga cennika:" << endl;
    c2.display();

    return 0;
}