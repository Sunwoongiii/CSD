#include <iostream>

using namespace std;

int main(){
  string s;

  while(true){
    bool isDown = true;
    cout<<"Write lower case string: ";
    cin>>s;
    if(s == "EXIT") break;

    for(int i = 0; i < s.size(); i++){
      if(s[i] < 'a' || s[i] > 'z'){
        cout<<"\"warning\""<<"\n";
        isDown = false;
        break;
      }
    }

    if(isDown){
      for(int i=  0; i < s.size(); i++){
        s[i] -= 32;
        cout<<s[i];
      }
      cout<<"\n";
    }
  }
  return 0;
}