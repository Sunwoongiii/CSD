#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Container{
public:
  virtual void push_back(int value) = 0;
  virtual void pop_back() = 0;
  virtual int front() = 0;
  virtual int back() = 0;
  virtual int getVectorArr(int index) = 0;
  virtual void setVectorArr(int index, int value) = 0;
  virtual ~Container(){}
};

class MyVector : public Container{
private:
  int* arr;
  int size;
  int count;

public:
  MyVector(int s): size(s), count(0){
    arr = new int[size];
  }
  virtual void push_back(int value)override{
    if(count == size){
      int newSize = size*2;
      int* newArr = new int[newSize];
      for(int i = 0; i < size; i++){
        newArr[i] = arr[i];
      }

      delete[] arr;
      arr = newArr;
      size = newSize;
    }
    arr[count++] = value;
  }

  virtual void pop_back()override{
    if(count > 0)count--;
    else cout<<"error\n";
  }

  virtual int front()override{
    if(count>0){
      return arr[0];
    }
    else{
      cout<<"error\n";
      exit(EXIT_FAILURE);
    }
  }

  virtual int back()override{
    if(count>0)return arr[count-1];
    else{
      cout<<"error\n";
      exit(EXIT_FAILURE);
    }
  }

  virtual int getVectorArr(int index)override{
    if(index >= count){
      cout<<"error\n";
      exit(EXIT_FAILURE);
    }
    else{
      return arr[index];
    }
  }

  virtual void setVectorArr(int index, int value)override{
    if(index>= 0 && index <count){
      arr[index] = value;
    }
    else{
      cout<<"error\n";
      exit(EXIT_FAILURE);
    }
  }

  ~MyVector(){
    delete[] arr;
  }
};

int main(){
  Container* v = new MyVector(5);

  for(int i = 0; i < 10; i ++){
    v->push_back(i*10);
  }

  cout<<v->front()<<endl;
  cout<<v->back()<<endl;
  cout<<v->getVectorArr(3)<<endl;

  v->setVectorArr(3,20);
  cout<<v->getVectorArr(3)<<endl;

  for(int j = 0; j < 10; j ++){
    cout<<v->back()<<" ";
    v->pop_back();
  }

  delete v;
  return 0;
}