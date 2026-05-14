#include <iostream>
#include <string>

// Abstract base class
class Appliance {
public:
    virtual void operate() = 0; // Pure virtual function
    virtual ~Appliance() {}
};

// Concrete derived class 1
class Refrigerator : public Appliance {
public:
    void operate() override {
        std::cout << "Refrigerator is cooling food." << std::endl;
    }
};

// Concrete derived class 2
// SEMANTIC ERROR: WashingMachine fails to implement the pure virtual function operate(),
// making it an abstract class itself.
class WashingMachine : public Appliance {
public:
    // Missing: void operate() override { ... }
};

int main() {
    Refrigerator myFridge;
    // SEMANTIC ERROR: Cannot instantiate abstract class 'WashingMachine'
    // because it does not override the pure virtual function 'operate()'.
    WashingMachine myWasher; // This line will cause a compile-time error.

    std::cout << "--- Direct calls ---" << std::endl;
    myFridge.operate();
    // myWasher.operate(); // Would also be an error if myWasher could be created.

    std::cout << "--- Polymorphic calls ---" << std::endl;
    Appliance* appliance1 = &myFridge;
    // Appliance* appliance2 = &myWasher; // Would be fine if myWasher was concrete.

    appliance1->operate();
    // appliance2->operate();

    return 0;
}