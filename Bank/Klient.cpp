#pragma once
#include <iostream>
#include "Klient.h"
#include "Adres.h"

Klient::Klient(): imie(""), nazwisko(""), rodzaj(rkOsobaFizyczna), aktywny(true){
}

Klient::Klient(std::string Imie, std::string Nazwisko, RodzajKlienta Rodzaj): imie(Imie), nazwisko(Nazwisko), rodzaj(Rodzaj), aktywny(true)
{}

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