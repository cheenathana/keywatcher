#include <iostream>
#include <windows.h>

#include "keywatcher.h"

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

  std::cout << "apps_path: " << keywatcher::get_apps_root_path() << std::endl;

  return 0;
}
