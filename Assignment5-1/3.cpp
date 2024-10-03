#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

string str,word;
map<string, int>m;

int main(){
  getline(cin,str);
  
  stringstream ss(str);
  while(ss >> word){
    m[word]++;
  }
  
  for(const auto& pair: m){
    cout<<pair.first<<": "<<pair.second<<"\n";
  }
}