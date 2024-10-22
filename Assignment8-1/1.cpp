#include <algorithm>
#include <iostream>
using namespace std;

class RangeCalc{
  virtual void read() = 0;
  virtual void write() const = 0;
  virtual int calculate() = 0;

protected:
  int result;

public:
  void run(){
    read();
    result = calculate();
    write();
  }
};

class RangeAdder : public RangeCalc{
  int x,y;

  void read()override{
    cout<<" Add Ints In Range: Sum all integer values between first and second input.\n";
    cout<<"Insert two integers >>";
    cin>>x>>y;
  }

  int calculate()override{
    int sum = 0;
    for(int i = min(x,y); i <= max(x,y); i++) sum+=i;
    return sum;
  }

  void write()const override{
    cout<<"The result is "<<result<<"\n";
  }
};

class RangeMultiplier : public RangeCalc{
  int x,y;
  
  void read()override{
    cout<<"Multiply Ints In Range: Multiply all integer values between first and second input.\n";
    cout<<"Insert two integers >>";
    cin>>x>>y;
  }

  int calculate()override{
    int product = 1;
    for(int i = min(x,y); i <= max(x,y); i++)product*=i;
    return product;
  }

  void write()const override{
    cout<<"The result is "<<result<<"\n";
  }

// public:
//   virtual ~RangeMultiplier(){}
};

int main(){
  RangeCalc *adder = new RangeAdder;
  adder->run();

  RangeCalc *multiplier = new RangeMultiplier;
  multiplier->run();

  delete adder;
  delete multiplier;

  return 0;
}