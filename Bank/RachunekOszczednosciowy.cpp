#include "RachunekOszczednosciowy.h"

RachunekOszczednosciowy::RachunekOszczednosciowy(double oprocentowanie){
	Rachunek::Rachunek();
	setOprocetowanie(oprocentowanie);
}
void RachunekOszczednosciowy::naliczOdsetki(){
	double wartosc = (getSaldo() * getOprocentowanie()) / 100;
	wplata("Naliczenie odsetek", wartosc);
}