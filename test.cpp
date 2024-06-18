#include <functional>
#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename Func>
void insertionSort(vector<T> &arr, Func cmp) {
  int n = arr.size();
  for (int i = 1; i < n; ++i) {
    T key = arr[i];
    int j = i - 1;
    while (j >= 0 && cmp(key, arr[j])) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {
  vector<string> arrStr = {"asa", "dsasd", "jhksd", "adsd"};
  auto orderCmp = [](const string &a, const string &b) {
    return a.size() < b.size();
  };

  insertionSort(arrStr, orderCmp);

  for (const auto &str : arrStr) {
    cout << str << ", ";
  }
  cout << endl;

  return 0;
}
