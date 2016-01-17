#pragma once
#include <iostream>
#include "Core.h"

class Interfejs{
	int wybor;
	Core core;

	void Welcome();
	void Bevel();
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
public:
	Interfejs();
	void Run();
};