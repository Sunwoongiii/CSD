#include <iostream>

using namespace std;

string func(string str1 = "Hello", string str2 = "world", string str3 = ""){
  if(str3 == "") return str1 + " " + str2;
  else return str1 + " " + str2 + " " + str3;
}

int main(){
  string str_1 = func();
  string str_2 = func("hello", "Hanyng");
  string str_3 = func("Hello", "C++", "world");

  cout<<str_1<<endl;
  cout<<str_2<<endl;
  cout<<str_3<<endl;
}