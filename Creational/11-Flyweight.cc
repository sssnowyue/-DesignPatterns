/**
Flyweight Pattern:
Flyweight : Shared by all concrete flyweight classes. It typically includes operations for handling external states.
ConcreteFlyweight : Inherits from the Flyweight class or implements the Flyweight interface and contains the internal state.
FlyweightFactory : Responsible for creating and managing flyweight objects. When a user requests a flyweight, the factory provides an existing instance or creates a new one.
Client : The Client maintains the external state and passes it to the flyweight object when it is used.
*/

/**
## Problem Description
In a graphics editor, users can draw different types of shapes, including
circles (CIRCLE), rectangles (RECTANGLE), triangles (TRIANGLE), etc. You are
tasked with implementing a shape drawing program that can share the same type of
shape objects to reduce memory usage.

### Input Description
The input consists of multiple lines, each representing a draw command. Each
command includes two parts:
1. Shape type (Circle, Rectangle, or Triangle)
2. Coordinates where the shape is drawn (two integers, x and y)

### Output Description
For each draw command, output the location information where the corresponding
shape is drawn. If the shape is being drawn for the first time, output "drawn
at". Otherwise, output "shared at".

### Input Example
```
CIRCLE 10 20
RECTANGLE 30 40
CIRCLE 15 25
TRIANGLE 5 15
CIRCLE 10 20
RECTANGLE 30 40
```

### Output Example
```
CIRCLE drawn at (10, 20)
RECTANGLE drawn at (30, 40)
CIRCLE shared at (15, 25)
TRIANGLE drawn at (5, 15)
CIRCLE shared at (10, 20)
RECTANGLE shared at (30, 40)
```
*/

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

enum ShapeType { CIRCLE, RECTANGLE, TRIANGLE };

std::string shapeTypeToString(ShapeType type) {
  switch (type) {
  case CIRCLE:
    return "CIRCLE";
  case RECTANGLE:
    return "RECTANGLE";
  case TRIANGLE:
    return "TRIANGLE";
  default:
    return "UNKNOWN";
  }
}

class Position {
private:
  int x;
  int y;

public:
  Position(int x, int y) : x(x), y(y) {}

  int getX() const { return x; }

  int getY() const { return y; }
};

class Shape {
public:
  virtual void draw(const Position &position) = 0;
  virtual ~Shape() {}
};

class ConcreteShape : public Shape {
private:
  ShapeType shapeType;
  bool isFirstTime;

public:
  ConcreteShape(ShapeType shapeType)
      : shapeType(shapeType), isFirstTime(true) {}

  void draw(const Position &position) override {
    std::cout << shapeTypeToString(shapeType)
              << (isFirstTime ? " drawn" : " shared") << " at ("
              << position.getX() << ", " << position.getY() << ")\n";
  }

  void setFirstTime(bool firstTime) { isFirstTime = firstTime; }
};

class ShapeFactory {
private:
  std::unordered_map<ShapeType, Shape *> shapes;

public:
  Shape *getShape(ShapeType type) {
    if (shapes.find(type) == shapes.end()) {
      shapes[type] = new ConcreteShape(type);
    }
    return shapes[type];
  }

  ~ShapeFactory() {
    for (const auto &entry : shapes) {
      delete entry.second;
    }
  }
};

void processCommand(ShapeFactory &factory, const std::string &command);

int main() {
  ShapeFactory factory;
  std::string command;

  while (std::getline(std::cin, command)) {
    processCommand(factory, command);
  }

  return 0;
}

void processCommand(ShapeFactory &factory, const std::string &command) {
  std::istringstream iss(command);
  std::string shapeTypeStr;
  int x, y;

  iss >> shapeTypeStr >> x >> y;

  ShapeType type;
  if (shapeTypeStr == "CIRCLE") {
    type = CIRCLE;
  } else if (shapeTypeStr == "RECTANGLE") {
    type = RECTANGLE;
  } else if (shapeTypeStr == "TRIANGLE") {
    type = TRIANGLE;
  } else {
    std::cerr << "Invalid shape type: " << shapeTypeStr << std::endl;
    return;
  }

  Shape *shape = factory.getShape(type);
  shape->draw(Position(x, y));
  dynamic_cast<ConcreteShape *>(shape)->setFirstTime(false);
}