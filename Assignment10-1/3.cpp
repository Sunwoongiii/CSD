#include <iostream>
#include <algorithm>
using namespace std;

class SortedArray{
  int size;
  int *p;
  void sort(){
    std::sort(p, p+size);
  }

public:
  SortedArray():size(0),p(nullptr){}

  SortedArray(const SortedArray& src) : size(src.size), p(new int[src.size]){
    std:copy(src.p, src.p+src.size,p);
  }

  SortedArray(int arr[], int n) : size(n), p(new int[n]){
    std::copy(arr, arr+n, p);
    sort();
  }

  ~SortedArray(){
    delete[] p;
  }

  SortedArray operator+(const SortedArray& op2){
    SortedArray result;
    result.size = size + op2.size;
    result.p = new int[result.size];
    std::copy(p,p+size,result.p);
    std::copy(op2.p, op2.p+op2.size, result.p+size);
    result.sort();
    return result;
  }

  SortedArray& operator=(const SortedArray& op2){
    if(this == &op2)return *this;
    delete[] p;
    size = op2.size;
    p = new int[size];
    std::copy(op2.p, op2.p+size, p);
    return *this;
  }

  void show()const{
    cout<<"Array: ";
    for(int i = 0; i < size; i++){
      cout<<p[i]<<" ";
    }
    cout<<endl;
  }
};

int main(){
  int n[] = {2,300,68};
  int m[] = {100,5,6,65};
  SortedArray a(n,3), b(m,4), c;

  c = a + b;
  
  a.show();
  b.show();
  c.show();
}