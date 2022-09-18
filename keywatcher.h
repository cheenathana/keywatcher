#ifndef KEYWATCHER_HEADER
#define KEYWATCHER_HEADER

#include <ctime>
#include <string>
#include <sstream>

namespace keywatcher {
  // class template for specifying a generic type
  template <class T>

  std::string to_string(const T&);     // parameter: reference value of a generic type(means any type of data)
  void write_to_log(const std::string&);


  struct datetime {
    // constructor for struct (allowed only in c++)
    datetime() {
      time_t ms;
      time(&ms);     // fetch the local time in millisec place it in variable

      struct tm* dt = localtime(&ms);

      auto sec = dt->tm_sec;
      auto minu = dt->tm_min;
      auto hour = dt->tm_hour;
      auto date = dt->tm_mday;
      auto mon = dt->tm_mon + 1;
      auto year = 1900 + dt->tm_year;

    }
  };

}


#endif // KEYWATCHER_HEADER
