#include <iostream>
#include <sstream>
#include "Tool.h"

std::string Tool::IntAsString(int input){
  std::ostringstream container ;
  container << input ;
  return container.str();
}

std::string Tool::DoubleAsString(double input){
	std::ostringstream stream;
	stream << input;
	return stream.str();
}

std::string Tool::uzupelnijDoDlugosci(std::string wpis, int dlugosc){
	int pozostalo = dlugosc - wpis.length();
	std::string uzupelnienie = "";

	for (int i=0; i<pozostalo; i++){
		uzupelnienie.append("0");
	}
	uzupelnienie.append(wpis);
	return uzupelnienie;
}

int Tool::strToUInt(std::string input){
	int res;
	std::istringstream iss(input);
	if (!(iss >> res))
		return -1;
	return res;
}
		
double Tool::strToDouble(std::string input){
	std::istringstream iss(input);
	double res;
	if (!(iss >> res))
		return 0.0;
	return res;
}
		
std::string Tool::inputString(){
	std::string _input;
	getline(std::cin, _input);
	return _input;
}
		
int Tool::inputUInt(){
	std::string _input;
	_input = inputString();
	return strToUInt(_input);
}
		
double Tool::inputDouble(){
	std::string _input;
	_input = inputString();
	return strToDouble(_input);
}