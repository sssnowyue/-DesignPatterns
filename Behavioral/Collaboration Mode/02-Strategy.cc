/**
Startegy pattern:
  Replaces `if else` and `switch case`
  - Strategy [Stable]: Defines a common interface for all supported algorithms
  - Concrete Strategy[Unstable]: Implements the strategy interface and provides specific algorithm implementation
  - Context [Stable]: Contains a strategy instance and calls methods of the strategy object when needed
*/

/**
A supermarket has launched different shopping discount strategies, and you can
choose different discount methods according to your needs. Among them, there are
two main preferential strategies:
1. 10% discount strategy: 90% of the original price.
2. Discount strategy: When you purchase a certain amount, you can enjoy
corresponding discounts. The specific full reduction rules are as follows:
    - 5 off for orders over 100
    - 15 off for orders over 150
    - 25 off for purchases over 200
    - 40 off for purchases over 300

Please design a shopping discount system. The user inputs the original price of
the product and the selected discount strategy number, and the system outputs
the calculated price.
*/

#include <iostream>
#include <vector>
using namespace std;

// Strategy Interface
class PricingStrategy {
public:
  PricingStrategy() {}
  virtual ~PricingStrategy() {}
  virtual int applyDiscount(int originalPrice) const = 0;
};

// Concrete Strategy 1
class TenPercentDiscount : public PricingStrategy {
public:
  int applyDiscount(int originalPrice) const override {
    return originalPrice * 0.9;
  }
};

// Concrete Strategy 2
class FullMinusDiscount : public PricingStrategy {
public:
  int applyDiscount(int originalPrice) const override {
    if (originalPrice >= 300) {
      return originalPrice - 40;
    } else if (originalPrice >= 200) {
      return originalPrice - 25;
    } else if (originalPrice >= 150) {
      return originalPrice - 15;
    } else if (originalPrice >= 100) {
      return originalPrice - 5;
    } else {
      return originalPrice;
    }
  }
};

// Context
class ShoppingCart {
public:
  ShoppingCart(const PricingStrategy *strat) : strategy(strat) {}
  ~ShoppingCart() {
    delete strategy; // Release the memory of the strategy
  }
  int applyDiscount(int originalPrice) const {
    return strategy->applyDiscount(originalPrice);
  }

private:
  const PricingStrategy *strategy;
};

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> purchases(N);
  for (int i = 0; i < N; ++i) {
    cin >> purchases[i].first >> purchases[i].second;
  }

  for (const auto &purchase : purchases) {
    const PricingStrategy *strategy;
    if (purchase.second == 1) {
      strategy = new TenPercentDiscount();
    } else if (purchase.second == 2) {
      strategy = new FullMinusDiscount();
    } else {
      cerr << "Invalid strategy code!" << endl;
      return 1;
    }
    ShoppingCart cart(strategy);
    cout << cart.applyDiscount(purchase.first) << endl;
  }

  return 0;
}
