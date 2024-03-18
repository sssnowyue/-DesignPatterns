/**
Bridge Pattern:
Focus on separating the abstract part from the implementation part.
- Abstraction:
    - defines the abstract interface
    - maintains the Implementor reference.
- Refined Abstraction:
    - extends the interface defined by Abstraction
- Implementor:
    - defines the interface for implementation classes
- Concrete Implementor:
    - implements the Implementor interface
*/
/**
Jack has a universal remote control at home, which can support multiple
brands of televisions. Each television can perform operations such as power on,
power off, and channel switching. Please use the Bridge pattern to simulate this
operation.

Input Description
The first line is an integer N (1 <= N <= 100), indicating that there are N
lines of input following. The next N lines each contain two numbers. The first
number indicates thecreation of a remote control and television for a certain
brand, and the second number indicates the operation to be performed. Where 0
indicates the creation of a Sony brand television, 1 indicates the creation of a
TCL brand remote control and television; 2 indicates turning on the television,
3 indicates turning off the television, 4 indicates switching the channel.

Output Description
For each operation, output the corresponding execution result.

Input Example
6
0 2
1 2
0 4
0 3
1 4
1 3

Output Example
Sony TV is ON
TCL TV is ON
Switching Sony TV channel
Sony TV is OFF
Switching TCL TV channel
TCL TV is OFF
*/
#include <iostream>
#include <memory>
#include <sstream>

using namespace std;

// Implementor
class TV {
public:
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
  virtual void switchChannel() = 0;
  virtual ~TV() = default;
};

// Concrete Implementor
class SonyTV : public TV {
public:
  void turnOn() override { cout << "Sony TV is ON" << endl; }

  void turnOff() override { cout << "Sony TV is OFF" << endl; }

  void switchChannel() override { cout << "Switching Sony TV channel" << endl; }
};
class TCLTV : public TV {
public:
  void turnOn() override { cout << "TCL TV is ON" << endl; }

  void turnOff() override { cout << "TCL TV is OFF" << endl; }

  void switchChannel() override { cout << "Switching TCL TV channel" << endl; }
};

// Abstraction
class RemoteControl {
public:
  RemoteControl(shared_ptr<TV> tv) : tv(move(tv)) {}
  virtual void performOperation() = 0;
  virtual ~RemoteControl() = default;

protected:
  shared_ptr<TV> tv; // Reference to Implementor
};

// Refined Abstaction
class PowerOperation : public RemoteControl {
public:
  using RemoteControl::RemoteControl;

  void performOperation() override { tv->turnOn(); }
};
class OffOperation : public RemoteControl {
public:
  using RemoteControl::RemoteControl;

  void performOperation() override { tv->turnOff(); }
};
class ChannelSwitchOperation : public RemoteControl {
public:
  using RemoteControl::RemoteControl;

  void performOperation() override { tv->switchChannel(); }
};

int main() {
  int N;
  cin >> N;
  cin.ignore();

  for (int i = 0; i < N; i++) {
    int brand, operation;
    cin >> brand >> operation;

    shared_ptr<TV> tv;
    if (brand == 0) {
      tv = make_shared<SonyTV>();
    } else {
      tv = make_shared<TCLTV>();
    }

    shared_ptr<RemoteControl> remoteControl;
    if (operation == 2) {
      remoteControl = make_shared<PowerOperation>(tv);
    } else if (operation == 3) {
      remoteControl = make_shared<OffOperation>(tv);
    } else {
      remoteControl = make_shared<ChannelSwitchOperation>(tv);
    }

    remoteControl->performOperation();
  }

  return 0;
}
