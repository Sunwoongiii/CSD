#include <iostream>
#include <vector>
using namespace std;

template <typename InputIt, typename OutputIt>
void MyCopy(InputIt first, InputIt last, OutputIt result){
  while(first!=last){
    *result = *first;
    ++first;
    ++result;
  }
}

template <typename InputIt1, typename InputIt2, typename OutPutIt>
void MyMerge(InputIt1 first_1, InputIt1 last_1, InputIt2 first_2, InputIt2 last_2, OutPutIt result){
  while(first_1 != last_1 && first_2 != last_2){
    if(*first_1 < *first_2){
      *result = *first_1;
      ++first_1;
    }
    else{
      *result = *first_2;
      ++first_2;
    }
    ++result;
  }

  while(first_1 != last_1){
    *result = *first_1;
    ++first_1;
    ++result;
  }
  while(first_2 != last_2){
    *result = *first_2;
    ++first_2;
    ++result;
  }
}

int main(){
  int first[] = {5,10,15,20,25};
  int second[] = {10,20,30,40,50};
  vector<int> myVector(5);
  vector<int> v(10);

  MyCopy(first, first+5, myVector.begin());
  cout<<"myVector contains:";
  for(vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
    cout<<' '<<*it;
  cout<<endl;

  MyMerge(first, first+5, second, second+5, v.begin());
  cout<<"the resulting vector contains: ";
  for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    cout<<' '<<*iter;
  cout<<'\n';

  return 0;
}