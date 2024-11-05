#include <iostream>
#include <map>
#include <string>
using namespace std;

class TestProblem {
private:
  map<string, int> subScore;
  int problemScore;
  static int totalScore;

public:
  TestProblem() : problemScore(0) {
    subScore["subScore1"] = 0;
    subScore["subScore2"] = 0;
  }

  TestProblem(const TestProblem& testProblem) : subScore(testProblem.subScore), problemScore(testProblem.problemScore) {}

  void setSubScore(string key, int _score) {
    if (_score >= 0 && _score <= 50) {
      problemScore -= subScore[key];
      subScore[key] = _score;
      problemScore += _score;
      totalScore += _score;
    } else {
      cout << "Error" << endl;
    }
  }

  int getProblemScore() const {
    return problemScore;
  }

  void show() const {
    for (const auto& item : subScore) {
      cout << item.first << ": " << item.second << endl;
    }
  }

  static void showTotalScore() {
    cout << "total score: " << totalScore << endl;
  }
};

int TestProblem::totalScore = 0;

int main() {
  TestProblem problem1;
  TestProblem problem2 = problem1;
  
  problem1.setSubScore("subScore1", 30);
  problem1.setSubScore("subScore2", 40);
  problem2.setSubScore("subScore1", 20);
  problem2.setSubScore("subScore2", 40);
  
  problem1.show();
  cout << "problem1 score: " << problem1.getProblemScore() << endl;
  
  problem2.show();
  cout << "problem2 score: " << problem2.getProblemScore() << endl;
  
  TestProblem::showTotalScore();
  
  return 0;
}
