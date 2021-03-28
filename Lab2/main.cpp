#include <iostream>

#include "LinearEquation.h"

using namespace std;

int main(int argc, char** argv) {
  double a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  string res = LinearEquation_solveEquation(a, b, c, d, e, f);

  cout << res << endl;
  return 0;
}