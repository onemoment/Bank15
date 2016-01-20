#include <iostream>
#include <fstream>
#include <string>
#include "Log.h"


Log::Log(){
	this->nazwaPliku = "log.txt";
	init();
}

void Log::init(){
	std::ofstream plik;
	plik.open(this->nazwaPliku, std::ofstream::out | std::ofstream::trunc);
	plik.close();
}

void Log::zaloguj(std::string komunikat){	
	std::ofstream plik;
	plik.open(this->nazwaPliku, std::ios_base::app);
	plik << komunikat.c_str() << "\n"; 
	plik.close();
}

void Log::pokaz(){
	std::ifstream plik(this->nazwaPliku);
	std::string linia;
	while (std::getline(plik, linia))
	{
		std::cout << linia << std::endl;
	}
	plik.close();
}