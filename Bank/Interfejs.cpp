#pragma once
#include <iostream>
#include <string>
#include "Interfejs.h"
#include "Klient.h"
#include "Tool.h"
#include "Data.h"


Interfejs::Interfejs(): wybor(0)
{}

void Interfejs::Run(){
	Welcome();
	do{
		Menu();
		Capture();
		if( Valid() ){
			Use();
		}
	}while(!End());
	Bye();
}

void Interfejs::Bevel(std::string Header){
	int used = 3;
	std:: string bevel = "---";

	if (Header.compare("") != 0){
		bevel.append(" ");
		bevel.append(Header);
		bevel.append(" ");
		used += Header.length() + 2;
	}

	for (int i = 0; i< (80-used); i++){
		bevel.append("-");
	}

	std::cout << bevel << std::endl;
}

void Interfejs::Use(){
	switch(this->wybor){
	// klienci
	case  1: DodawanieKlienta(); break;
	case  2: WypisanieListyKlientow(); break;
	case  3: SzczegolyKlienta(); break;
	case  4: EdytowanieDanychKlienta(); break;
	// konta
	case  5: DodawanieKonta(); break;
	case  6: ListaKont(); break;
	case  7: UsuwanieKonta(); break;
	case  8: SaldoKonta(); break;
	// transakcje
	case  9: TransakcjaWplata(); break;
	case 10: TransakcjaWyplata(); break;
	case 11: TransakcjaPrzelew(); break;

	case 12: LogAplikacji(); break;
	}
}

bool Interfejs::End(){
	return this->wybor == 0;
}

void Interfejs::Capture(){
	do{
		this->wybor = Tool::inputUInt();
		if (this->wybor == -1){
			std::cout << "Bledne dane!" << std::endl;
		}
	}while(this->wybor == -1);
}

bool Interfejs::Valid(){
	return 
		(this->wybor >= 0) ||
		(this->wybor <= 12);
}

void Interfejs::Menu(){
	using namespace std;
	int unsigned wybor;

	cout << endl;
	Bevel("Menu");
	cout << "Kartoteka klientow        Katroteka rachunkow       Transakcje         " << endl;
	cout << "1. Dodaj klienta          5. Dodaj rachunek          9. Wplata         " << endl;
	cout << "2. Lista klientow         6. Lista rachunkow        10. Wyplata        " << endl;
	cout << "3. Szczegoly klienta      7. Usun rachunek          11. Przelew        " << endl;
	cout << "4. Edytuj dane klienta    8. Saldo rachunku                            " << endl;
	cout << "\n0. Wyjscie                                          12. Log aplikacji  " << endl;
	cout << "> ";
}

void Interfejs::Welcome(){
	std::cout << "Aplikacja bankowa" << std::endl << std::endl;
	Data data;
	data.teraz();
	this->core.zaloguj("Uruchomienie dnia: " + data.getData());
}

void Interfejs::Bye(){
	std::cout << std::endl << "Do widzenia!" << std::endl;
}

// akcje

void Interfejs::DodawanieKlienta(){
	Bevel("Dodaj klienta");
	this->core.DodajKlienta();
}

void Interfejs::WypisanieListyKlientow(){
	Bevel("Lista klientow");
	this->core.WypiszKlientow();
}

void Interfejs::SzczegolyKlienta(){
	Bevel("Szczegoly klienta");
	this->core.WyswietlKlienta();
}

void Interfejs::EdytowanieDanychKlienta(){
	Bevel("Edytuj dane klienta");
	this->core.EdytujDaneklienta();
}

void Interfejs::DodawanieKonta(){
	Bevel("Dodaj rachunek");
	this->core.DodajRachunek();
}

void Interfejs::ListaKont(){
	Bevel("Lista rachunkow");
	this->core.ListaRachunkow();
}

void Interfejs::UsuwanieKonta(){
	Bevel("Usun rachunek");
	this->core.UsunRachunek();
}

void Interfejs::SaldoKonta(){
	Bevel("Saldo rachunku");
	this->core.PodajSaldo();
}


void Interfejs::TransakcjaWplata(){
	Bevel("Wplata na rachunek");
	this->core.DokonajWplaty();
}

void Interfejs::TransakcjaWyplata(){
	Bevel("Wyplata z rachunku");
	this->core.DokonajWyplaty();
}

void Interfejs::TransakcjaPrzelew(){
	Bevel("Przelew");
	this->core.WyslijPrzelew();
}

void Interfejs::LogAplikacji(){
	Bevel("Dziennik aplikacji");
	this->core.PokazLog();
}