#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "keywatcher.h"

template <class T>
std::string keywatcher::to_string(const T& value) {
  std::ostringstream s;

  s << value;

  return s.str();
}


void keywatcher::write_to_log(const std::string& s) {
  std::ofstream file("keywatcher.log", std::ios::app);     // opening file in append mode

  file << "[" << keywatcher::datetime().get_datetime() << "] " << s << std::endl;
  file.close();
}
