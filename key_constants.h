#ifndef KEYCONSTANTS_HEADER
#define KEYCONSTANTS_HEADER

#include <string>
#include <map>

class KeyPair {
  private:
    std::string virtual_name;
    std::string key_name;

  public:
    KeyPair(const std::string vn, const std::string kn) {
      virtual_name = vn;
      key_name = kn;
    }
};


#endif // KEYCONSTANTS_HEADER
