#include <iostream>
#include <string>

// Abstract base class
class Appliance {
public:
    virtual void operate() = 0; // Pure virtual function
    virtual ~Appliance() {}
} // SYNTAX ERROR: Missing semicolon here

// Concrete derived class 1
class Refrigerator : public Appliance {
public:
    void operate() override {
        std::cout << "Refrigerator is cooling food." << std::endl;
    }
};

// Concrete derived class 2
class WashingMachine : public Appliance {
public:
    void operate() override {
        std::cout << "Washing machine is washing clothes." << std::endl;
    }
};

int main() {
    // This code contains a syntax error and will not compile.
    // If it were fixed, it would demonstrate object creation and method calls.
    Refrigerator myFridge;
    WashingMachine myWasher;

    std::cout << "--- Direct calls ---" << std::endl;
    myFridge.operate();
    myWasher.operate();

    std::cout << "--- Polymorphic calls ---" << std::endl;
    Appliance* appliance1 = &myFridge;
    Appliance* appliance2 = &myWasher;

    appliance1->operate();
    appliance2->operate();

    return 0;
}