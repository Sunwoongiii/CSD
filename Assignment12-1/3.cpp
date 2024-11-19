#include <iostream>
#include <string>
using namespace std;

class NegativeValueException {
public:
  void print() const {
    cout << "Exception! Cannot convert negative value" << endl;
  }
};

class Converter {
protected:
  double _ratio;
  virtual double convert(double src) = 0;
  virtual string getSrcMetric() = 0;
  virtual string getDestMetric() = 0;
public:
  Converter(double ratio) : _ratio(ratio) { }
  
  void run() {
    double src;
    cout << "Convert " << getSrcMetric() << " to " << getDestMetric() << endl;
    cout << "Input " << getSrcMetric() << " : ";
    cin >> src;

    try {
      if (src < 0) {
        throw NegativeValueException();
      }
      cout << "Result : " << convert(src) << getDestMetric() << endl;
    }
    catch (NegativeValueException &e) {
      e.print();
    }
  }
};

class DollarToWon : public Converter {
public:
  DollarToWon(double ratio = 0.0) : Converter(ratio) {}

  double convert(double src) override {
    if (src < 0) {
      throw NegativeValueException();
    }
    return src * _ratio;
  }

  string getSrcMetric() override {
    return "dollar";
  }

  string getDestMetric() override {
    return "won";
  }
};

int main() {
  DollarToWon dtw(1176.5);
  dtw.run();
  return 0;
}
