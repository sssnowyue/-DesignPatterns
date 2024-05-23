/**
Prototype Pattern:
- Prototype : [Stable] Declare a method `clone`(Deep Clone) to clone itself. Like the combination of `Factory` and `Production` in [Factory Method Pattern] and [Abstract Factory Pattern].
- Concrete Prototype : [Unstable] Implement the `clone` method to copy the current object and return a new object.
*/
/**
Problem Description:
The company is developing a graphic design software where a frequently used graphic element is a rectangle. Designers might need to frequently create similar rectangles that share the same basic properties (color, width, height). To improve the efficiency of designers, you are tasked with designing a prototype pattern for a rectangle object. This prototype will allow quick cloning of new rectangle objects.

Input Description:
First, input a string representing the basic properties of a rectangle, including color, width, and height, separated by spaces, e.g., "Red 10 5".
Then, input an integer N (1 ≤ N ≤ 100), representing the number of rectangles to be created using the prototype.

Output Description:
For each rectangle, output a string representing the rectangle's detailed information in the format: "Color: Red, Width: 10, Height: 5".

Input Example:
```
Red 10 5
3
```

Output Example:
```
Color: Red, Width: 10, Height: 5
Color: Red, Width: 10, Height: 5
Color: Red, Width: 10, Height: 5
```

Hint:
Implement the creation of rectangle objects using the clone method of the prototype pattern.
*/

#include <iostream>
#include <string>
#include <vector>

// Prototype
class Prototype {
public:
    virtual Prototype* clone() const = 0; // Clone method
    virtual std::string getDetails() const = 0;
    virtual ~Prototype() {}
};

// Concrete Prototype
class RectanglePrototype : public Prototype {
private:
    std::string color;
    int width;
    int height;

public:
    RectanglePrototype(std::string color, int width, int height)
        : color(color), width(width), height(height) {}

    Prototype* clone() const override { // Clone method
        return new RectanglePrototype(*this);
    }

    std::string getDetails() const override {
        return "Color: " + color + ", Width: " + std::to_string(width) + ", Height: " + std::to_string(height);
    }
};

// Client
int main() {
    std::string color;
    int width, height, N;
    std::cin >> color >> width >> height;

    RectanglePrototype* prototype = new RectanglePrototype(color, width, height); // Create the prototype

    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        Prototype* clonedRectangle = prototype->clone(); // Clone the prototype
        std::cout << clonedRectangle->getDetails() << std::endl;
        delete clonedRectangle;
    }

    // Clean up the prototype
    delete prototype;

    return 0;
}
