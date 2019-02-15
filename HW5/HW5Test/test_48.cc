#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;
  char ch {'r'};
  s.put(ch);
  SAME(s.str(), "\x63\x72"s)
  return 0;
}
