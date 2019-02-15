#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;
  int i {39534};
  bool b {true};
  s.put(i);
  s.put(b);
  int ii; bool bb;
  s.get(ii);
  s.get(bb);
  SAME(ii, 39534)
  SAME(bb, true)
  return 0;
}
