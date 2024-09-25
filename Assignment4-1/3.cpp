#include <iostream>
#include <string>

using namespace std;

class student{
  private:
    string _name;
    string _major;
    string _studentID;

  public:
    Student(){
      _name = "";
      _major = "";
      _studentID = "";
    }
    
    void setName(string name);
    void setMajor(string major);
    void setStudentID(string studentID);
    void showStudentInfo();
};

void student::setName(string name){
  _name = name;
}

void student::setMajor(string major){
  _major = major;
}

void student::setStudentID(string studentID){
  _studentID = studentID;
}

void student::showStudentInfo(){
  cout<<_name<<" / "<<_major<<" / "<<_studentID<<"\n";
}

int main(){
  string name, major, studentID;

  cout<<"Name: ";
  getline(cin, name);
  cout<<"Major: ";
  getline(cin, major);
  cout<<"StudentID: ";
  cin>>studentID;

  student firstStudent;
  firstStudent.setName(name);
  firstStudent.setMajor(major);
  firstStudent.setStudentID(studentID);

  firstStudent.showStudentInfo();

  return 0;
}