#include <iostream>
#include <vector>
#define PI 3.14159265358979323846
using namespace std;

class Shape{
  string name;
protected:
  int width, height;
public:
  Shape(string n, int w, int h)
    : name(n),width(w),height(h){}

  virtual double getArea(){return 0;}
  
  string getName() const{return name;}
};

class Ellipse : public Shape{
public:
  Ellipse(string n, int w, int h): Shape(n,w,h){}
  double getArea() override{
    return PI * width * height;
  }
};

class Rect : public Shape{
public:
  Rect(string n, int w, int h):Shape(n,w,h){}
  double getArea() override{
    return width * height;
  }
};

class Triangle : public Shape{
public:
  Triangle(string n, int w, int h):Shape(n,w,h){}
  double getArea() override{
    return (width*height)/2.0;
  }
};

int main(){
  vector<Shape*>p(3);
  p[0] = new Ellipse("Ellipse", 10, 20);
  p[1] = new Rect("Rectangle", 30, 40);
  p[2] = new Triangle("Triangle", 30, 40);

  for(int i = 0; i < 3; i++){
    cout<<p[i]->getName()<<"'s area is "<<p[i]->getArea()<<"\n";
  }
  for(int i = 0; i < 3; i++) delete p[i];

  return 0;
}