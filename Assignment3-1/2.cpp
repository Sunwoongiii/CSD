#include <iostream>

void mySwap(int*a, int& b){
  int temp = *a;
  *a = b;
  b = temp;
}

int main(){

  int x, y;
  std::cout<<"x: ";
  std::cin>>x;
  std::cout<<"y: ";
  std::cin>>y;

  std::cout<<"Before Swap - x: "<<x<<", y: "<<y<<std::endl;
  mySwap(&x,y); // mySwap(&x, &y);
  std::cout<<"Afer Swap - x: "<<x<<", y: "<<y<<std::endl;
}