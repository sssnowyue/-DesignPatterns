/**
Builder Pattern:
- Product: A complex object being constructed, containing multiple components
- Abstract Builder: Defines an abstract interface for building various parts of the product and a method getResult that returns complex products
- Concrete Builder: Implements the abstract builder interface, builds the various components of the product, and provides a method to return the final product
- Director: Call Abstract Builder's method to build the product according to a certain order or logic
*/
/**
Question description:
Jack's family has opened a new bicycle factory to assemble and customize different bicycles, including mountain bikes and road bikes, using bicycle accessories (frames and wheels).
Mountain bikes use Aluminum Frame (aluminum frame) and Knobby Tires (grip tires), and road bikes use Carbon Frame (carbon frame) and Slim Tries.
Now it has received an order to customize a batch of bicycles. Please use [Builder Mode] to tell Xiao Ming which bicycle configurations need to be used for this order.

Input Description:
The first line of input is an integer N (1 ≤ N ≤ 100), representing the quantity of the order. 
The next N lines, each input a string, the string represents the customer's bicycle needs.
The string can contain the keywords "mountain" or "road" to indicate that the customer wants a mountain bike or a road bike.

Output Description:
For each order, output the customized bike configuration for that order.

Input Example:
3
mountain
road
mountain

Output Example:
Aluminum Frame Knobby Tires
Carbon Frame Slim Tires
Aluminum Frame Knobby Tires

Hint:
In this example, the product is a bicycle and there can be two builders: a mountain bike builder and a road bike builder.
*/

#include <iostream>
#include <vector>
#include <string>

// Product class
class Bicycle {
public:
    std::string frame;
    std::string tires;

    void showBicycle() const {
        std::cout << frame << " " << tires << std::endl;
    }
};

// Abstract Builder class
class BicycleBuilder {
public:
    virtual void buildFrame() = 0;
    virtual void buildTires() = 0;
    virtual Bicycle* getResult() = 0;
};

// Concrete Builder for Mountain Bike
class MountainBikeBuilder : public BicycleBuilder {
private:
    Bicycle* bike;

public:
    MountainBikeBuilder() {
        bike = new Bicycle();
    }

    void buildFrame() override {
        bike->frame = "Aluminum Frame";
    }

    void buildTires() override {
        bike->tires = "Knobby Tires";
    }

    Bicycle* getResult() override {
        return bike;
    }
};

// Concrete Builder for Road Bike
class RoadBikeBuilder : public BicycleBuilder {
private:
    Bicycle* bike;

public:
    RoadBikeBuilder() {
        bike = new Bicycle();
    }

    void buildFrame() override {
        bike->frame = "Carbon Frame";
    }

    void buildTires() override {
        bike->tires = "Slim Tires";
    }

    Bicycle* getResult() override {
        return bike;
    }
};

// Director class
class Director {
public:
    void construct(BicycleBuilder* builder) {
        builder->buildFrame();
        builder->buildTires();
    }
};

// Main function
int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> orders(N);

    for(int i = 0; i < N; ++i) {
        std::cin >> orders[i];
    }

    Director director;

    for(const auto& order : orders) {
        BicycleBuilder* builder = nullptr;
        if(order == "mountain") {
            builder = new MountainBikeBuilder();
        } else if(order == "road") {
            builder = new RoadBikeBuilder();
        }

        if(builder) {
            director.construct(builder);
            Bicycle* bike = builder->getResult();
            bike->showBicycle();
            delete bike;
            delete builder;
        }
    }

    return 0;
}
