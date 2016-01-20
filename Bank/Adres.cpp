#include <iostream>
#include <string>
#include "Tool.h"
#include "Adres.h"

using namespace std;

Adres::Adres():
  fUlica(""), fDom(""), fMieszkanie(0), fKod(0), fMiasto("//"), fKraj("POLSKA") 
{}


Adres::Adres(string Ulica, string Dom, int Mieszkanie, int Kod, string Miasto, string Kraj){
	this->setUlica(Ulica);
	this->setDom(Dom);
	this->setMieszkanie(Mieszkanie);
	this->setMiasto(Miasto);
	this->setKod(Kod);
	this->setKraj(Kraj);
}
	
// setter
void Adres::setUlica(string Ulica){ this->fUlica.assign(Ulica); }
void Adres::setDom(string Dom){ this->fDom = Dom; }
void Adres::setMieszkanie(int Mieszkanie){ this->fMieszkanie = Mieszkanie; }
void Adres::setMiasto(string Miasto){ this->fMiasto = Miasto; }
void Adres::setKod(int Kod){ this->fKod = Kod; }
void Adres::setKraj(string Kraj){ this->fKraj = Kraj; }

// getter
string Adres::getUlicaDom(){
	string Result = "";
	Result.append(this->fUlica) += " ";
	Result.append(this->fDom);

	if (this->fMieszkanie > 0)
		Result.append("/") += Tool::IntAsString(static_cast<long long> (this->fMieszkanie));

	return Result;
}

string Adres::getKodMiasto(){
	string Result;

	Result = this->getKod();
	Result.append(" ").append(this->fMiasto);

	return Result;
}

string Adres::getKraj(){
	return this->fKraj;
}

string Adres::getKod(){
	string Result;
	Result = Tool::IntAsString(static_cast<long long> (this->fKod));

	if (Result.length() < 5){
		string Lead = "";
		for (int i = 1; i< (5 -Result.length()); i++)
			Lead.append("0");
		Result = Lead + Result;
	}

	if (this->getKraj().compare("POLSKA") == 0)
		Result = Result.substr(0,2).append("-").append(Result.substr(2,3));

	return Result;
}

void Adres::uzupelnij(TrybEdycji trybEdycji){
	string _ulica;
	string _dom;
	int _mieszkanie;
	string _miasto;
	int _kod;
	string _kraj;

	// ulica
	if (trybEdycji == teZmiana) cout << "Ulica : " << this->fUlica << endl << "Nowa wartosc : ";
	cout << "Ulica: ";
	cin >> _ulica;
	if (_ulica.compare("") != 0) this->fUlica = _ulica;

	// dom
	if (trybEdycji == teZmiana) cout << "Numer domu : " << this->fDom << endl << "Nowa wartosc : ";
	cout << "Numer domu: ";
	cin >> _dom;
	if (_dom.compare("") != 0) this->fDom = _dom;

	// mieszkanie
	if (trybEdycji == teZmiana) cout << "Mieszkanie : " << this->fMieszkanie << endl << "Nowa wartosc : ";
	cout << "Mieszkanie: ";
	cin >> _mieszkanie;
	if (_mieszkanie != 0) this->fMieszkanie = _mieszkanie;

	// miasto
	if (trybEdycji == teZmiana) cout << "Miejscowosc : " << this->fMiasto << endl << "Nowa wartosc : ";
	cout << "Miejscowosc: ";
	cin >> _miasto;
	if (_miasto.compare("") != 0) this->fMiasto = _miasto;

	// kod pocztowy
	if (trybEdycji == teZmiana) cout << "Kod pocztowy : " << getKod() << endl << "Nowa wartosc : ";
	cout << "Kod pocztowy (bez kresek): ";
	cin >> _kod;
	if (_kod != 0) this->fKod = _kod;

	// kraj
	if (trybEdycji == teZmiana) cout << "Kraj : " << this->fKraj << endl << "Nowa wartosc : ";
	cout << "Kraj: ";
	cin >> _kraj;
	if (_kraj.compare("") != 0) this->fKraj = _kraj;
}

void Adres::nowyAdres(){ uzupelnij(teDodawanie); }

void Adres::zmienAdres(){ uzupelnij(teZmiana); }
