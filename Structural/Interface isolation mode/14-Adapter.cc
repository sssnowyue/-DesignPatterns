/**
Adapter Pattern:
- Target: the interface that the client wants to use
- Adapter: implements the target interface used by the client and holds an
instance of the class that needs to be adapted.
- Adaptee: the class that needs to be adapted
*/
/**
Problem description
Jack bought a new computer that uses a Type C interface. He already has a USB
charger and data cable. In order to ensure that the new computer can use the
existing USB charger and data cable, he bought a Type C to USB docking station.
Please use the adapter mode to design and implement this docking station system
to ensure that Jack's new computer can use the existing USB charging cable and
data cable through the docking station, and can also use the Type C interface to
charge.

Input description
The title contains multiple lines of input. The first line enters a number N (1
< N <= 20), indicating that there are N groups of test data behind. The next N
lines are all integers, 1 means using the computer's own Type C interface, and 2
means using the docking station's USB interface to charge.

Output description
Output the corresponding charging information based on each line of input.

Input example
3
1
2
1

Output example
TypeC
USB Adapter
TypeC
*/

#include <iostream>

// Target
class IPrinter {
public:
  virtual ~IPrinter() {}
  virtual void print() = 0;
};

// Adaptee
class OldPrinter {
public:
  void printOldWay() { std::cout << "Printing the old way." << std::endl; }
};

// Adapter
class PrinterAdapter : public IPrinter {
private:
  OldPrinter *oldPrinter;

public:
  PrinterAdapter(OldPrinter *printer) : oldPrinter(printer) {}
  void print() override { oldPrinter->printOldWay(); }
};

int main() {
  OldPrinter *oldPrinter = new OldPrinter();
  
  IPrinter *printer = new PrinterAdapter(oldPrinter);
  printer->print(); 

  delete printer;
  delete oldPrinter;

  return 0;
}
