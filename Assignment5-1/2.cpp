#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void mergeContainers(vector<int>& container1, const vector<int>& container2) {
  container1.insert(container1.end(), container2.begin(), container2.end());
}

void mergeContainers(list<int>& container1, const list<int>& container2) {
  container1.insert(container1.end(), container2.begin(), container2.end());
}

void mergeContainers(deque<int>& container1, const deque<int>& container2) {
  container1.insert(container1.end(), container2.begin(), container2.end());
}

void mergeContainers(set<int>& container1, const set<int>& container2) {
  container1.insert(container2.begin(), container2.end());
}

void mergeContainers(map<int, int>& container1, const map<int, int>& container2) {
  for(const pair<const int, int>& pair : container2){
    if(container1.find(pair.first) == container1.end()){
      container1.insert(pair);
    }
  }
}
