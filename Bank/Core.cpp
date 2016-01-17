#include <string>
#include "Core.h"
#include "Parametry.h"
#include "Klient.h"

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