#include <iostream>
#include <sstream>
#include "Tool.h"

std::string Tool::asString(int input){
  std::ostringstream container ;
  container << input ;
  return container.str();
}