#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s;

  bool caught {false};
  try {
  long l;
  s.get(l);
  } catch (string st) {
    if (!st.empty()) caught = true;
  }
  assert(caught);

  return 0;
}
