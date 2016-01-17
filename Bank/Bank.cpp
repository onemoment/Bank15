#include "Bank.h"

int Bank::sumaKontrolna(std::string numerKonta){
	int liczba;
	int suma = 0;
	for (int i=0; i<numerKonta.length(); i++){
		liczba = (int) numerKonta[i] - 48;
		suma += liczba;
	}

	suma = suma % 100;
	return suma;
}

Bank::Bank() : nazwa(""){
	this->numerPlacowki = rand();
}

Bank::Bank(std::string nazwaOddzialu){
	Bank();
	setNazwa(nazwaOddzialu);
}

void Bank::setNazwa(std::string nazwa){
	this->nazwa = nazwa;
}

void Bank::uaktualnijAdres(TrybEdycji trybEdycji){
	this->adres.uzupelnij(trybEdycji);
}

int Bank::getNumerPlacowki(){ return this->numerPlacowki; }
std::string Bank::getNazwa(){ return this->nazwa; }