#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void mergeVectors(vector<vector<int>> &originalVector,
                  vector<vector<int>> &res) {
  if (originalVector.empty())
    return;
  sort(originalVector.begin(), originalVector.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

  res.push_back(originalVector[0]);

  for (int i = 1; i < originalVector.size(); ++i) {
    int currentStart = originalVector[i][0];
    int currentEnd = originalVector[i][1];
    int lastRes = res.back()[1];
    if (currentStart <= lastRes) {
      lastRes = max(lastRes, currentEnd);
    } else {
      res.push_back(originalVector[i]);
    }
  }
  return;
}

int main() {
  vector<vector<int>> originalVector = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> res;

  mergeVectors(originalVector, res);

  for (const auto &signalRes : res) {
    cout << "[" << signalRes[0] << "," << signalRes[1] << "]";
  }
  cout << endl;

  return 0;
}
