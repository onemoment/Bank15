#include "Rachunek.h"

class RachunekOszczednosciowy : public Rachunek {
public:
	RachunekOszczednosciowy(double oprocentowanie);
	void naliczOdsetki();
};