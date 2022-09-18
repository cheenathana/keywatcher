#include <iostream>
#include <windows.h>

int main() {
  MSG msg;

  while (GetMessage(&msg, NULL, 0, 0)) {
    // converts virtual keys to character input message
    TranslateMessage(&msg);

    // dispatches a message to a window procedure
    DispatchMessage(&msg);
  }
  return 0;
}
