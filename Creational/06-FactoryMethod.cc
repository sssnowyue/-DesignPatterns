/**
Factory Method Pattern:
  To deal with the problem of creating objects without having to specify their exact class
  - Creator [Stable]: An abstract factory interface used to create Product objects
  - ConcreteCreator [Unstable] : Implements the abstract factory interface to creates specific products objects
  - Product [Stable] : An abstract product interface of the product
  - ConcreteProduct [Unstable] : Implements the abstract product interface
*/

/**
Problem Description:
Jack has two factories, one for producing circular blocks and one for producing square blocks. Please help him design a block factory system to record the production information of the blocks.

Input Description:
The first line of the input is an integer N (1 ≤ N ≤ 100), which represents the number of production times.
The next N lines each contain a string and an integer. The string represents the type of block. The block types are "Circle" and "Square". The integer represents the number of blocks of this type to be produced.

Output Description:
For each block, output a string representing the information of the block.

Input Example:
3
Circle 1
Square 2
Circle 1

Output Example:
Circle Block
Square Block
Square Block
Circle Block

Tips:
In the example, the block factory produced 3 blocks, of which 2 are circular and 1 is square. According to the input type, the information of each block is output to the console.
*/
#include <iostream>
#include <vector>
#include <memory>

// Product
class Block {
public:
    virtual void produce() = 0;
    virtual ~Block() = default;
};

// ConcreteProduct 1
class CircleBlock : public Block {
public:
    void produce() override {
        std::cout << "Circle Block" << std::endl;
    }
};

// ConcreteProduct 2
class SquareBlock : public Block {
public:
    void produce() override {
        std::cout << "Square Block" << std::endl;
    }
};

// Creator
class BlockFactory {
public:
    virtual std::unique_ptr<Block> createBlock() = 0;
    virtual ~BlockFactory() = default;
};

// ConcreteCreator 1
class CircleBlockFactory : public BlockFactory {
public:
    std::unique_ptr<Block> createBlock() override {
        return std::make_unique<CircleBlock>();
    }
};

// ConcreteCreactor 2
class SquareBlockFactory : public BlockFactory {
public:
    std::unique_ptr<Block> createBlock() override {
        return std::make_unique<SquareBlock>();
    }
};

// BlockFactorySystem class
class BlockFactorySystem {
private:
    std::vector<std::unique_ptr<Block>> blocks;

public:
    void produceBlocks(BlockFactory& factory, int quantity) {
        for (int i = 0; i < quantity; i++) {
            auto block = factory.createBlock();
            block->produce();
            blocks.push_back(std::move(block));
        }
    }

    const std::vector<std::unique_ptr<Block>>& getBlocks() const {
        return blocks;
    }
};

int main() {
    BlockFactorySystem factorySystem;

    // Read the number of production times
    int productionCount;
    std::cin >> productionCount;

    // Read each production type and quantity
    for (int i = 0; i < productionCount; i++) {
        std::string blockType;
        int quantity;
        std::cin >> blockType >> quantity;

        if (blockType == "Circle") {
            static CircleBlockFactory circleFactory;
            factorySystem.produceBlocks(circleFactory, quantity);
        } else if (blockType == "Square") {
            static SquareBlockFactory squareFactory;
            factorySystem.produceBlocks(squareFactory, quantity);
        }
    }

    return 0;
}
