#include <iostream>
#include <windows.h>
#include <string>

#include "../include/keywatcher.h"

int main() {
//  MSG msg;
//
//  while (GetMessage(&msg, NULL, 0, 0)) {
//    // converts virtual keys to character input message
//    TranslateMessage(&msg);
//
//    // dispatches a message to a window procedure
//    DispatchMessage(&msg);
//  }

  std::cout << keywatcher::datetime().get_datetime() << std::endl;
  keywatcher::datetime x;
  keywatcher::datetime y;
  keywatcher::datetime z;

  std::cout << x.get_datetime() << std::endl;
  std::cout << z.get_datetime() << std::endl;
  std::cout << y.get_datetime() << std::endl;

  std::cout << "Dated filename: " << x.get_dated_filename() << std::endl;


  std::string path = keywatcher::fetch_apps_root_path();
  std::cout << "Apps base path: " << path << std::endl;

  // Writing logs
  keywatcher::log("Hello writing to log file.");





  return 0;
}
