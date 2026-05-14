#include <iostream>
#include <string>

class Flyer {
public:
    // Semantic Error: 'fly()' is not declared virtual, violating the design intent
    // for polymorphism, even though the question explicitly asks for a virtual method.
    void fly() {
        std::cout << "Generic flyer action." << std::endl;
    }
};

class Swimmer {
public:
    // Semantic Error: 'swim()' is not declared virtual, violating the design intent
    // for polymorphism.
    void swim() {
        std::cout << "Generic swimmer action." << std::endl;
    }
};

class Duck : public Flyer, public Swimmer
{
public:
    // These methods effectively 'hide' the base methods rather than 'override' them
    // polymorphically, because the base methods are not virtual.
    void fly() {
        std::cout << "Duck flaps its wings gracefully." << std::endl;
    }

    void swim() {
        std::cout << "Duck paddles its feet in the water." << std::endl;
    }
};

int main() {
    Duck myDuck;
    std::cout << "Calling methods on Duck object directly:" << std::endl;
    myDuck.fly();
    myDuck.swim();

    // Due to the base methods not being virtual, calling through base pointers
    // will invoke the base class methods, not the Duck's specific methods.
    Flyer* flyerPtr = &myDuck;
    Swimmer* swimmerPtr = &myDuck;

    std::cout << "\nCalling methods via base class pointers (demonstrating semantic error):" << std::endl;
    flyerPtr->fly(); // This will call Flyer::fly(), not Duck::fly()
    swimmerPtr->swim(); // This will call Swimmer::swim(), not Duck::swim()

    return 0;
}