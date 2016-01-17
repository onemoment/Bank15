#pragma once
#include <iostream>
#include <string>
#include "Interfejs.h"
#include "Klient.h"


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
	case 1: DodawanieKlienta(); break;
	case 2: WypisanieListyKlientow(); break;
	case 3: EdytowanieDanychKlienta(); break;
	case 4: DodawanieKonta(); break;
	case 5: ListaKont(); break;
	case 6: UsuwanieKonta(); break;
	}
}

bool Interfejs::End(){
	return this->wybor == 0;
}

void Interfejs::Capture(){
	std::cin >> this->wybor;
}

bool Interfejs::Valid(){
	return 
		(this->wybor >= 0) ||
		(this->wybor <= 10);
}

void Interfejs::Menu(){
	using namespace std;
	int unsigned wybor;

	cout << endl;
	Bevel("Menu");
	cout << "Kartoteka klientow          Katroteka rachunkow        Transakcje             " << endl;
	cout << "1. Dodaj klienta            4. Dodaj rachunek          7. Wplata              " << endl;
	cout << "2. Lista klientow           5. Lista rachunkow         8. Wyplata             " << endl;
	cout << "3. Edytuj dane klienta      6. Usun rachunek           9. Przelew             " << endl;
	cout << "                                                      10. Historia transakcji " << endl;
	cout << "\n0. Wyjscie                                                                  " << endl;
	cout << "> ";
}

void Interfejs::Welcome(){
	std::cout << "Aplikacja bankowa" << std::endl << std::endl;
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