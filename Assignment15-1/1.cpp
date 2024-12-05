#include <iostream>
using namespace std;

void func1(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void func2() {
    int *p = new int;
    delete p;
    // delete p;
    p = nullptr;
} 

void func3()
{
    int *ptr = new int(10);
    cout<<*ptr<<'\n';
    delete ptr;
    ptr = nullptr;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    func1(arr, 5);

    func3();

    return 0;
}