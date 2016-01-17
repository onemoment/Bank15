#pragma once
#include <iostream>

class Tool{
public:
  static std::string asString(int input);
  static std::string uzupelnijDoDlugosci(std::string wpis, int dlugosc);
};