#include <iostream>
#include <vector>
#include "Klient.h"

using namespace std;

class Core{

private:
	
	vector<Klient> klienci;
	vector<string> konta;

public:

	// kartoteka klientow
	void DodajKlienta();
	void WypiszKlientow();
	void EdytujDaneklienta();

	// lista rachunkow
	void DodajRachunek();

};