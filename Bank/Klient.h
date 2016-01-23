#pragma once
#include <iostream>
#include "Adres.h"
#include "Parametry.h"

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

	std::string opisRodzaju();
public:
	Klient();
	Klient(std::string Imie, std::string Nazwisko, RodzajKlienta Rodzaj);
	void uzupelnijDane(TrybEdycji trybEdycji);
	void uzupelnijAdres(TrybEdycji trybEdycji);
	void aktywuj(bool aktywacja);
	std::string getHeadLine();
	std::string getInfo();
};