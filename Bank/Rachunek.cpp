#include <iostream>
#include "Rachunek.h"
#include "Tool.h"


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

Rachunek::Rachunek(){
	std::string idOddzial = Tool::uzupelnijDoDlugosci(Tool::asString(getNumerPlacowki()), 10);
	std::string idRachunek = Tool::uzupelnijDoDlugosci(Tool::asString(rand()), 10);
	idOddzial.append(idRachunek);
	idRachunek = Tool::uzupelnijDoDlugosci(Tool::asString(sumaKontrolna(idOddzial)), 2);
	idRachunek.append(idOddzial);

	this->numer = idRachunek;
	this->stanKonta = 0.0;
	this->klient = -1;
	this->oprocentowanie = 0.0;
	this->czyKarta = false;
	this->prowizja = 0.1;
	this->waluta = wPLN;
	this->otwarty = true;
}

Rachunek::Rachunek(int idKlient){
	Rachunek();
	podlaczKlienta(idKlient);
}

void Rachunek::podlaczKlienta(int idKlient){
	this->klient = idKlient;
}

int Rachunek::getKlientId(){
	return this->klient;
}

void Rachunek::setOprocetowanie(double oprocentowanie){
	this->oprocentowanie = oprocentowanie;
}

double Rachunek::getOprocentowanie(){
	return this->oprocentowanie;
}

void Rachunek::podlaczKarte(){
	this->czyKarta = true;
}

bool Rachunek::isKarta(){
	return this->czyKarta;
}

void Rachunek::setProwizja(double prowizja){
	this->prowizja = prowizja;
}

double Rachunek::getProwizja(){
	return this->prowizja;
}

Waluta Rachunek::getWaluta(){
	return this->waluta;
}

double Rachunek::getSaldo(){
	return this->stanKonta;
}

bool Rachunek::wplata(double kwota){
	this->stanKonta += kwota;
	return true;
}

bool Rachunek::wyplata(double kwota){
	if (kwota >= this->stanKonta){
		this->stanKonta -= kwota;
		return true;
	}else{
		return false;
	}
}

bool Rachunek::zamknijRachunek(){
	this->otwarty = false;
	Data data;
	this->dataZamkniecia = data;
	return true;
}
void Rachunek::przelewPrzychodzacy(int nadawca, double kwota){
	wplata(kwota);// log
}

void Rachunek::przelewWychodzacy(int odbiorca, double kwota){
	wyplata(kwota); //log
}