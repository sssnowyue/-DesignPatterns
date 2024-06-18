/**
State Pattern:
- `State`: [Stable] Declares the interface for the state-specific behavior.
- `ConcreteState`: [Unstable] Implement the state-specific behavior.
- `Context`:  [Stable] Maintains an instance of a `ConcreteState` subclass that defines the current state.
*/

/**
Title description
Jame has a light bulb at home, which is in the off state (OffState) at the beginning. The desk lamp can receive a series of commands, including turning on ("ON"), turning off ("OFF"), and flashing ("blink"). Each time a command is received, the desk lamp will perform the corresponding operation and output the current state of the bulb. Please design a program to simulate this light bulb system.

Input description
The first line is an integer n (1 <= n <= 1000), indicating the number of commands received.

The next n lines, each line contains a string s, representing a command ("ON", "OFF" or "blink").

Output description
For each command, output a line to indicate the state of the bulb after executing the command.
Input example
5
ON
OFF
BLINK
OFF
ON
Output example
Light is ON
Light is OFF
Light is Blinking
Light is OFF
Light is ON
*/
#include <iostream>
#include <memory>
#include <string>

// State
class State {
public:
    virtual ~State() = default;
    virtual std::string handle() const = 0;
};

// ConcreteState
class OnState : public State {
public:
    std::string handle() const override {
        return "Light is ON";
    }
};

class OffState : public State {
public:
    std::string handle() const override {
        return "Light is OFF";
    }
};

class BlinkState : public State {
public:
    std::string handle() const override {
        return "Light is Blinking";
    }
};

// Context
class Light {
private:
    std::unique_ptr<State> state;
public:
    Light() : state(std::make_unique<OffState>()) {} 
    void setState(std::unique_ptr<State> newState) {
        state = std::move(newState);
    }
    std::string performOperation() const {
        return state->handle();
    }
};

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    Light light;
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::getline(std::cin, command);
        if (command == "ON") {
            light.setState(std::make_unique<OnState>());
        } else if (command == "OFF") {
            light.setState(std::make_unique<OffState>());
        } else if (command == "BLINK") {
            light.setState(std::make_unique<BlinkState>());
        } else {
            std::cout << "Invalid command: " << command << std::endl;
        }
        std::cout << light.performOperation() << std::endl;
    }

    return 0;
}
