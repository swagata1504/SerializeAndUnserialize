#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;
  s.put(short(100));

  bool caught;
  try {
    char x;
    s.get(x);
  } catch (string st) {
    if (st.size() > 0) caught = true;
  }

  assert(caught);
  return 0;
}
