#include <iostream>
using namespace std;

template <typename T>
T sum(T arr[], int size) {
  T total = 0;
  for (int i = 0; i < size; i++) {
    total += arr[i];
  }
  return total;
}

int main() {
  float fdata[5];
  int i = 0;
  
  cout << "\nInput 5 numbers >>" << endl;
  for (i = 0; i < 5; i++)
    cin >> fdata[i];
  
  cout << "\nSum of the above inputs is: " << sum(fdata, 5) << endl;
  
  return 0;
}
