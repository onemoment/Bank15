#pragma once
#include <iostream>

class Tool{
public:
	// tekstowe
	static std::string uzupelnijDoDlugosci(std::string wpis, int dlugosc);

	// konwersje
	static std::string IntAsString(int input);
	static std::string DoubleAsString(double input);
	static int strToUInt(std::string input);
	static double strToDouble(std::string input);
		
	// odczyt
	static std::string inputString();
	static int inputUInt();
	static double inputDouble();
};