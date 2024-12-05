#include <iostream>
#include <memory>
#include <vector>

int func1() {
    int x = 0;
    return x;
}

void func2() {
    int* ptr = nullptr;
    // std::cout << *ptr << std::endl;

    if(ptr)std::cout<<*ptr<<std::endl;
    else std::cout<<"Pointer is null, cannot dereference."<<std::endl;
}

int main() {
    int value = func1();
    std::cout << value << std::endl;
    
    func2();

    return 0;
}
