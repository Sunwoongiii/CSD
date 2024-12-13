#include <iostream>
#include <cstring>
using namespace std;

class Container {
public:
  virtual void push_back(int value) = 0;
  virtual void pop_back() = 0;
  virtual int getVectorArr(int index) = 0;
  virtual void setVectorArr(int index, int value) = 0;
  virtual ~Container() {}
};

class MyVector : public Container {
private:
  int* data;
  int size;
  int capacity;

  void resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; i++) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
  }

public:
  MyVector(int initialCapacity) : size(0), capacity(initialCapacity) {
    data = new int[capacity];
  }

  ~MyVector() {
    delete[] data;
  }

  void push_back(int value) override {
    if (size == capacity) {
      resize();
    }
    data[size++] = value;
  }

  void pop_back() override {
    if (size == 0) {
      throw "nothing to pop";
    }
    size--;
  }

  int getVectorArr(int index) override {
    if (index < 0 || index >= size) {
      throw "Out of range error";
    }
    return data[index];
  }

  void setVectorArr(int index, int value) override {
    if (index < 0 || index >= size) {
      throw "Out of range error";
    }
    data[index] = value;
  }
};

int main() {
  Container* v = new MyVector(5);

  for (int i = 0; i < 10; i++) {
    v->push_back(i * 10);
  }

  try {
    v->setVectorArr(11, 20); 
  } catch (const char* msg) {
    cerr << msg << endl;
  }

  for (int i = 9; i >= 0; i--) {
    try {
      cout << v->getVectorArr(i) << " ";
    } catch (const char* msg) {
      cerr << msg << endl;
    }
  }
  cout << endl;

  for (int j = 0; j < 11; j++) {
    try {
      v->pop_back();
    } catch (const char* msg) {
      cerr << msg << endl;
    }
  }

  delete v;
  return 0;
}
