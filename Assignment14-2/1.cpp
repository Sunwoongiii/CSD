#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

int main () {
    vector<int> intList;
    cout << "Enter intList (type 'q' to finish): ";
    string input;
    while (true) {
        cin >> input;
        if (input == "q") {
            break;
        }
        intList.push_back(stoi(input));
    }

    int sum = accumulate(intList.begin(), intList.end(), 0);
    cout << "Sum of all elements: " << sum << endl;

    vector<int> even;
    copy_if (intList.begin(), intList.end(), back_inserter(even), [](int i) {
        return i % 2 == 0;
    });
    cout << "Even numbers: ";
    for_each(even.begin(), even.end(), [] (int i) {
        cout << i << " ";
    });
    cout << endl;
    
    sort(intList.begin(), intList.end(), [](int a, int b) {
        return a > b;
    });
    cout << "Sorted list in descending order: ";
    for_each(intList.begin(), intList.end(), [] (int i) {
        cout << i << " ";
    });
    cout << endl;
    return 0;
}