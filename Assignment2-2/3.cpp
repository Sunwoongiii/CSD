#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
  int t, cnt = 0;
  string word;
  cout<<"S = ";
  cin>>t;

  while(t>0){
    cin>>word;

    bool isLower = true;
    for(int i = 0; i <word.size(); i++){
      if(!islower(word[i])){
        isLower = false;
        break;
      }
    }

    if(!isLower){
      cout<<"\"warning\""<<"\n";
      continue;
    }

    bool alpha[26] = {false};
    alpha[word[0] - 'a'] = true;
    bool isGrouped = true;

    for(int i = 1; i < word.size(); i++){
      if(word[i] == word[i-1]) continue;
      if(alpha[word[i] - 'a']){
        isGrouped = false;
        break;
      }
      alpha[word[i] - 'a'] = true;
    }
    if(isGrouped){
      cnt++;
    }
    t--;
  }
  cout<<cnt;
}