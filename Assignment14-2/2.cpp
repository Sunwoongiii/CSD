#include <iostream>
#include <utility>
#include <cstring>

using namespace std;

class StringWrapper {
    char* str;

    public:
        StringWrapper() : str(nullptr) {}
        StringWrapper(const char* s) {
            if (s) {
                str = new char[strlen(s)+1];
                strcpy(str, s);
            }
            else {
                str = nullptr;
            }
        }
        StringWrapper(const StringWrapper& other) {
            if (other.str) {
                str = new char[strlen(other.str)+1];
                strcpy(str, other.str);
            }
            else {
                str = nullptr;
            }
            cout << "Copy constructor called.\n";
        }
        StringWrapper(StringWrapper&& other) noexcept : str(other.str) {
            other.str = nullptr;
            cout << "Move constructor called.\n";
        }
        StringWrapper& operator=(const StringWrapper& other) {
            if (this != &other) {
                delete[] str;
                if (other.str) {
                    str = new char[strlen(other.str)+1];
                    strcpy(str, other.str);
                }
                else {
                    str = nullptr;
                }
                cout << "Copy assignment operator called.\n";
            }
            return *this;
        }
        StringWrapper& operator=(StringWrapper&& other) noexcept {
            if (this != &other) {
                delete[] str;
                str = other.str;
                other.str = nullptr;
                cout << "Move assignment operator called.\n";
            }
            return *this;
        }
        ~StringWrapper() {
            delete[] str;
        }
        friend ostream& operator<< (ostream& os, const StringWrapper& sw) {
            if (sw.str) {
                os << sw.str;
            }
            else {
                os << "null";
            }
            return os;
        }
};

int main()
{
    StringWrapper sw1("Hello World");
    std::cout << "sw1: " << sw1 << std::endl;
    // Copy constructor
    StringWrapper sw2 = sw1;
    std::cout << "sw2 (after copy): " << sw2 << std::endl;
    // Move constructor
    StringWrapper sw3 = std::move(sw1);
    std::cout << "sw1 (after move): " << sw1 << std::endl;
    std::cout << "sw3 (after move): " << sw3 << std::endl;
    // Copy assignment operator
    StringWrapper sw4;
    sw4 = sw2;
    std::cout << "sw4 (after copy assignment): " << sw4 << std::endl;
    // Move assignment operator
    StringWrapper sw5;
    sw5 = std::move(sw2);
    std::cout << "sw2 (after move assignment): " << sw2 << std::endl;
    std::cout << "sw5 (after move assignment): " << sw5 << std::endl;
    return 0;
}