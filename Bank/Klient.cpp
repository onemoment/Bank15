#pragma once
#include <iostream>
#include "Adres.h"

enum RodzajKlienta{
	rkOsobaFizyczna,
	rkFirma,
	rkInstytucja
};

class Klient{
	std::string imie;
	std::string nazwisko;
	RodzajKlienta rodzaj;
	Adres adres;
	bool aktywny;

public:
	Klient();
	Klient(std::string Imie, std::string Nazwisko, RodzajKlienta Rodzaj);
	void aktywuj(bool aktywacja);
};


Klient::Klient(): imie(""), nazwisko(""), rodzaj(rkOsobaFizyczna), aktywny(true){
}

Klient::Klient(std::string Imie, std::string Nazwisko, RodzajKlienta Rodzaj): imie(Imie), nazwisko(Nazwisko), rodzaj(Rodzaj), aktywny(true)
{}

void Klient::aktywuj(bool aktywacja){
	this->aktywny = aktywacja;
}