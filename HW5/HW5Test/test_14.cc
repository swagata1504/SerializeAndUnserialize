#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;
  const short x {6};
  s.put(x);
  SAME(s.empty(), false)
  return 0;
}
