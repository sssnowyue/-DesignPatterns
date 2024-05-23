/**
Singleton Pattern:
    1. A class has only one instance;
    2. Provides a global point of access to it.
*/
#include <iostream>

// Singleton Class
class Singleton {
private:
    // Private constructor to prevent instancing
    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }

    // Declare copy constructor and assignment operator as deleted to prevent copies
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // The unique instance of the Singleton
    static Singleton* instance;

public:
    // Static method to get the unique instance of the Singleton
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Example method to demonstrate functionality
    void showMessage() {
        std::cout << "Hello from Singleton instance!" << std::endl;
    }
};

// Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton* Singleton::instance = nullptr;

// Main function to demonstrate Singleton usage
int main() {
    // Get the unique instance of Singleton
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();

    // Try to get another instance and show message
    Singleton* s2 = Singleton::getInstance();
    s2->showMessage();

    // Check if both instances are the same
    if (s1 == s2) {
        std::cout << "Both instances are the same." << std::endl;
    } else {
        std::cout << "Instances are different." << std::endl;
    }

    return 0;
}