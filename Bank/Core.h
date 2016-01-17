#include <iostream>
#include <vector>
#include "Klient.h"
#include "Rachunek.h"

using namespace std;

class Core{

private:
	
	vector<Klient> klienci;
	vector<Rachunek> konta;

public:

	// kartoteka klientow
	void DodajKlienta();
	void WypiszKlientow();
	void EdytujDaneklienta();

	// lista rachunkow
	void DodajRachunek();
	void ListaRachunkow();
	void UsunRachunek();

};