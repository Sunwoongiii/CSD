#include <iostream>
#include <string>

using namespace std;

namespace selfIntro{
  void name(string var1){
    cout<<"Hello my name is "<<var1<<".\n";
  }
  void major(string var2){
    cout<<"My major is "<<var2<<".\n";
  }
  void studentID(string var3){
    cout<<"My student ID is "<<var3<<".\n";
  }
}

int main(){
  string name, major, studentID;
  cout<<"name: ";
  cin>>name;
  cout<<"major: ";
  cin>>major;
  cout<<"studentID: ";
  cin>>studentID;

  selfIntro::name(name);
  selfIntro::major(major);
  selfIntro::studentID(studentID);
}