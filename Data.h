#pragma once
#include <iostream>

using namespace std;

class Data{
	int fDzien;
	int fMiesiac;
	int fRok;
public:
	Data();
	Data(int Dzien, int Miesiac, int Rok);
	// setters
	void setDzien(int Dzien);
	void setMiesiac(int Miesiac);
	void setRok(int Rok);
	// getters
	int getDzien();
	int getMiesiac();
	int getRok();
	string getData();
};