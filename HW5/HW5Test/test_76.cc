#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;

  s.put(3);
  s.put('*');
  int x;
  s.get(x);
  assert(x == 3);
  s.put("testing"s);
  s.put(true);

  char ch;
  s.get(ch);
  assert(ch == '*');

  string ss;
  s.get(ss);
  assert(ss == "testing"s);

  assert(ss.empty() == false);
  return 0;
}
