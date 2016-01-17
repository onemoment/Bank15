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

void Interfejs::Bevel(){
	std::cout << "\n============================================================\n" << std::endl;
}

void Interfejs::Use(){
	Bevel();
	switch(this->wybor){
	case 1: DodawanieKlienta(); break;
	case 2: WypisanieListyKlientow(); break;
	case 3: EdytowanieDanychKlienta(); break;
	}
	Bevel();
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
		(this->wybor <= 2);
}

void Interfejs::Menu(){
	using namespace std;
	int unsigned wybor;

	cout << endl;
	cout << "Menu" << endl;
	cout << "1. Dodaj klienta " << endl;
	cout << "2. Lista klientow " << endl;
	cout << "3. Edytuj dane klienta " << endl;
	cout << "0. Wyjscie " << endl;
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
	this->core.DodajKlienta();
}

void Interfejs::WypisanieListyKlientow(){
	this->core.WypiszKlientow();
}

void Interfejs::EdytowanieDanychKlienta(){
	this->core.EdytujDaneklienta();
}