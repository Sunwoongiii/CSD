#include <iostream>
#include <memory>
#include <string>
using namespace std;

class CleaningUp {
  private:
    string word;
  public:
    CleaningUp(const string& str) : word(str) {
      cout << "Created word: " << word << endl;
    }
    ~CleaningUp() {
      cout << "Destroyed word: " << word << endl;
    }
};

void ThrowsException() {
  CleaningUp hi("HI");
  unique_ptr<int> pi(new int);
  throw "Exception";
  CleaningUp bye("BYE");
}

int main() {
  try {
    ThrowsException();
  } catch (const char* e) {
    cout << "Caught an exception" << endl;
  }
  return 0;
}
