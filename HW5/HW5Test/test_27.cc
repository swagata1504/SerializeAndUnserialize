#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;
  s.put("You may assume that a string constant will not contain a double quote, backslash, or a newline."s);
  string x;
  s.get(x);
  SAME(x, "You may assume that a string constant will not contain a double quote, backslash, or a newline."s)
  return 0;
}
