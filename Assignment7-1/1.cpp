#include <iostream>
using namespace std;

class Calculator{
  void input(){
    cout<<"Input 2 integers >>";
    cin>>a>>b;
  }
protected:
  int a,b;
  virtual int calc(int a, int b) {return 0; }
public:
  void run(){
    input();
    cout<<"Answer: "<<calc(a,b)<<endl;
  }
};

class Adder : public Calculator{
protected:
  int calc(int a, int b) override{
    return a+b;
  }
};

class Subtractor : public Calculator{
protected:
  int calc(int a, int b) override{
    return a-b;
  }
};

int main(){
  Calculator *adder = new Adder;
  Calculator *subtractor = new Subtractor;

  adder ->run();
  subtractor->run();

  delete adder;
  delete subtractor;

  return 0;
}