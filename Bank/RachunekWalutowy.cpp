#include "RachunekWalutowy.h"


RachunekWalutowy::RachunekWalutowy(Waluta waluta){
	setWaluta(waluta);
}

void RachunekWalutowy::setWaluta(Waluta waluta){
	if (waluta != wPLN){
		Rachunek::setWaluta(waluta);
	}
}