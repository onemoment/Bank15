#pragma once
#include <iostream>

class Tool{
public:
  static std::string IntAsString(int input);
  static std::string DoubleAsString(double input);
  static std::string uzupelnijDoDlugosci(std::string wpis, int dlugosc);
};