#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

template<typename Container>
double calculate_median(Container container){
  using ValueType = typename Container::value_type;
  vector<ValueType> sorted_data(container.begin(), container.end());
  sort(sorted_data.begin(), sorted_data.end());

  size_t n = sorted_data.size();
  if(n%2 == 0) return (sorted_data[n/2-1]+sorted_data[n/2])/2.0;
  else return sorted_data[n/2];
}

template<>
double calculate_median<forward_list<double>>(forward_list<double> container){
  vector<double> sorted_data(container.begin(), container.end());
  sort(sorted_data.begin(), sorted_data.end());

  size_t n = sorted_data.size();
  if(n%2 == 0)return (sorted_data[n/2-1]+sorted_data[n/2])/2.0;
  else return sorted_data[n/2];
}

template <typename Container>
void print_stats(const Container& container){
  static_assert(is_arithmetic<typename Container::value_type>::value, "Container must hold numeric values.\n");
  
  if(container.empty()){
    cout<<"Container is empty. No statistics available.\n";
    return;
  }

  using ValueType = typename Container::value_type;
  ValueType min_value = numeric_limits<ValueType>::max();
  ValueType max_value = numeric_limits<ValueType>::lowest();

  double sum = 0.0;
  double sum_of_squares = 0.0;
  size_t cnt = 0;

  for(const auto& value : container){
    if(value < min_value)min_value = value;
    if(value > max_value)max_value = value;
    sum += value;
    sum_of_squares += value*value;
    ++cnt;
  }

  double mean = sum / cnt;
  double variance = sum_of_squares/cnt - mean*mean;
  double std_dev = sqrt(variance);
  double median = calculate_median(container);

  cout<<"Minimum: "<<min_value<<'\n';
  cout<<"Maximum: "<<max_value<<'\n';
  cout<<"Median: "<<median<<'\n';
  cout<<"Average: "<<mean<<'\n';
  cout<<"Variance: "<<variance<<'\n';
  cout<<"Standard Deviation: "<<std_dev<<'\n';
}

int main(){
  vector<double> vec = {1.2,3.4,2.5,7.8,5.6};
  deque<int>deq = {10,20,30,40,50};
  list<float> lst = {2.1f, 4.3f, 3.3f, 5.7f};
  forward_list<int>fwd_lst = {9,2,7,4,6};

  cout<<"Statistics for vector: \n";
  print_stats(vec);
  cout<<"\nStatistics for deque: \n";
  print_stats(deq);
  cout<<"\nStatistics for list:\n";
  print_stats(lst);
  cout<<"\nStatistics for forward_list:\n";
  print_stats(fwd_lst);

  return 0;
}