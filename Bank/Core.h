#include <iostream>
#include <vector>
#include "Klient.h"
#include "Rachunek.h"
#include "Log.h"

using namespace std;

class Core : public Log{

private:
	
	vector<Klient> klienci;
	vector<Rachunek> konta;

	void Przelew(int idKlient1, int idKlient2, std::string tytul, double kwota);
public:

	// kartoteka klientow
	void DodajKlienta();
	void WypiszKlientow();
	void EdytujDaneklienta();

	// lista rachunkow
	void DodajRachunek();
	void ListaRachunkow();
	void UsunRachunek();
	void PodajSaldo();

	// operacje na rachunkach
	void DokonajWplaty();
	void DokonajWyplaty();
	void WyslijPrzelew();

	// dzialania aplikacji
	void PokazLog();
};