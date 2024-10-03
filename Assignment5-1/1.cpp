#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
  int n;
  cout<<"N = \n";
  cin>>n;

  map<string, int>studentSocres;

  for(int i = 0; i < n; i++){
    string name;
    int score;
    cin>>name>>score;

    studentSocres[name] = score;
  }
  cout<<"Which student's score? \n";
  string qName;
  cin>>qName;

  if(studentSocres.find(qName) != studentSocres.end()){
    cout<<qName<<"'s score: "<<studentSocres[qName]<<"\n";
  }
  else{
    cout<<qName<<" is not in the database.";
  }
}