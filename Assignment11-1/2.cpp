#include <iostream>
using namespace std;

template <typename T>
void reverseArray(T arr[], int size) {
  for (int i = 0; i < size / 2; i++) {
    T temp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = temp;
  }
}

int main() {
  int x[] = {1, 10, 100, 3, 5};
  reverseArray(x, 5);

  for (int i = 0; i < 5; i++)
    cout << x[i] << " ";
  
  return 0;
}
