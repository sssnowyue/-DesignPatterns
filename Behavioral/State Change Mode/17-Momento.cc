/*
Momento Pattern:
- `Memento`: Stores the internal state of the `Originator` object
- `Originator`: Creates a memento containing a snapshot of its current internal state and uses the memento to restore its internal state.
- `Caretaker`: Responsible for keeping the memento. It never operates on or examines the contents of a memento.
*/
#include <iostream>
#include <string>
#include <vector>

class Memento {
private:
  int state;

public:
  Memento(int state) : state(state) {}
  int getState() const { return state; }
};

class Counter {
private:
  int value;
  std::vector<Memento> history;
  int current;

public:
  Counter() : value(0), current(-1) {}

  void increment() {
    value++;
    saveState();
    std::cout << value << std::endl;
  }

  void decrement() {
    value--;
    saveState();
    std::cout << value << std::endl;
  }

  void undo() {
    if (current > 0) {
      current--;
      value = history[current].getState();
      std::cout << value << std::endl;
    }
  }

  void redo() {
    if (current < static_cast<int>(history.size()) - 1) {
      current++;
      value = history[current].getState();
      std::cout << value << std::endl;
    }
  }

private:
  void saveState() {
    if (current < static_cast<int>(history.size()) - 1) {
      history.erase(history.begin() + current + 1, history.end());
    }
    history.push_back(Memento(value));
    current++;
  }
};

int main() {
  Counter counter;
  std::string command;

  while (std::cin >> command) {
    if (command == "Increment") {
      counter.increment();
    } else if (command == "Decrement") {
      counter.decrement();
    } else if (command == "Undo") {
      counter.undo();
    } else if (command == "Redo") {
      counter.redo();
    }
  }

  return 0;
}