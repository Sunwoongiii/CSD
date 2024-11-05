#include <iostream>
using namespace std;

class HardwareB; 

class HardwareA {
  int specification;
public:
  HardwareA(int spec) : specification(spec) {}
  void setSpecification(int spec) { specification = spec; }
  void show() const { cout << "HardwareA: " << specification << endl; }
  friend void exchange(HardwareA& a, HardwareB& b);
  friend void exchange(HardwareA* a, HardwareB* b);
  friend void show(const HardwareA& a, const HardwareB& b);
};

class HardwareB {
  int specification;
public:
  HardwareB(int spec) : specification(spec) {}
  void setSpecification(int spec) { specification = spec; }
  void show() const { cout << "HardwareB: " << specification << endl; }
  friend void exchange(HardwareA& a, HardwareB& b);
  friend void exchange(HardwareA* a, HardwareB* b);
  friend void show(const HardwareA& a, const HardwareB& b);
};

void exchange(HardwareA& a, HardwareB& b) {
  int temp = a.specification;
  a.specification = b.specification;
  b.specification = temp;
}

void exchange(HardwareA* a, HardwareB* b) {
  int temp = a->specification;
  a->specification = b->specification;
  b->specification = temp;
}

void show(const HardwareA& a, const HardwareB& b) {
  cout << "HardwareA, HardwareB: " << a.specification << ", " << b.specification << endl;
}

int main() {
  HardwareA hardwareA(10);
  HardwareB hardwareB(20);
  show(hardwareA, hardwareB);
  exchange(hardwareA, hardwareB);
  show(hardwareA, hardwareB);
  exchange(&hardwareA, &hardwareB);
  show(hardwareA, hardwareB);
  return 0;
}
