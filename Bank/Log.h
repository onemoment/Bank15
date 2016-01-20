#include <iostream>

class Log{
private:
	std::string nazwaPliku;
public:
	Log();
	void zaloguj(std::string komunikat);
	void pokaz();
};