#pragma once
#include <iostream>
#include "Interfejs.h"


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

void Interfejs::Use(){
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
	cout << endl;
	cout << "Menu" << endl;
	cout << "1. Dodaj klienta " << endl;
	cout << "0. Wyjscie " << endl;
	cout << "> ";
}

void Interfejs::Welcome(){
	std::cout << "Aplikacja bankowa" << std::endl << std::endl;
}

void Interfejs::Bye(){
	std::cout << std::endl << "Do widzenia!" << std::endl;
}