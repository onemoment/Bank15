#include "Rachunek.h"

class RachunekWalutowy : public Rachunek{
public:
	RachunekWalutowy(Waluta waluta);
	void setWaluta(Waluta waluta);
};