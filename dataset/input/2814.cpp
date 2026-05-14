#include <iostream>
#include <string>

class Engine {
public:
    int power;
    std::string type;

    Engine(int p, std::string t) : power(p), type(t) {}

    void startEngine() {
        std::cout << "Engine (" << type << ", " << power << " HP) starting..." << std::endl;
    }
};

class Car {
public:
    std::string make;
    std::string model;
    Engine* enginePtr; // SEMANTIC ERROR: Using a raw pointer for composition without proper ownership/lifecycle

    Car(std::string mk, std::string md, int enginePower, std::string engineType)
        : make(mk), model(md) {
        // SEMANTIC ERROR: Creating a local Engine object and assigning its address
        // The local 'tempEngine' will be destroyed when the constructor exits,
        // leaving 'enginePtr' as a dangling pointer. Dereferencing it later is undefined behavior.
        Engine tempEngine(enginePower, engineType);
        enginePtr = &tempEngine;
        std::cout << "Car constructor finished. tempEngine is now out of scope." << std::endl;
    }

    void start() {
        std::cout << "Car " << make << " " << model << " attempting to start." << std::endl;
        if (enginePtr) {
            // This dereferences a dangling pointer, leading to undefined behavior (e.g., crash, garbage output)
            enginePtr->startEngine();
        } else {
            std::cout << "Error: Engine not properly initialized." << std::endl;
        }
        std::cout << "Car started!" << std::endl;
    }

    // A destructor would typically be needed for raw pointers, but in this specific
    // case, deleting enginePtr would be a double error (deleting stack memory).
    // The core semantic error is the dangling pointer itself.
    ~Car() {
        // No delete enginePtr; to avoid runtime crash on stack memory,
        // but this highlights the incorrect ownership model.
    }
};

int main() {
    // Driver code for testing
    Car myCar("Toyota", "Camry", 180, "Gasoline");
    myCar.start(); // Will likely exhibit undefined behavior

    std::cout << std::endl;

    Car electricCar("Tesla", "Model 3", 450, "Electric");
    electricCar.start(); // Will likely exhibit undefined behavior

    return 0;
}