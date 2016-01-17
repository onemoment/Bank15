#include <iostream>
#include "Rachunek.h"

class RachunekWalutowy : Rachunek{
public:
	RachunekWalutowy(Waluta waluta);
	void setWaluta(Waluta waluta);
};