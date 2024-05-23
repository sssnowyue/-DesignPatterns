/**
To create families of related or dependent objects without specifying their concrete classes
> Factory Method Pattern is  a special Abstract Factory Pattern that has no relative objects.
 */


/**
Problem Description:
Jack's family has recently opened two factories to produce furniture. One factory produces modern-style sofas and chairs, while the other produces classical-style sofas and chairs. The factories have received an order, and you need to help design a system that describes the information about the furniture that needs to be produced according to the order.

Input Description:
The first line of input is an integer \( N \) (1 ≤ \( N \) ≤ 100), indicating the number of orders.
The next \( N \) lines each contain a string, which represents the type of furniture. The furniture types are "modern" and "classical".

Output Description:
For each order, output the string that describes the furniture that needs to be produced.
For a "modern" order, output the following two lines:
```
modern chair
modern sofa
```
For a "classical" order, output the following two lines:
```
classical chair
classical sofa
```

Input Example:
```
3
modern
classical
modern
```

Output Example:
```
modern chair
modern sofa
classical chair
classical sofa
modern chair
modern sofa
```

Hint:
In the example, the factory received 3 orders, 2 of which are for modern style and 1 for classical style. According to the input type, the furniture production information is output to the console for each order.
*/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Abstract product interfaces
class Chair {
public:
    virtual ~Chair() = default;
    virtual std::string description() const = 0;
};

class Sofa {
public:
    virtual ~Sofa() = default;
    virtual std::string description() const = 0;
};

// Concrete products for modern style
class ModernChair : public Chair {
public:
    std::string description() const override {
        return "modern chair";
    }
};

class ModernSofa : public Sofa {
public:
    std::string description() const override {
        return "modern sofa";
    }
};

// Concrete products for classical style
class ClassicalChair : public Chair {
public:
    std::string description() const override {
        return "classical chair";
    }
};

class ClassicalSofa : public Sofa {
public:
    std::string description() const override {
        return "classical sofa";
    }
};

// Abstract factory interface
class FurnitureFactory {
public:
    virtual ~FurnitureFactory() = default;
    virtual std::unique_ptr<Chair> createChair() const = 0;
    virtual std::unique_ptr<Sofa> createSofa() const = 0;
};

// Concrete factory for modern furniture
class ModernFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<ModernChair>();
    }

    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<ModernSofa>();
    }
};

// Concrete factory for classical furniture
class ClassicalFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<ClassicalChair>();
    }

    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<ClassicalSofa>();
    }
};

// Client code
void produceFurniture(const FurnitureFactory& factory) {
    auto chair = factory.createChair();
    auto sofa = factory.createSofa();
    std::cout << chair->description() << std::endl;
    std::cout << sofa->description() << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> orders(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> orders[i];
    }

    for (const auto& order : orders) {
        if (order == "modern") {
            ModernFurnitureFactory modernFactory;
            produceFurniture(modernFactory);
        } else if (order == "classical") {
            ClassicalFurnitureFactory classicalFactory;
            produceFurniture(classicalFactory);
        }
    }

    return 0;
}
