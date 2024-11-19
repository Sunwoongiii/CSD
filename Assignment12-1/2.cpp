#include <iostream>
using namespace std;

// 예외의 기본 클래스
class Exceptions {
public:
  virtual void print() const = 0; 
};

class InvalidInputException : public Exceptions {
public:
  void print() const override {
    cout << "Negative value input exception" << endl;
  }
};

class DivideByZeroException : public Exceptions {
public:
  void print() const override {
    cout << "Divide by zero exception" << endl;
  }
};

double divide(int a, int b) {
  if (a < 0 || b < 0) {
    throw InvalidInputException();
  }
  if (b == 0) {
    throw DivideByZeroException();
  }
  return static_cast<double>(a) / b;
}

int main() {
  int x, y;
  double result;

  try {
    cout << "Division. Input two numbers >> ";
    cin >> x >> y;
    result = divide(x, y);
    cout << result << endl;
  }
  catch (DivideByZeroException &e) {
    e.print();
  }
  catch (InvalidInputException &e) {
    e.print();
  }

  return 0;
}
