#pragma once
#include <iostream>
#include "Core.h"

class Interfejs{
	int wybor;
	Core core;

	void Welcome();
	void Bevel(std::string Header);
	void Menu();
	void Capture();
	bool Valid();
	void Use();
	bool End();
	void Bye();

	// akcje
	void DodawanieKlienta();
	void WypisanieListyKlientow();
	void EdytowanieDanychKlienta();

	void DodawanieKonta();
	void ListaKont();
	void UsuwanieKonta();
	void SaldoKonta();

	void TransakcjaWplata();
	void TransakcjaWyplata();
	void TransakcjaPrzelew();

	void LogAplikacji();
public:
	Interfejs();
	void Run();
};