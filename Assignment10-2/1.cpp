#include <iostream>
using namespace std;

class MyInt {
  int num;
public:
  MyInt(int num) : num(num) {}
  int getNum() const { return num; }
  void show() const { cout << num << endl; }
};

class MyDouble {
  double num;
public:
  MyDouble(double num) : num(num) {}
  double getNum() const { return num; }
  void show() const { cout << num << endl; }
};

MyInt operator+(const MyInt& a, const MyInt& b) {
  return MyInt(a.getNum() + b.getNum());
}

MyInt operator-(const MyInt& a, const MyInt& b) {
  return MyInt(a.getNum() - b.getNum());
}

MyInt operator*(const MyInt& a, const MyInt& b) {
  return MyInt(a.getNum() * b.getNum());
}

MyDouble operator/(const MyInt& a, const MyInt& b) {
  return MyDouble(static_cast<double>(a.getNum()) / b.getNum());
}

MyDouble operator+(const MyInt& a, const MyDouble& b) {
  return MyDouble(a.getNum() + b.getNum());
}

MyDouble operator-(const MyInt& a, const MyDouble& b) {
  return MyDouble(a.getNum() - b.getNum());
}

MyDouble operator*(const MyInt& a, const MyDouble& b) {
  return MyDouble(a.getNum() * b.getNum());
}

MyDouble operator/(const MyInt& a, const MyDouble& b) {
  return MyDouble(a.getNum() / b.getNum());
}

MyDouble operator+(const MyDouble& a, const MyInt& b) {
  return MyDouble(a.getNum() + b.getNum());
}

MyDouble operator-(const MyDouble& a, const MyInt& b) {
  return MyDouble(a.getNum() - b.getNum());
}

MyDouble operator*(const MyDouble& a, const MyInt& b) {
  return MyDouble(a.getNum() * b.getNum());
}

MyDouble operator/(const MyDouble& a, const MyInt& b) {
  return MyDouble(a.getNum() / b.getNum());
}

MyDouble operator+(const MyDouble& a, const MyDouble& b) {
  return MyDouble(a.getNum() + b.getNum());
}

MyDouble operator-(const MyDouble& a, const MyDouble& b) {
  return MyDouble(a.getNum() - b.getNum());
}

MyDouble operator*(const MyDouble& a, const MyDouble& b) {
  return MyDouble(a.getNum() * b.getNum());
}

MyDouble operator/(const MyDouble& a, const MyDouble& b) {
  return MyDouble(a.getNum() / b.getNum());
}

int main() {
  MyInt intNum_1(10), intNum_2(20);
  MyDouble doubleNum_1(100.0), doubleNum_2(70.0);

  (intNum_1 * intNum_2).show();
  (doubleNum_2 - intNum_1).show();
  (intNum_2 + doubleNum_1).show();
  (doubleNum_1 / doubleNum_2).show();

  return 0;
}
