#include <iostream>
#include "Adres.h"

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