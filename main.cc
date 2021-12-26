#include <stdio.h>
#include <iostream>
#include <vector>

#include "interval.h"

double_int fp(double_int x) {
  return double_int(2)*(x);
}

double_int f(double_int x) {
  return (x*x) - double_int(10);
}

int main() {
 
  // Find the left root of x^2-10
  double_int xn(-5);
  
  double prev_rng = xn.range();
  double prev_mid = xn.mid();

  do {
    prev_rng = xn.range();
    prev_mid = xn.mid();

    xn = xn - (f(xn)/fp(xn));
    xn.print();
  } while (xn.mid() != prev_mid && xn.range() >= prev_rng);
  
  return 0;
}
