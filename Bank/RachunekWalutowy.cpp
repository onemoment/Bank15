#include "RachunekWalutowy.h"


RachunekWalutowy::RachunekWalutowy(Waluta waluta){
	Rachunek::Rachunek();
	setWaluta(waluta);
}

void RachunekWalutowy::setWaluta(Waluta waluta){
	if (waluta != wPLN){
		Rachunek::setWaluta(waluta);
	}
}