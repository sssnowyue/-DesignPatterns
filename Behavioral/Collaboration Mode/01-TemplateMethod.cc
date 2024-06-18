/**
Template Method
- Abstract Class: Defines the skeleton of the algorithm, including:
    - a Template Method [stable] and
    - a series of `virtual` Abstract Methods [unstable]
- Concrete Class:
    Inherit the abstract class, `override` implements the abstract method, and
completes the specific steps in the algorithm
*/

/**
Jessica likes to taste different types of coffee. She found that the making
process of each coffee has some same steps. She decided to design a simple
coffee making system, using the template method pattern to define the coffee
making process. The system supports two coffee types: American Coffee and Latte.
The coffee making process includes the following steps:
1. Grinding coffee beans
2. Brewing coffee
3. Adding condiments Adding condiments
Among them, the methods of adding seasonings to Americano coffee and latte are
slightly different. Latte requires adding milk when adding seasonings.
*/
#include <iostream>
#include <string>
using namespace std;
// Abstract class
class Coffee {
public:
  // Constructor
  Coffee() {}
  // Destructor
  virtual ~Coffee() {}
  
  // Template method : Defining the coffee making process
  void makeCoffee() {
    grindCoffeeBeans();
    brewCoffee();
    addCondiments();
    cout << endl;
  }
  void grindCoffeeBeans() { cout << "Grinding coffee beans" << endl; }
  void brewCoffee() { cout << "Brewing coffee" << endl; }

protected:
  // Abstract Methods : Adding condiments
  virtual void addCondiments() = 0;
};

// Concrete Class 1 : American Coffee class
class AmericanCoffee : public Coffee {
public:
  void addCondiments() override { cout << "Adding condiments" << endl; }
};

// Concrete Class 2 : Latte class
class Latte : public Coffee {
public:
  void addCondiments() override {
    cout << "Adding milk" << endl;
    cout << "Adding condiments" << endl;
  }
};

int main() {
  string input;
  while (getline(cin, input)) {
    int coffeeType = stoi(input);
    cout << "Making ";
    if (coffeeType == 1) {
      cout << "American Coffee:" << endl;
      AmericanCoffee americanCoffee;
      americanCoffee.makeCoffee();
    } else if (coffeeType == 2) {
      cout << "Latte:" << endl;
      Latte latte;
      latte.makeCoffee();
    } else {
      cout << "Unknown Coffee Type" << endl;
    }
  }

  return 0;
}
