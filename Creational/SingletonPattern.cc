/**
Singleton Pattern:
    1. A class has only one instance;
    2. Provides a global point of access to it.
*/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

class ShoppingCartManager {
public:
  static ShoppingCartManager &getInstance() {
    static ShoppingCartManager instance;
    return instance;
  }
  void addIntoCart(const string &itemName, int quantity) {
    if (ranges::find(orderLst, itemName) == orderLst.end()) {
      orderLst.emplace_back(itemName);
    }
    cart[itemName] += quantity;
  }
  void viewCart() const {
    for (const auto &item : orderLst) {
      cout << item << " " << cart.at(item) << endl;
    }
  }
  

private:
  ShoppingCartManager() {}
  vector<string> orderLst;
  unordered_map<string, int> cart;
};

int main() {
  ShoppingCartManager &cart = ShoppingCartManager::getInstance();
  string itemName;
  int quantity;
  while (cin >> itemName >> quantity) {
    cart.addIntoCart(itemName, quantity);
  }
  cart.viewCart();

  return 0;
}