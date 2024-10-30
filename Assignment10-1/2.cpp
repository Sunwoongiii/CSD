#include <iostream>
using namespace std;

class Circle{
  int radius;

public:
  Circle(int radius = 0):radius(radius){}

  void show()const{
    cout<<"Circle's radius = "<<radius<<endl;
  }

  friend Circle& operator ++ (Circle& c);
  friend Circle operator ++ (Circle& c, int);
};

Circle& operator ++ (Circle& c){
  ++c.radius;
  return c;
}

Circle operator ++ (Circle& c, int){
  Circle temp = c;
  c.radius++;
  return temp;
}

int main(){
  Circle a(5), b;
  b = ++a;
  a.show();
  b.show();
  b = a++;
  a.show();
  b.show();
}