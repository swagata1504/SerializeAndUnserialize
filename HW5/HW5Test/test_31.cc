#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;
  bool b {true};
  s.put(b);
  bool x;
  s.get(x);
  SAME(x, true)
  return 0;
}
