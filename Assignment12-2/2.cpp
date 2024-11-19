#include <iostream>
using namespace std;

class MyException {
public:
  void report() {
    cout << "Exception report" << endl;
  }
};

class MyArray {
private:
  int* my_array;
  int maxSize;

public:
  MyArray(int size) : maxSize(size) {
    my_array = new int[maxSize];
  }

  ~MyArray() {
    delete[] my_array;
  }

  int& operator[](const int& index) {
    if (index < 0 || index >= maxSize) {
      throw MyException();
    }
    return my_array[index];
  }
};

int main() {
  MyArray myArray(5);
  try {
    myArray[20];
  } catch (MyException& e) {
    e.report();
  }

  return 0;
}
