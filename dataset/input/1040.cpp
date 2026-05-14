#include <iostream>
#include <string>

class Flyer {
public:
    virtual void fly() {
        std::cout << "Generic flyer action." << std::endl;
    }
};

class Swimmer {
public:
    virtual void swim() {
        std::cout << "Generic swimmer action." << std::endl;
    }
};

class Duck : public Flyer, public Swimmer
{
public:
    // Logical Error: Duck overrides the methods but calls the base class implementations,
    // instead of printing specific duck actions as required.
    void fly() override {
        Flyer::fly(); // Calls the generic Flyer method
    }

    void swim() override {
        Swimmer::swim(); // Calls the generic Swimmer method
    }
};

int main() {
    Duck myDuck;
    std::cout << "Calling methods on Duck object directly:" << std::endl;
    myDuck.fly();
    myDuck.swim();

    Flyer* flyerPtr = &myDuck;
    Swimmer* swimmerPtr = &myDuck;

    std::cout << "\nCalling methods via base class pointers:" << std::endl;
    flyerPtr->fly();
    swimmerPtr->swim();

    return 0;
}