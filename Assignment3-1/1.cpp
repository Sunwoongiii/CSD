#include <iostream>
#include <iomanip>

using namespace std;

int n;

void Max(int* arr, int* max){
  *max = arr[0];
  for(int i = 1; i < n; i++){
    if(arr[i] > *max){
      *max = arr[i];
    }
  }
}

void Min(int* arr, int* min){
  *min = arr[0];
  for(int i = 1; i < n; i++){
    if(arr[i] < *min) *min = arr[i];
  }
}

void Average(int* arr, double* ave){
  double sum = 0;
  for(int i = 0; i < n; i++){
    sum+=arr[i];
  }
  *ave = sum / n;
}

int main(){
  cin>>n;
  int*arr = new int[n];
  int max, min;
  double ave;

  for(int i = 0; i < n; i++) cin>>arr[i];

  Max(arr, &max);
  Min(arr, &min);
  Average(arr, &ave);

  cout<<"Max: "<<max<<"\n";
  cout<<"Min: "<<min<<"\n";
  cout<<fixed<<setprecision(6);
  cout<<"Average: "<<ave<<"\n";
  delete[] arr;
  return 0;
}