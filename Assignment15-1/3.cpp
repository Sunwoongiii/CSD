#include <iostream>
#include <limits>

int func1(int a, int b) {
    if(b==0)throw std::invalid_argument("Division by zero is not allowed.");
    return a/b;
}

int func2() {
    int i = std::numeric_limits<int>::max();
    if(i == std::numeric_limits<int>::max()) throw std::overflow_error("Integer overflow detected.");
    return i + 1;
}

void func3() {
    int *j = new int(42);
    std::cout << *j << std::endl;
    delete j;
}

int main() {
    try{
        int result1 = func1(10,0);
        std::cout<<result1<<std::endl;
    }
    catch(const std::exception& e){
        std::cerr<<"Error in func1: "<<e.what()<<std::endl;
    }

    try{
        int result2 = func2();
        std::cout<<result2<<std::endl;
    }
    catch(const std::exception& e){
        std::cerr<<"Error in func2: "<<e.what()<<std::endl;
    }
    return 0;
}
