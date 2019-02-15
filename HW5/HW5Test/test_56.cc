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

  bool caught {false};
  try {
  bool bb;
  s.get(bb);
  } catch (string st) {
    if (!st.empty()) caught = true;
  }
  assert(caught);
  return 0;
}
