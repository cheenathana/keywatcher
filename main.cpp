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

  std::cout << x.now() << std::endl;
  keywatcher::write_to_log(x.get_date());
  keywatcher::write_to_log(x.now());
  keywatcher::write_to_log("Hello man we are good what is your status??");

  return 0;
}
