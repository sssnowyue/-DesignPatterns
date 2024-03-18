/**
Decorator Pattern:
- Component: 
    - An interface.
- Concrete Component: 
    - Implements Component;
- Decorator: 
    - Holds a reference to a component object;
    - Defines an interface consistent with Component.
- Concrete Decorator: 
    - Implements Decorator : Adds new decorations(responsibilities) to the component object.
*/
/**
Jack enjoys tasting coffee with different flavors. He found that each type of
coffee can be enhanced with different additives, such as milk, sugar, and
chocolate. He decided to use the decorator pattern to create his favorite
coffee. Please design a simple coffee making system that uses the decorator
pattern to add different additives to the coffee. The system supports two types
of coffee: Black Coffee and Latte.

Input Description:
Multiple lines of input, each containing two numbers. The first number
represents the choice of coffee (1 for Black Coffee, 2 for Latte), and the
second number represents the type of additive to be added (1 for milk, 2 for
sugar).

Output Description: For each line of input, output the process of making
coffee, including the type of coffee and the additives added.

Input Example:
1 1
2 2

Output Example:
Brewing Black Coffee
Adding Milk
Brewing Latte
Adding Sugar
*/
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Component
class Coffee {
public:
  virtual string makingCoffee() const = 0;
  virtual ~Coffee() = default;
};

// Concrete Component 1 : Black Coffee
class BlackCoffee : public Coffee {
public:
  string makingCoffee() const override { return "Brewing Black Coffee"; }
};

// Concrete Component 2 : Latte
class Latte : public Coffee {
public:
  string makingCoffee() const override { return "Brewing Latte"; }
};

// Decorator : For adding condiments
class CondimentDecorator : public Coffee {
public:
  // Pointer to (Concrete) Component objects
  CondimentDecorator(unique_ptr<Coffee> coffee) : coffee(move(coffee)) {}
  string makingCoffee() const override { return coffee->makingCoffee(); }

protected:
  unique_ptr<Coffee> coffee;
};

// Concrete Decorator 1 : adding Milk
class MilkDecorator : public CondimentDecorator {
public:
  using CondimentDecorator::CondimentDecorator;
  string makingCoffee() const override {
    return CondimentDecorator::makingCoffee() + "\nAdding Milk";
  }
};

// Concrete Decorator 2 : adding Sugar
class SugarDecorator : public CondimentDecorator {
public:
  using CondimentDecorator::CondimentDecorator;
  string makingCoffee() const override {
    return CondimentDecorator::makingCoffee() + "\nAdding Sugar";
  }
};

int main() {
  int coffeeChoice, condimentChoice;
  while (cin >> coffeeChoice >> condimentChoice) {
    unique_ptr<Coffee> coffee;

    // Select the type of coffee
    if (coffeeChoice == 1)
      coffee = make_unique<BlackCoffee>();
    else if (coffeeChoice == 2)
      coffee = make_unique<Latte>();

    // Add condiments
    if (condimentChoice == 1)
      coffee = make_unique<MilkDecorator>(move(coffee));
    else if (condimentChoice == 2)
      coffee = make_unique<SugarDecorator>(move(coffee));

    // Output the coffee making process
    cout << coffee->makingCoffee() << endl;
  }

  return 0;
}
