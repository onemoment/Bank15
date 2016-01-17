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

public:
	Klient();
	Klient(std::string Imie, std::string Nazwisko, RodzajKlienta Rodzaj);
	void uzupelnijAdres(TrybEdycji trybEdycji);
	void aktywuj(bool aktywacja);
	std::string getHeadLine();
};