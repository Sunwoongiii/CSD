#include <iostream>
#include <vector>
using namespace std;

class Point{
public:
  int x,y;
  Point(int x=0, int y=0):x(x),y(y){} 
};

class Canvas{
public:
  Canvas(size_t row, size_t col);
  ~Canvas(){}
  void Resize(size_t w, size_t h);
  bool DrawPixel(int x, int y, char brush);
  void Print();
  void Clear();
  Point GetCanvasSize() const{return canvas_size;}

private:
  vector<vector<char>> canvas;
  Point canvas_size;
};

Canvas::Canvas(size_t row, size_t col){
  canvas_size = Point(col, row);
  canvas.assign(row, vector<char>(col, '.'));
}

void Canvas::Resize(size_t w, size_t h){
  canvas_size = Point(w,h);
  canvas.assign(h,vector<char>(w,'.'));
}

bool Canvas::DrawPixel(int x, int y, char brush){
  if(x < canvas_size.x && y < canvas_size.y && x>=0&&y>=0){
    canvas[y][x] = brush;
    return true;
  }
  else return false;
}

void Canvas::Print(){
  cout<<' ';
  for(int i =0 ; i < canvas_size.x; i++) cout<<i%10;
  cout<<"\n";
  for(int y = 0; y < canvas_size.y; y++){
    cout<<y%10;
    for(int x = 0; x < canvas_size.x; x++){
      cout<<canvas[y][x];
    }
    cout<<'\n';
  }
  cout<<"\n";
}

void Canvas::Clear(){
  for(int r = 0; r < canvas_size.y; r++){
    for(int c = 0; c < canvas_size.x; c++){
      canvas[r][c] = '.';
    }
  }
}

class Shape{
public:
  virtual ~Shape(){}
  virtual void Draw(Canvas* canvas) = 0;
  virtual void PrintDump(){}

protected:
  string name;
  char brush;
  Point pos, size;
};

class Rectangle : public Shape{
public:
  Rectangle(Point _top_left, Point _size, char _brush){
    name = "rect";
    pos = _top_left;
    size = _size;
    brush = _brush;
  }

  void Draw(Canvas* canvas){
    for(int y = pos.y; y < pos.y+size.y; y++){
      for(int x = pos.x; x < pos.x+size.x; x++){
        canvas->DrawPixel(x,y,brush);
      }
    }
  }

  void PrintDump(){
    cout<<name<<" "<<pos.x<<" "<<pos.y<<" "<<size.x<<" "<<size.y<<" "<<brush<<"\n";
  }
};

class UpTriangle : public Shape{
public:
  UpTriangle(Point _top_center, int _height, char _brush){
    name = "tri_up";
    pos = _top_center;
    size = Point(0,_height);
    brush = _brush;
  }

  void Draw(Canvas* canvas){
    for(int y = pos.y; y < pos.y + size.y; y++){
      int line = y - pos.y;
      for(int x = pos.x-line; x<= pos.x+line; x++){
        canvas->DrawPixel(x,y,brush);
      }
    }
  }

  void PrintDump(){
    cout<<name<<" "<<pos.x<<" "<<pos.y<<" "<<size.y<<" "<<brush<<"\n";
  }
};

class DownTriangle : public Shape{
public:
  DownTriangle(Point _bottom_center, int _height, char _brush){
    name = "tri_down";
    pos = _bottom_center;
    size = Point(0,_height);
    brush = _brush;
  }

  void Draw(Canvas* canvas){
    for(int y = pos.y - size.y+1; y <= pos.y; y++){
      int line = pos.y-y;
      for(int x= pos.x-line; x<=pos.x+line; x++){
        canvas->DrawPixel(x,y,brush);
      }
    }
  }

  void PrintDump(){
    cout<<name<<" "<<pos.x<<" "<<pos.y<<" "<<brush<<"\n";
  }
};

class Diamond : public Shape{
public:
  Diamond(Point _top_center, int _dist_c, char _brush){
    name = "diamond";
    pos = _top_center;
    size = Point(0,_dist_c);
    brush = _brush;
  }

  void Draw(Canvas* canvas){
    for(int y = pos.y; y < pos.y+size.y*2+1; y++){
      int line;
      if(y<=pos.y+size.y){
        line = y-pos.y;
      }
      else{
        line = pos.y+size.y*2 - y;
      }
      for(int x = pos.x - line; x<= pos.x+line; x++){
        canvas->DrawPixel(x,y,brush);
      }
    }
  }

  void PrintDump(){
    cout<<name<<" "<<pos.x<<" "<<pos.y<<" "<<size.y<<" "<<brush<<"\n";
  }
};

int main(){
  vector<Shape*> shape_info;
  int x,y;
  cin>>x>>y;
  Canvas canvas(y,x);
  canvas.Print();

  string command;
  while(true){
    cin>>command;
    int x,y,w,h,d;
    char b;

    if(command == "add"){
      cin>>command;
      if(command == "rect"){
        cin>>x>>y>>w>>h>>b;
        shape_info.push_back(new Rectangle(Point(x,y),Point(w,h),b));
      }
      else if(command == "tri_up"){
        cin>>x>>y>>h>>b;
        shape_info.push_back(new UpTriangle(Point(x,y), h, b));
      }
      else if(command == "tri_down"){
        cin>>x>>y>>h>>b;
        shape_info.push_back(new DownTriangle(Point(x,y),h,b));
      }
      else if(command == "diamond"){
        cin>>x>>y>>d>>b;
        shape_info.push_back(new Diamond(Point(x,y),d,b));
      }
    }

    else if(command == "draw"){
      canvas.Clear();
      for(auto shape : shape_info){
        shape->Draw(&canvas);
      }
      canvas.Print();
    }

    else if(command == "dump"){
      for(size_t i = 0; i < shape_info.size(); i++){
        cout<<i<<" ";
        shape_info[i]->PrintDump();
      }
      cout<<"\n";
    }

    else if(command == "delete"){
      int index;
      cin>>index;
      if(index>=0 && index< shape_info.size()){
        delete shape_info[index];
        shape_info.erase(shape_info.begin() + index);
      }
    }

    else if(command == "resize"){
      int new_width, new_height;
      cin>>new_width>>new_height;
      canvas.Resize(new_width, new_height);
      canvas.Clear();
      for(auto shape : shape_info)shape->Draw(&canvas);
      canvas.Print();
    }

    else if(command == "quit")break;
  }

  for(auto shape : shape_info) delete shape;
  return 0;
}