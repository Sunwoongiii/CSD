#include <cmath>
#include <iostream>
using namespace std;

class Distance{
  private:
    double _meter;
  public:
    Distance(){
      _meter = 0.0;
    }
    void setDis(double meter){
      this->_meter = meter;
    }
    double getDis(){
      return _meter;
    }
};

double addDis(double dis_1, double dis_2){
  return dis_1 + dis_2;
}

double subDis(double dis_1, double dis_2){
  double dis_3 = dis_1 - dis_2;
  return fabs(dis_3);
}

int main(){
  double dis_1, dis_2;
  cout<<"Enter distance1 value of meters: ";
  cin>>dis_1;
  cout<<"Enter distance2 value of meters: ";
  cin>>dis_2;

  Distance d1;
  Distance d2;

  d1.setDis(dis_1);
  d2.setDis(dis_2);
  cout<<"The sum between the two distances: "<<addDis(d1.getDis(), d2.getDis())<<"m\n";
  cout<<"The difference between the thwo distances: "<<subDis(d1.getDis(), d2.getDis())<<"m";
}