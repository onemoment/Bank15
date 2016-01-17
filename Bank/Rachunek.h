#pragma once
#include <iostream>
#include "Adres.h"
#include "Parametry.h"
#include "Data.h"

enum Waluta{
	wPLN,
	wEUR,
	wDOL,
	wCHF
};

class Bank{
private:
	std::string nazwa;
	Adres adres;
	int numerPlacowki;
	
public:
	Bank();
	Bank(std::string nazwaOddzialu);
	void setNazwa(std::string nazwa);
	void uaktualnijAdres(TrybEdycji trybEdycji);

	int getNumerPlacowki();
	std::string getNazwa();
	int sumaKontrolna(std::string numerKonta);
};

class Rachunek : Bank{
private:
	std::string numer;
	double stanKonta;
	int klient;
	double oprocentowanie;
	Data dataZalozenia;
	Data dataZamkniecia;
	bool czyKarta;
	double prowizja;
	Waluta waluta;
	bool otwarty;

public:
	Rachunek();
	Rachunek(int idKlient);
	
	void podlaczKlienta(int idKlient);
	int getKlientId();

	void setOprocetowanie(double oprocentowanie);
	double getOprocentowanie();

	void podlaczKarte();
	bool isKarta();

	void setProwizja(double prowizja);
	double getProwizja();

	Waluta getWaluta();

	double getSaldo();
	bool wplata(double kwota);
	bool wyplata(double kwota);
	bool zamknijRachunek();
	void przelewPrzychodzacy(int nadawca, double kwota);
	void przelewWychodzacy(int odbiorca, double kwota);
};