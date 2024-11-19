#include <iostream>
using namespace std;

int Exp(int base, int exponent) {
  if (exponent < 0) {
    throw "Cannot use negative numbers.";
  }

  int result = 1;
  for (int i = 0; i < exponent; i++) {
    result *= base;
  }
  return result;
}

int main() {
  int v = 0;
  try {
    v = Exp(2, 10);
    cout << "The value of 2 to the power 10 is " << v << endl;

    v = Exp(2, -10);
    cout << "The value of 2 to the power -10 is " << v << endl;
  }
  catch (const char *s) {
    cout << "Exception! " << s << endl;
  }

  return 0;
}
