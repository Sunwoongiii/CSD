#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class SortedArray{
  private:
    vector<int> numbers_;
  
  public:
    SortedArray(){}
    ~SortedArray(){}

    void AddNumber(int num){
      numbers_.push_back(num);
    }

    vector<int> GetSortedAscending(){
      vector<int> sorted = numbers_;
      sort(sorted.begin(), sorted.end());
      return sorted;
    }

    vector<int> GetSortedDescending(){
      vector<int>sorted = numbers_;
      sort(sorted.begin(), sorted.end(), greater<int>());
      return sorted;
    }

    int GetMax(){
      return *max_element(numbers_.begin(), numbers_.end());
    }

    int GetMin(){
      return *min_element(numbers_.begin(), numbers_.end());
    }
};

int main(){
  SortedArray sa;
  string input;
  
  while(true){
    getline(cin,input);
    
    if(input == "ascend"){
      vector<int>sorted = sa.GetSortedAscending();
      for(int num : sorted) cout<<num<<" ";
      cout<<"\n";
    }

    else if(input == "decend"){
      vector<int>sorted = sa.GetSortedDescending();
      for(int num : sorted) cout<<num<<" ";
      cout<<"\n";
    }

    else if(input == "max"){
      int maximum = sa.GetMax();
      cout<<maximum<<"\n";
    }

    else if(input == "min"){
      int minimum = sa.GetMin();
      cout<<minimum<<"\n";
    }

    else if(input == "quit") break;

    else{
      stringstream ss(input);
      int number;
      
      while(ss>>number)sa.AddNumber(number);
    }
  }
  return 0;
}