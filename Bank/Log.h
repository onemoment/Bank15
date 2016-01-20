#include <iostream>

class Log{
private:
	std::string nazwaPliku;
	void init();
public:
	Log();
	void zaloguj(std::string komunikat);
	void pokaz();
};