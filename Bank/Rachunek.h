#pragma once
#include <iostream>
#include "Bank.h"
#include "Adres.h"
#include "Parametry.h"
#include "Data.h"

enum Waluta{
	wPLN,
	wEUR,
	wDOL,
	wCHF
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

	void setWaluta(Waluta waluta);
	Waluta getWaluta();

	double getSaldo();
	bool wplata(std::string tytul, double kwota);
	bool wyplata(std::string tytul, double kwota);
	bool zamknijRachunek();
	void przelewPrzychodzacy(int nadawca, double kwota, std::string tytul);
	void przelewWychodzacy(int odbiorca, double kwota, std::string tytul);
};