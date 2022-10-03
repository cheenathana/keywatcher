#ifndef KEYWATCHER_HEADER
#define KEYWATCHER_HEADER

#include <ctime>
#include <string>
#include <sstream>


namespace keywatcher {
  // class template for specifying a generic type
  template <class T>

  /* Helper functions */
  std::string to_string(const T&);     // parameter: reference value of a generic type(means any type of data)
  void log(const std::string);

  std::string fetch_apps_root_path();
  std::string fetch_log_path();
  bool make_dir(std::string);
  bool validate_path(std::string);


  /* datetime struct  */
  struct datetime {
    int sec, minu, hour, date, mon, year;

    // constructor for struct (allowed only in c++)
    datetime() {
      time_t ms;
      time(&ms);     // fetch the local time in millisec place it in variable

      struct tm* dt = localtime(&ms);

      sec = dt->tm_sec;
      minu = dt->tm_min;
      hour = dt->tm_hour;
      date = dt->tm_mday;
      mon = dt->tm_mon + 1;
      year = 1900 + dt->tm_year;
    }

    std::string now() {
      return datetime().get_datetime();
    }

    std::string get_dated_filename() {
      // return string of format DD_MM_YY
      return to_string(year) + "_" + to_string(mon) + "_" + to_string(date);
    }

    std::string get_date() {
      // formatting date to DD:MM:YY
      return std::string(date < 10 ? "0":"") + to_string(date) + ":" +
             std::string(mon < 10 ? "0":"") + to_string(mon) + ":" +
             to_string(year);
    }

    std::string get_time() {
      // formatting time to HH:MM:YY
      return std::string(sec < 10 ? "0":"") + to_string(sec) + ":" +
             std::string(minu < 10 ? "0":"") + to_string(minu) + ":" +
             std::string(hour < 10 ? "0":"") + to_string(hour);
    }

    std::string get_datetime() {
      return get_time() + " " + get_date();
    }
  };

}


#endif // KEYWATCHER_HEADER
