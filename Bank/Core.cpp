#include <string>
#include "Core.h"
#include "Parametry.h"
#include "Klient.h"
#include "RachunekBiezacy.h"
#include "RachunekOszczednosciowy.h"
#include "RachunekWalutowy.h"

void Core::DodajKlienta(){
	Klient klient;
	klient.uzupelnijDane(teDodawanie);
	klient.uzupelnijAdres(teDodawanie);

	this->klienci.push_back(klient);
}

void Core::WypiszKlientow(){
	if (this->klienci.size() == 0){
		std::cout << "    brak klientow.\n" << std::endl;
	}
	else
	{
		for(int i = 0; i<this->klienci.size(); i++){
			std::cout << i << ". " << this->klienci[i].getHeadLine() << std::endl;
		}
	}
}

void Core::EdytujDaneklienta(){
	std::cout << "Wybierz klienta do edycji: " << std::endl;
	int unsigned id;
	WypiszKlientow();
	std::cout << "> ";
	cin >> id;

	if (id < this->klienci.size()){
		this->klienci[id].uzupelnijDane(teZmiana);
		this->klienci[id].uzupelnijAdres(teZmiana);
	}

}

void Core::DodajRachunek(){
	std::cout << "Wybierz klienta: " << std::endl;
	int unsigned id;
	WypiszKlientow();
	std::cout << "> ";
	cin >> id;

	int typ = 10;

	if (id < this->klienci.size()){
		
		std::cout << "Podaj rodzaj rachunku:\n0. Rachunek biezacy\n1. Rachunek oszczednosciowy\n2. Rachunek walutowy" << std::endl;
		std::cin >> typ;

		switch(typ){
		case 0:{
			RachunekBiezacy rb(id);
			this->konta.push_back(rb);
			break;
		}
		case 1:{
			double procent;
			std::cout << "Podaj oprocentowanie: ";
			std::cin >> procent;
			RachunekOszczednosciowy ro(procent);
			ro.podlaczKlienta(id);
			this->konta.push_back(ro);
			break;
		}
		case 2:{
			int wal;
			std::cout << "Podaj walute: \n1. EURO\n2. Dolar\n3. CHF" << std::endl;
			std::cin >> wal;
			if (wal > 0 && wal <=3){
				Waluta w = Waluta(wal);
				RachunekWalutowy rw(w);
				rw.podlaczKlienta(id);
				this->konta.push_back(rw);
			}else{
				std::cout << "Nie wybrano waluty." << std::endl;
			}
			break;
		}
		default:{ std::cout << "Nie wybrano rodzaju konta. " << std::endl; }
		}

	}else{
		std::cout << "Wybrany klient nie istnieje." << std::endl;
	}
}

void Core::ListaRachunkow(){
	if (this->konta.size() == 0){
		std::cout << "    brak rachunkow.\n" << std::endl;
	}
	else
	{
		std::string status;

		for(int i = 0; i<this->konta.size(); i++){

			this->konta[i].isOtwarty() ? status = "Aktywny" : status = "Zamkniety";

			std::cout << i << ". Numer: " << this->konta[i].getNumer() << 
				" Klient: " << this->klienci[this->konta[i].getKlientId()].getHeadLine() << 
				" Saldo: " << this->konta[i].getSaldo() << " Status: " << status << 
				std::endl;
		}
	}
}

void Core::UsunRachunek(){
	std::cout << "Wybierz rachunek do usuniecia: " << std::endl;
	int unsigned id;
	ListaRachunkow();
	std::cout << "> ";
	cin >> id;

	if (id < this->konta.size()){
		this->konta[id].zamknijRachunek();
	}

}