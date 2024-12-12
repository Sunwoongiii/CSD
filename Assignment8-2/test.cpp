#include <iostream>
using namespace std;

class Container{
public:
  Container(){}
  virtual void push_back(int value)=0;
  virtual void pop_back()=0;
  virtual int getVectorArr(int index)=0;
  virtual void setVectorArr(int index, int value)=0;
  virtual ~Container(){}
};

class MyVector : public Container {
private:
    int size;
    int cnt;
    int* arr;
public:
    MyVector(int s) : size(s), cnt(0) {
        arr = new int[size];
    }

    virtual void push_back(int value) override {
        if (cnt == size) {
            int* new_arr = new int[size * 2];
            for (int i = 0; i < size; i++) {
                new_arr[i] = arr[i];
            }
            size *= 2;
            delete[] arr;
            arr = new_arr;
        }

        arr[cnt] = value;
        cnt++;
    }

    virtual void pop_back() override {
        if (cnt == 0) throw "Nothing to pop\n";
        cnt--;
    }

    virtual int getVectorArr(int index) override {
        if (index >= 0 && index < cnt) return arr[index];
        else throw "Out of range error\n";
    }

    virtual void setVectorArr(int index, int value) override {
        if (index >= 0 && index < cnt) arr[index] = value;
        else throw "Out of range error\n";
    }

    virtual ~MyVector() {
        delete[] arr;
    }
};

int main() { 
  Container* v = new MyVector(5); 
  for (int i = 0; i < 10; i++) { 
      v->push_back(i * 10); 
  } 
  try { 
      v->setVectorArr(11, 20); 
      cout << v->getVectorArr(10) << endl; 
  } catch (const char* msg) { 
      cerr << msg << endl; 
  } 
  for (int j = 0; j < 11; j++) { 
      try { 
          v->pop_back(); 
      } catch (const char* msg) { 
          cerr << msg << endl; 
      } 
  } 
  cout << endl; 
}