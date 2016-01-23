#pragma once
#include <iostream>
#include <string>
#include "Klient.h"
#include "Adres.h"
#include "Tool.h"

Klient::Klient(): imie(""), nazwisko(""), rodzaj(rkOsobaFizyczna), aktywny(true){
}

Klient::Klient(std::string Imie, std::string Nazwisko, RodzajKlienta Rodzaj): imie(Imie), nazwisko(Nazwisko), rodzaj(Rodzaj), aktywny(true)
{}

std::string Klient::opisRodzaju(){
	switch(this->rodzaj){
		case rkOsobaFizyczna: return "Osoba fizyczna"; break;
		case rkFirma: return "Firma"; break;
		case rkInstytucja: return "Instytucja"; break;
	}
	return "";
}

void Klient::uzupelnijDane(TrybEdycji trybEdycji){
	// typ klienta
	int unsigned wybor = 10;

	std::string _imie = this->imie;
	std::string _nazwisko = this->nazwisko;
	RodzajKlienta _rodzaj = this->rodzaj;

	while (wybor > 2){
		if (trybEdycji == teZmiana) cout << "Rodzaj klienta : " << opisRodzaju() << endl << "Nowa wartosc : ";
		std::cout << "Wskaz rodaj klienta: " << std::endl << "0. Osoba fizyczna " << std::endl << "1. Firma " << std::endl << "2. Instytucja " << std::endl << "Wybor : ";
		wybor = Tool::inputUInt();
	}

	_rodzaj = RodzajKlienta(wybor);

	switch (_rodzaj){
	case rkOsobaFizyczna :
		if (trybEdycji == teZmiana) cout << "Imie : " << this->imie << endl << "Nowa wartosc : ";
		std::cout << "Imie: ";
		_imie = Tool::inputString();
		if (_imie.compare("") != 0) this->imie = _imie;

		if (trybEdycji == teZmiana) cout << "Nazwisko : " << this->nazwisko << endl << "Nowa wartosc : ";
		std::cout << "Nazwisko: ";
		_nazwisko = Tool::inputString();
		if (_nazwisko.compare("") != 0) this->nazwisko = _nazwisko;
		break;

	case rkFirma:
		if (trybEdycji == teZmiana) cout << "Nazwa firmy : " << this->nazwisko << endl << "Nowa wartosc : ";
		std::cout << "Nazwa firmy: ";
		_nazwisko = Tool::inputString();
		if (_nazwisko.compare("") != 0) this->nazwisko = _nazwisko;
		break;

	case rkInstytucja:
		if (trybEdycji == teZmiana) cout << "Nazwa instytucji : " << this->nazwisko << endl << "Nowa wartosc : ";
		std::cout << "Nazwa instytucji: ";
		_nazwisko = Tool::inputString();
		if (_nazwisko.compare("") != 0) this->nazwisko = _nazwisko;
		break;
	}
}

void Klient::uzupelnijAdres(TrybEdycji trybEdycji){
	this->adres.uzupelnij(trybEdycji);
}

void Klient::aktywuj(bool aktywacja){
	this->aktywny = aktywacja;
}

std::string Klient::getHeadLine(){
	std::string hl = "";
	if (this->rodzaj == rkOsobaFizyczna){
		hl = this->imie;
		hl.append(" ");
	}
	hl.append(this->nazwisko);
	return hl;
}