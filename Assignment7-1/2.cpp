#include <iostream>
#include <string>
using namespace std;

class Converter{
protected:
  double _ratio;

  virtual double convert(double src) {return 0;}
  virtual string getSrcMetric(){return "";}
  virtual string getDestMetric(){return "";}

public:
  Converter(double ratio): _ratio(ratio){}

  double getRatio() const {return _ratio;}

  void run(){
    double src;
    cout<<"Converter "<<getSrcMetric()<<" to "<<getDestMetric()<<endl;
    cout<<"Input "<<getSrcMetric()<<" : ";
    cin>>src;
    cout<<"Result: "<<convert(src)<<" "<<getDestMetric()<<endl;
  }
};

class KmToMile : public Converter{
public:
  KmToMile(double ratio):Converter(ratio){}
protected:
  double convert(double src) override{
    return src* _ratio;
  }
  string getSrcMetric() override{return "km";}
  string getDestMetric() override{return "mile";}
};

int main(){
  Converter *ktm = new KmToMile(0.621371);
  ktm->run();
  delete ktm;

  return 0;
}