#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;

  s.put(3);
  s.put(4);
  s.put('*');
  int x;
  s.get(x);
  s.get(x);
  s.put("testing"s);
  s.put(true);

  char ch; string ss;
  bool caught = false;

  try {
    s.get(ss);
  } catch (string st) {
    if (st.size() > 0) caught = true;
  }

  assert(caught);

  s.get(ch); s.get(ss);
  assert(ss == "testing"s);
  bool b;
  s.get(b);

  assert(s.empty() == true);
  return 0;
}
