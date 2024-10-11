#include <iostream>
using namespace std;

class Shape{
protected:
  int width;
  int height;

public:
  Shape(int w, int h): width(w), height(h) {}
};

class Triagle : public Shape{
public:
  Triagle(int w, int h): Shape(w,h) {}
  double getArea(){
    return (width * height) /2.0;
  }
};

class Square : public Shape{
public:
  Square(int w, int h): Shape(w,h){}
  double getArea(){
    return width*height;
  }
};

int main(){
  double width, height;
  cout<<"Width: ";
  cin>>width;
  cout<<"Height: ";
  cin>>height;

  Triagle t1(width, height);
  Square s1(width, height);
  cout<<"Area of the Triangle is "<<t1.getArea()<<"\n";
  cout<<"Area of the Square is "<<s1.getArea()<<"\n";
  return 0;
}