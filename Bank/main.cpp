#include <iostream>
#include "Data.h"

int main(int argc, char **argv) {
  Data data;
  data.setDzien(23);
  
  std::cout << data.getData(); 
  
  return 0;
}