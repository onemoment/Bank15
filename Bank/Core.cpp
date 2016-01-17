#include <string>
#include "Core.h"
#include "Parametry.h"
#include "Klient.h"

void Core::DodajKlienta(){
	int unsigned wybor = 10;

	std::string _imie;
	std::string _nazwisko;
	RodzajKlienta _rodzaj;

	std::cout << "Dodaj klienta: " << std::endl;

	// typ klienta
	while (wybor > 2){
		std::cout << "Wskaz rodaj klienta: " << std::endl << "0. Osoba fizyczna " << std::endl << "1. Firma " << std::endl << "2. Instytucja " << std::endl << "Wybor : ";
		std::cin >> wybor;
	}

	_rodzaj = RodzajKlienta(wybor);

	switch (_rodzaj){
	case rkOsobaFizyczna :
		std::cout << "Imie: ";
		std::cin >> _imie;
		std::cout << "Nazwisko: ";
		std::cin >> _nazwisko;
		break;

	case rkFirma:
		std::cout << "Nazwa firmy: ";
		std::cin >> _nazwisko;
		break;

	case rkInstytucja:
		std::cout << "Nazwa instytucji: ";
		std::cin >> _nazwisko;
		break;
	}
	Klient klient(_imie, _nazwisko, _rodzaj);
	klient.uzupelnijAdres(teDodawanie);

	this->klienci.push_back(klient);
}

void Core::WypiszKlientow(){
	std::cout << "Klienci" << std::endl;
	for(int i = 0; i<this->klienci.size(); i++){
		std::cout << i << ". " << this->klienci[i].getHeadLine() << std::endl;
	}
}

void Core::EdytujDaneklienta(){
	std::cout << "Wybierz klienta do edycji: " << std::endl;
	WypiszKlientow();
}