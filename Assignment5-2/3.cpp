#include <set>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// set<int> parseSet(const string& str);
// void printSet(const set<int>& set_);
// set<int> getUnion(const set<int>& set0, const set<int>& set1);
// set<int> getIntersection(const set<int>& set0, const set<int>& set1);
// set<int> getDifference(const set<int>& set0, const set<int>& set1);

set<int> parseSet(const string& str){
  set<int>result;
  stringstream ss(str);
  char ch;
  int num;

  while(ss >> ch){
    if(isdigit(ch) || ch == '-'){
      ss.putback(ch);
      ss>>num;
      result.insert(num);
    }
  }
  return result;
}

void printSet(const set<int>& set_){
  cout<<"{ ";
  for(int num : set_){
    cout<<num<<" ";
  }
  cout<<"}\n";
}

set<int> getUnion(const set<int>& set0, const set<int>& set1){
  set<int>result(set0);
  result.insert(set1.begin(), set1.end());
  return result;
}

set<int> getIntersection(const set<int>& set0, const set<int>& set1){
  set<int>result;
  for(int num : set0){
    if(set1.find(num) != set1.end()){
      result.insert(num);
    }
  }
  return result;
}

set<int> getDifference(const set<int>& set0, const set<int>& set1){
  set<int>result;
  for(int num : set0){
    if(set1.find(num) == set1.end()){
      result.insert(num);
    }
  }
  return result;
}

int main(){

  string input;
  while(true){
    getline(cin, input);
    if(input == "0")break;

    char operation = ' ';
    int location;

    for(int i = 0; i < input.length(); i++){
      if(input[i] == '+' || input[i] == '*'){
        operation = input[i];
        location = i;
        break;
      }
      else if(input[i] == '-'){
        if(i+1 < input.length() && isdigit(input[i+1])){
          continue;
        }
        else{
          operation = input[i];
          location = i;
          break;
        }
      }
    }

    string Set0 = input.substr(0,location);
    string Set1 = input.substr(location+1);
    // cout<<Set0<<"\n"<<Set1<<"\n";

    set<int>set0 = parseSet(Set0);
    set<int>set1 = parseSet(Set1);
    set<int>resultSet;

    if(operation == '+') resultSet = getUnion(set0,set1);
    else if(operation == '-') resultSet = getDifference(set0,set1);
    else if(operation == '*') resultSet = getIntersection(set0, set1);

    printSet(resultSet);
  }
  return 0;
}