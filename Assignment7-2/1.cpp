#include <iostream>
using namespace std;

class Container{
public:
  Container(){}

  virtual void push(int value){}
  virtual int pop(){return 0;}
  virtual bool isEmpty(){return false;}
  virtual ~Container(){}
};

class MyStack : public Container{
private:
  int *stackArray, top, capacity;

  void resize(){
    int *newArray = new int[capacity*2];
    for(int i = 0; i < capacity; i++) newArray[i] = stackArray[i];
    delete[] stackArray;
    stackArray = newArray;
    capacity*=2;
    // delete[] newArray;
  }

public:
  MyStack(int size): capacity(size), top(-1){
    stackArray = new int[capacity];
  }
  virtual ~MyStack(){
    delete[] stackArray;
  }
  void push(int value) override{
    if(top == capacity - 1) resize();
    stackArray[++top] = value;
  }
  int pop()override{
    if(isEmpty()) return -1;
    return stackArray[top--];
  }
  bool isEmpty()override{
    return top == -1;
  }
};

class MyQueue : public Container{
private:
  int *queueArray,capacity,front,rear,size;

  void resize(){
    int *newArray = new int[capacity*2];
    for(int i = 0; i < capacity; i++) newArray[i] = queueArray[i];
    delete[] queueArray;
    queueArray = newArray;
    front = 0;
    rear = size -1;
    capacity *= 2;
    // delete[] newArray;
  }

public:
  MyQueue(int size): capacity(size),front(0),rear(-1),size(0){
    queueArray = new int[capacity];
  }
  virtual ~MyQueue(){
    delete[] queueArray;
  }
  void push(int value)override{
    if(size == capacity) resize();
    rear = (rear+1)%capacity;
    queueArray[rear] = value;
    size++;
  }
  int pop()override{
    if(isEmpty())return-1;
    int value = queueArray[front];
    front = (front+1)%capacity;
    size--;
    return value;
  }
  bool isEmpty()override{
    return size == 0;
  }
};

int main(){
  Container *myStack = new MyStack(5);
  Container *myQueue = new MyQueue(5);

  for(int i=0;i<10;i++){
    myStack->push(i*10);
    myQueue->push(i*10);
  }
  for(int i=0;i<10;i++){
    int n=myStack->pop();
    cout<<n<<" ";
  }
  cout<<endl;

  for(int i=0;i<10;i++){
    int n = myQueue->pop();
    cout<<n<<" ";
  }
  cout<<"\n";

  delete myStack;
  delete myQueue;

  return 0;
}