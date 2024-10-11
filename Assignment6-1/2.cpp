#include <iostream>
using namespace std;

class Point{
protected:
  int x,y;
public:
  Point(int x1,int y1): x(x1), y(y1){}
  void move(int _x, int _y){
    this->x = _x;
    this->y = _y;
  }
};

class ColorPoint : public Point{
private:
  string color;
public:
  ColorPoint(int x1, int y1, string color): Point(x1,y1), color(color) {}
  void setPoint(int _x, int _y){
    move(_x, _y);
  }
  void setColor(string _color){
   this->color = _color;
  }
  void show(){
    cout<<"The pointer's color is "<<color<<" which is on ("<<x<<","<<y<<").\n";
  }
};

int main(){
  ColorPoint cp(5,5,"RED");
  cp.show();
  cp.setPoint(10,20);
  cp.setColor("BLUE");
  cp.show();
}