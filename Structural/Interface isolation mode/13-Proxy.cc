/**
Proxy Pattern:
- Subject: An abstract class that declares the business methods implemented by
the real subject and the proxy object, through either an interface or an
abstract class.
- RealSubject: Defines the real object represented by the Proxy, which is the
actual object that the client ultimately wants to access.
- Proxy: Contains a reference to an instance of RealSubject, controls access to
RealSubject, and may be responsible for creating and deleting instances of
RealSubject.
*/

/**
**Problem Description**

Xiaoming wants to buy a house and has decided to seek the help of a real estate
agent to find a house with an area exceeding 100 square meters. Only houses that
meet this condition will be presented to Xiaoming for consideration.

**Input Description**

The first line is an integer \( N \) (1 ≤ \( N \) ≤ 100), representing the
number of houses available for viewing.

The next \( N \) lines each contain an integer, representing the area of the
corresponding house.

**Output Description**

For each house, output one line indicating whether it meets the purchase
condition. If the house area exceeds 100 square meters, output "YES"; otherwise,
output "NO".

**Input Example**

```
3
120
80
110
```

**Output Example**

```
YES
NO
YES
```
*/
#include <iostream>

// Subject
class HomePurchase {
public:
  virtual void requestPurchase(int area) = 0;
};

// RealSubject
class HomeBuyer : public HomePurchase {
public:
  void requestPurchase(int area) override { std::cout << "YES" << std::endl; }
};

// Proxy
class HomeAgentProxy : public HomePurchase {
private:
  HomeBuyer homeBuyer;

public:
  void requestPurchase(int area) override {
    if (area > 100) {
      homeBuyer.requestPurchase(area);
    } else {
      std::cout << "NO" << std::endl;
    }
  }
};

int main() {
  HomePurchase *buyerProxy = new HomeAgentProxy();

  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int area;
    std::cin >> area;
    buyerProxy->requestPurchase(area);
  }

  delete buyerProxy;

  return 0;
}