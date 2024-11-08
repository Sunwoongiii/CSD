#include <iostream>
using namespace std;

template <typename T>
class Container{
public:
  Container(){}
  virtual void push(T value) = 0;
  virtual T pop() = 0;
  virtual bool isEmpty()=0;
  virtual ~Container(){}
};

template <typename T>
class MyStack : public Container<T>{
private:
  T* arr;
  int top;
  int maxSize;

  void resize(){
    maxSize*=2;
    T* newArr = new T[maxSize];
    for(int i = 0; i <= top; i++){
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
  }

public:
  MyStack(int size):maxSize(size), top(-1){
    arr = new T[maxSize];
  }
  ~MyStack(){
    delete[] arr;
  }

  void push(T value)override{
    if(top == maxSize-1) resize();
    arr[++top] = value;
  }

  T pop()override{
    if(isEmpty()) return T();
    return arr[top--];
  }

  bool isEmpty()override{
    return top == -1;
  }
};

int main(){
  Container<int>* stack1 = new MyStack<int>(5);
  Container<double>* stack2 = new MyStack<double>(5);

  for(int i = 0; i < 10; i++){
    stack2->push(i*10+0.5);
    stack1->push(i*10);
  }

  for(int i = 0; i < 10; i++){
    int num = stack1->pop();
    cout<<num<<" ";
  }
  cout<<endl;

  for(int i = 0; i < 10; i++){
    double num_2 = stack2->pop();
    cout<<num_2<<" ";
  }
  cout<<endl;

  delete stack1;
  delete stack2;
  return 0;
}