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

  Serial s3(s2);

  SAME(s3.str(), "\x53\x05\x68\x65\x6c\x6c\x6f"s)
  return 0;
}
