#include <iostream>
#include <string>
using namespace std;

int checkN() {
  int num;
  cout << "S = ";
  cin >> num;

  if (num <= 0 || num > 100) {
    throw "Out of range error.";
  }

  return num;
}

bool isGroupWord(const string& input) {
  bool seen[26] = {false};
  char prev = '\0';

  for (char ch : input) {
    if (prev != ch) {
      if (seen[ch - 'a']) {
        return false;
      }
      seen[ch - 'a'] = true;
    }
    prev = ch;
  }
  return true;
}

int main() {
  int N, cnt = 0;

  try {
    N = checkN();
  } catch (const char* msg) {
    cerr << msg << endl;
    return 1;
  }

  for (int i = 0; i < N; i++) {
    string input;

    while (true) {
      bool isValid = true;
      cin >> input;

      for (char ch : input) {
        if (ch < 'a' || ch > 'z') {
          cout << "warning" << endl;
          isValid = false;
          break;
        }
      }

      if (isValid) {
        break;
      }
    }

    if (isGroupWord(input)) {
      cnt++;
    }
  }

  cout << "Output: " << cnt << endl;
  return 0;
}
