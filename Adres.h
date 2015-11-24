#pragma once
#include <iostream>

using namespace std;

class Adres{
	string fUlica;
	string fDom;
	int fMieszkanie;
	string fMiasto;
	int fKod;
	string fKraj;
public:
	Adres();
	Adres(string Ulica, string Dom, int Mieszkanie, int Kod, string Miasto, string Kraj);
	
	// setter
	void setUlica(string Ulica);
	void setDom(string Dom);
	void setMieszkanie(int Mieszkanie);
	void setMiasto(string Miasto);
	void setKod(int Kod);
	void setKraj(string Kraj);

	// getter
	string getUlicaDom();
	string getKodMiasto();
	string getKraj();
	string getKod();
};