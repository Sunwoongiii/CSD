#include <iostream>
#include <istream>

using namespace std;

int main(){
  string name,major,studentID;

  cout<<"name: ";
  getline(cin, name);
  cout<<"major: ";
  getline(cin, major);
  cout<<"studentID: ";
  cin>>studentID;

  cout<<"Hello. My name is "<<name<<".\n";
  cout<<"My major is "<<major<<".\n";
  cout<<"My student ID is "<<studentID<<".\n";
  return 0;
}