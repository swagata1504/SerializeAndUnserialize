#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;
  s.put(9832759025L);
  long x;
  s.get(x);
  SAME(x, 9832759025L)
  return 0;
}
