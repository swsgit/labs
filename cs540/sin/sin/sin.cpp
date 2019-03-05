// Spencer Stone
// CS540
// 3/4/19
#include <iostream>
#include <math.h>

using namespace std;

double factorial(int n) {
  double tmp = 1.00;
  for (int i = n; i > 0; i--) {
    tmp *= i;
  }
  return tmp;
}

double _sin(double x) {
  return x - (pow(x, 3) / factorial(3)) + (pow(x, 5) / factorial(5)) -
         (pow(x, 7) / factorial(7)) + (pow(x, 9) / factorial(9)) -
         (pow(x, 11) / factorial(11)) + (pow(x, 13) / factorial(13));
}

int main() {
  constexpr auto PI = 3.14159265358979323846;
  printf("%f\n", _sin(PI));

  return 0;
}
/*
0.000021
*/