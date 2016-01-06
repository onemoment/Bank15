#pragma once
#include <iostream>

class Interfejs{
	int wybor;
	void Welcome();
	void Menu();
	void Capture();
	bool Valid();
	void Use();
	bool End();
	void Bye();
public:
	Interfejs();
	void Run();
};