#include <iostream>
#include <sstream>
#include "Tool.h"

std::string Tool::asString(int input){
  std::ostringstream container ;
  container << input ;
  return container.str();
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