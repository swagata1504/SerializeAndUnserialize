#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;
  int i {39534};
  s.put(i);
  int x;
  s.get(x);
  SAME(x, 39534)
  return 0;
}
