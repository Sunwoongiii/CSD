#include <iostream>
using namespace std;

int add_int(const int a, const int b){return a+b;}
double add_double(const double a, const double b){return a+b;}

template<typename T, typename U>
auto add_any(const T& a, const U& b)->decltype(a+b){
  static_assert(std::is_same<decltype(a+b), decltype(a+b)>::value, "Types must support addition operator.\n");
  return a+b;
}

class MyClass{
public:
  int value;
  MyClass(int v):value(v){}
  MyClass operator+(const MyClass& other)const{
    return MyClass(value + other.value);
  }
  void print()const{cout<<value<<'\n';}
};

int main(){
  MyClass o1(10), o2(20);
  MyClass o3 = add_any(o1, o2);

  cout<<"add_int(3,4): "<<add_int(3,4)<<'\n';
  cout<<"add_double(3.1,4.2): "<<add_double(3.1,4.2)<<'\n';
  cout<<"add_any(string, string): "<<add_any(string("Hello "), string("World!"))<<'\n';
  cout<<"add_any(class, class): "; o3.print();
}