/**
Used for one-to-many dependencies: when the status of a subject changes, all Observers will be notified and automatically updated.
- Subject [Stable]: 1. Register, 2. Delete, 3. Notify Observer
- Observer [Stable]: Do corresponding operations after receiving notifications from Subject
- Concrete Subject [Unstable]: Specific implementations of Subject
- Concrete Observer [Unstable]: Specific implementations of Observer
*/
/**
The school has a clock (subject), which will notify all students (observers) of
the current time every hour on the hour.
Please use the observer pattern to implement this clock notification system.
Note: The time starts at 0 and is updated every hour.
*/
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// Observer
class Observer {
public:
  virtual void update(int time) = 0;
};

// Subject
class Subject {
public:
  virtual void registerObserver(shared_ptr<Observer> observer) = 0;
  virtual void removeObserver(shared_ptr<Observer> observer) = 0;
  virtual void notifyObservers() = 0;
};

// Concrete Subject (Clock)
class Clock : public Subject {
private:
  int time;
  vector<shared_ptr<Observer>> observers; // multiple observers

public:
  Clock() : time(0) {}

  void registerObserver(shared_ptr<Observer> observer) override {
    observers.push_back(observer);
  }

  void removeObserver(shared_ptr<Observer> observer) override {
    observers.erase(remove(observers.begin(), observers.end(), observer),observers.end());
  }

  void notifyObservers() override {
    for (auto &observer : observers) {
      observer->update(time);
    }
  }

  void tick() {
    ++time;
    notifyObservers(); // Notify observers
  }
};

// Concrete Observer (Student)
class Student : public Observer {
private:
  string name;

public:
  Student(const string &name) : name(name) {}

  void update(int time) override {
    cout << name << " " << time << endl;
  }
};

int main() {
  int N;
  cin >> N;

  vector<shared_ptr<Observer>> students;
  for (int i = 0; i < N; ++i) {
    string name;
    cin >> name;
    students.push_back(make_shared<Student>(name));
  }

  int updates;
  cin >> updates;

  Clock clock;
  for (const auto &student : students) {
    clock.registerObserver(student);
  }

  for (int i = 0; i < updates; ++i) {
    clock.tick();
  }

  return 0;
}
