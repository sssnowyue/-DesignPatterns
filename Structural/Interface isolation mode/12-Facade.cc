/**
Facade Pattern:
- Facade Class : Provides a unified high-level interface to make a complex subsystem easier to use.
- Subsystem Classes : Implement the functionality of the subsystem and handle the tasks assigned by the facade class.
*/
/**
### Problem Description
The main power switch in Xiaoming's house controls three devices: an air conditioner, a desk lamp, and a television. Each device has its own switch code represented by the numbers 1, 2, and 3 respectively. That is, inputting 1 turns off the air conditioner, inputting 2 turns off the desk lamp, and inputting 3 turns off the television. When the input is 4, it means all devices should be turned off. Please write a program using the facade pattern to describe the operation of the main power switch.

### Input Description
The first line is an integer N (1 <= N <= 100), representing the number of subsequent lines of input.

The next N lines, each containing a single digit, represent the switch operation for the corresponding device (1 to turn off the air conditioner, 2 to turn off the desk lamp, 3 to turn off the television, and 4 to turn off all devices).

### Output Description
Output the status of all devices after turning them off. When the input number is outside the range of 1-4, output "Invalid device code."

### Input Example
```
4
1
2
3
4
```

### Output Example
```
Air Conditioner is turned off.
Desk Lamp is turned off.
Television is turned off.
All devices are off.
```
*/

#include <iostream>
#include <vector>

class AirConditioner {
public:
    void turnOff() {
        std::cout << "Air Conditioner is turned off." << std::endl;
    }
};

class DeskLamp {
public:
    void turnOff() {
        std::cout << "Desk Lamp is turned off." << std::endl;
    }
};

class Television {
public:
    void turnOff() {
        std::cout << "Television is turned off." << std::endl;
    }
};

class PowerSwitchFacade {
private:
    DeskLamp deskLamp;
    AirConditioner airConditioner;
    Television television;

public:
    PowerSwitchFacade() {
    }

    void turnOffDevice(int deviceCode) {
        switch (deviceCode) {
            case 1:
                airConditioner.turnOff();
                break;
            case 2:
                deskLamp.turnOff();
                break;
            case 3:
                television.turnOff();
                break;
            case 4:
                std::cout << "All devices are off." << std::endl;
                break;
            default:
                std::cout << "Invalid device code." << std::endl;
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n; i++) {
        std::cin >> input[i];
    }

    PowerSwitchFacade powerSwitch;
    for (int i = 0; i < n; i++) {
        powerSwitch.turnOffDevice(input[i]);
    }

    return 0;
}