#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class MessageBook{
  private:
    map<int,string> messages_;
  public:
    MessageBook(){}
    ~MessageBook(){}

    void AddMessage(int number, const string&message){
      messages_[number] = message;
    }
    void DeleteMessage(int number){
      messages_.erase(number);
    }
    vector<int> GetNumbers(){
      vector<int>numbers;
      for(const auto& pair : messages_){
        numbers.push_back(pair.first);
      }
      return numbers;
    }
    const string& GetMessage(int number){
      static const string empty_string = "";
      if(messages_.find(number) != messages_.end()){
        return messages_[number];
      }
      return empty_string;
    }
};

int main(){
  int number;
  string command, message;
  MessageBook mb;

  while(true){
    cin>>command;

    if(command == "add"){
      cin>>number;
      cin.ignore();
      getline(cin, message);
      mb.AddMessage(number, message);
    }
    else if(command == "delete"){
      cin>>number;
      mb.DeleteMessage(number);
    }
    else if(command == "print"){
      cin>>number;
      cout<<mb.GetMessage(number)<<"\n\n";
    }
    else if(command == "list"){
      vector<int>numbers = mb.GetNumbers();
      for(int num : numbers){
        cout<<num<<" : "<<mb.GetMessage(num)<<"\n";
      }
    }
    else if(command == "quit") break;
  }
  return 0;
}