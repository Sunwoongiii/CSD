#include <iostream>

using namespace std;

class Cat{
  private:
    int _age;
    int _weight;
  
  public:
    void showCatInfo(){
      cout<<"Age: "<<_age<<" months\n";
      cout<<"Weight: "<<_weight<<" kg\n";
    }
    Cat(int age, int weight):_age(age), _weight(weight){}
};

int main(){
  int age, weight;

  cout<<"Age: ";
  cin>>age;
  cout<<"Weight: ";
  cin>>weight;

  Cat myCat(age, weight);
  myCat.showCatInfo();

  return 0;
}