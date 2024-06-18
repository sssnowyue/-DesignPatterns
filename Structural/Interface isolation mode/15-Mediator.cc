/**
Mediator Pattern:
- Mediator: Declares methods used by components to communicate.
- ConcreteMediator: Implements the mediator interface and coordinates
communication between components.
- Component: Communicate with each other through the mediator.
*/
#include <iostream>
#include <string>

class Component1;
class Component2;

class Mediator {
public:
  virtual void notify(Component1 *sender, const std::string &event) const = 0;
  virtual void notify(Component2 *sender, const std::string &event) const = 0;
};

class Component1 {
private:
  Mediator *mediator;

public:
  Component1(Mediator *med) : mediator(med) {}

  void doA() {
    std::cout << "Component 1 does A.\n";
    mediator->notify(this, "A");
  }

  void doB() {
    std::cout << "Component 1 does B.\n";
    mediator->notify(this, "B");
  }
};

class Component2 {
private:
  Mediator *mediator;

public:
  Component2(Mediator *med) : mediator(med) {}

  void doC() {
    std::cout << "Component 2 does C.\n";
    mediator->notify(this, "C");
  }

  void doD() {
    std::cout << "Component 2 does D.\n";
    mediator->notify(this, "D");
  }
};

class ConcreteMediator : public Mediator {
private:
  Component1 *component1;
  Component2 *component2;

public:
  ConcreteMediator(Component1 *c1, Component2 *c2)
      : component1(c1), component2(c2) {}

  void notify(Component1 *sender, const std::string &event) const override {
    if (event == "A") {
      std::cout << "Mediator reacts on A and triggers following operations:\n";
      component2->doC();
    } else if (event == "B") {
      std::cout << "Mediator reacts on B and triggers following operations:\n";
      component2->doD();
    }
  }

  void notify(Component2 *sender, const std::string &event) const override {
    if (event == "C") {
      std::cout << "Mediator reacts on C and triggers following operations:\n";
      component1->doA();
    } else if (event == "D") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";
      component1->doB();
    }
  }
};

int main() {
  Component1 *c1 = new Component1(nullptr);
  Component2 *c2 = new Component2(nullptr);
  ConcreteMediator *mediator = new ConcreteMediator(c1, c2);

  c1->doA();
  c2->doC();
  c1->doB();
  c2->doD();

  delete c1;
  delete c2;
  delete mediator;

  return 0;
}
