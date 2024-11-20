#include <iostream>
#include <type_traits>
#include <string>

int add_int(int a, int b) {
  return a + b;
}

double add_double(double a, double b) {
  return a + b;
}

template <typename T>
auto add_any(const T& a, const T& b) -> decltype(a + b) {
  return a + b;
}

int main() {
  int int_sum = add_int(3, 5);
  std::cout << "int_sum: " << int_sum << std::endl;

  double double_sum = add_double(3.14, 2.71);
  std::cout << "double_sum: " << double_sum << std::endl;

  std::string str_sum = add_any(std::string("Hello, "), std::string("World!"));
  std::cout << "str_sum: " << str_sum << std::endl;

  class Point {
  private:
    int x, y;

  public:
    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point& other) const {
      return Point(x + other.x, y + other.y);
    }

    void print() const {
      std::cout << "(" << x << ", " << y << ")";
    }
  };

  Point p1(1, 2), p2(3, 4);
  Point p_sum = add_any(p1, p2);
  std::cout << "p_sum: ";
  p_sum.print();

  return 0;
}
