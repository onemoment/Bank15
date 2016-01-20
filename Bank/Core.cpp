#include <string>
#include "Core.h"
#include "Tool.h"
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
	zaloguj("Dodano klienta " + klient.getHeadLine());
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
			zaloguj("Utworzono konto " + rb.getNumer());
			break;
		}
		case 1:{
			double procent;
			std::cout << "Podaj oprocentowanie: ";
			std::cin >> procent;
			RachunekOszczednosciowy ro(procent);
			ro.podlaczKlienta(id);
			this->konta.push_back(ro);
			zaloguj("Utworzono konto " + ro.getNumer());
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
				zaloguj("Utworzono konto " + rw.getNumer());
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
		zaloguj("Zamknieto konto " + this->konta[id].getNumer());
	}

}

void Core::DokonajWplaty(){
	std::cout << "Wybierz rachunek: " << std::endl;
	int unsigned id;
	ListaRachunkow();
	std::cout << "> ";
	cin >> id;

	if (id < this->konta.size()){
		
		double kwota;
		std::string tytul;

		std::cout << "Podaj kwote wplaty: ";
		std::cin >> kwota;

		std::cout << "Tytul wplaty: ";
		std::cin >> tytul;

		this->konta[id].wplata(tytul, kwota);
		zaloguj("Wplata na konto " + this->konta[id].getNumer() + " Tytulem \"" + tytul + "\" Kwota " + Tool::DoubleAsString(kwota));
	}

}

void Core::DokonajWyplaty(){
	std::cout << "Wybierz rachunek: " << std::endl;
	int unsigned id;
	ListaRachunkow();
	std::cout << "> ";
	cin >> id;

	if (id < this->konta.size()){
		
		double kwota;
		std::string tytul;

		std::cout << "Podaj kwote wyplaty: ";
		std::cin >> kwota;

		std::cout << "Tytul wyplaty: ";
		std::cin >> tytul;

		this->konta[id].wyplata(tytul, kwota);
		zaloguj("Wyplata z konta " + this->konta[id].getNumer() + " Tytulem \"" + tytul + "\" Kwota " + Tool::DoubleAsString(kwota));
	}
}

void Core::WyslijPrzelew(){
	int unsigned id1;
	int unsigned id2;

	std::cout << "Wybierz rachunek nadawcy: " << std::endl;
	ListaRachunkow();
	std::cout << "> ";
	cin >> id1;

	if (id1 < this->konta.size()){
		
		std::cout << "Wybierz rachunek odbiorcy: " << std::endl;
		ListaRachunkow(); // exclude
		std::cout << "> ";
		cin >> id2;

		if (id1 < this->konta.size() && id1 != id2){

			double kwota;
			std::string tytul;

			std::cout << "Podaj kwote wplaty: ";
			std::cin >> kwota;

			std::cout << "Tytul wplaty: ";
			std::cin >> tytul;

			Przelew(id1, id2, tytul, kwota);
			zaloguj("Wykonano przelew z konta " + this->konta[id1].getNumer() + " na konto " + this->konta[id2].getNumer() + " Tytulem \"" + tytul + "\" Kwota " + Tool::DoubleAsString(kwota));
		}
	}
}

void Core::Przelew(int idKlient1, int idKlient2, std::string tytul, double kwota){
	this->konta[idKlient1].wyplata(tytul, kwota);
	this->konta[idKlient2].wplata(tytul, kwota);
}

void Core::PodajSaldo(){
	std::cout << "Wybierz rachunek: " << std::endl;
	int unsigned id;
	ListaRachunkow();
	std::cout << "> ";
	cin >> id;

	if (id < this->konta.size()){
		std::cout << "Obecne saldo: " << this->konta[id].getSaldo() << this->konta[id].getWaluta() << std::endl;
	}
}


void Core::PokazLog(){
	pokaz();
}