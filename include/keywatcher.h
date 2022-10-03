#ifndef KEYWATCHER_HEADER
#define KEYWATCHER_HEADER

#include <ctime>
#include <string>
#include <sstream>

#include "windows.h"

// Namespace for Keywatcher application
namespace kw {
  // class template for specifying a generic type
  template <class T>

  /* Support functions */
  std::string to_string(const T&);     // parameter: reference value of a generic type(means any type of data)
  void log(const std::string);

  std::string fetch_apps_root_path();
  std::string fetch_log_path();
  std::string fetch_keyfile_path();
  bool make_dir(std::string);
  bool validate_path(std::string);


  /* timestamp struct  */
  struct timestamp {
    int yy, mm, dd, H, M, S;

    // constructor for struct (allowed only in c++)
    timestamp() {
      time_t ms;
      time(&ms);     // fetch the local time in millisec place it in "ms" variable

      struct tm* dt = localtime(&ms);

      S = dt->tm_sec;
      M = dt->tm_min;
      H = dt->tm_hour;
      dd = dt->tm_mday;
      mm = dt->tm_mon + 1;
      yy = 1900 + dt->tm_year;
    }

    std::string now() {
      return timestamp().get_timestamp();
    }

    std::string get_filename() {
      // return string of format YY_MM_DD to be used for file name
      return to_string(yy) + "_" + to_string(mm) + "_" + to_string(dd);
    }

    std::string get_date() {
      // formatting date to DD:MM:YY
      return std::string(dd < 10 ? "0":"") + to_string(dd) + ":" +
             std::string(mm < 10 ? "0":"") + to_string(mm) + ":" +
             to_string(yy);
    }

    std::string get_time() {
      // formatting time to HH:MM:YY
      return std::string(S < 10 ? "0":"") + to_string(S) + ":" +
             std::string(M < 10 ? "0":"") + to_string(M) + ":" +
             std::string(H < 10 ? "0":"") + to_string(H);
    }

    std::string get_timestamp() {
      // formatting date & time to "HH:MM:YY DD:MM:YY"
      return get_time() + " " + get_date();
    }
  };

}


#endif // KEYWATCHER_HEADER
