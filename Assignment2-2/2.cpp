#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  int IOI = 0, OI = 0, t = 2;
  bool isUp = true;

  while(true){
    isUp = true;
    IOI = 0, OI = 0;
    cout<<"S = ";
    cin>>s;

    for(int i = 0; i < s.size(); i++){
      if(s[i] < 'A' || s[i] > 'Z'){
        cout<<"\"Warning\""<<"\n\n";
        isUp = false;
        break;
      }
    }

    if(isUp){
      for(int i = 0; i < s.size(); i++){
        if(i+2 < s.size() && s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I'){
          IOI++;
          i++;
        }
      }
      for(int i = 0; i < s.size(); i++){
        if(i+1 < s.size() && s[i] == 'O' && s[i+1] == 'I'){
          OI++;
          i++;
        }
      }
      t--;
      cout<<IOI<<"\n"<<OI<<"\n\n";
      if(t == 0) return 0;
    }
  }
  return 0;
}