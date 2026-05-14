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
{ // Missing semicolon here, causing a syntax error
public:
    void fly() override {
        std::cout << "Duck flaps its wings gracefully." << std::endl;
    }

    void swim() override {
        std::cout << "Duck paddles its feet in the water." << std::endl;
    }
}

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