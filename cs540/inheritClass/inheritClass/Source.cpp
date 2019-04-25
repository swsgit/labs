#include <iostream>

class A {
public:
  A(int aa = 0, int bb = 0, int cc = 0) : a(aa), b(bb), c(cc) {
    std::cout << "Inside A()...\n";
  }

public:
  int a;

private:
  int b;

protected:
  int c;
};

class B : public A {
public:
  B(int xx = 1, int yy = 2, int zz = 3, int aa = 4, int bb = 5, int cc = 6)
      : x(xx), y(yy), z(zz), A(aa, bb, cc) {
    std::cout << "Inside B()...\n";
  }

public:
  int x;

private:
  int y;

protected:
  int z;
};

int main() {
  B b;
  b.a = 1;
  b.x = 1;
  //b.c = 1;
  //b.z = 1;

  while (1)
    ;
  return 0;
}