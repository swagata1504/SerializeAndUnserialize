#include <string>
#include <cassert>
#include <typeinfo>
#include "Serial.h"
#define SAME(X, Y) {assert(typeid(X) == typeid(Y)); assert(X == Y);}

using namespace std;

int main() {
  Serial s1;
  string x {"hello"s};
  s1.put(x);

  const Serial s2(s1);

  Serial s3;
  s3 = s2;
  string xx;
  s3.get(xx);

  assert(xx == "hello"s);
  return 0;
}
