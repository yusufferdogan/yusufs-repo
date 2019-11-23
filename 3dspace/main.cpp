#include "space3D.h"
#include <iostream>
#include <graphics.h>
int main(int argc, char const *argv[]) {
  SPACE3D a(2,3,4),b(1,2,3),c(1.2,4.5,9),d;
  cout << "a is\n" << a << "b is\n" << b << "c is\n" << c << "d is\n" << d;
  cout << "difference between a and b nodes is : " << a(b) << endl;
  return 0;
}
