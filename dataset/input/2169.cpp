#include <iostream>
#include <string>

// Engine class with a simple constructor and start() method.
class Engine {
private:
    std::string name_;

public:
    // Simple constructor
    Engine(std::string name = "Default Engine") : name_(name) {
        std::cout << "Engine " << name_ << " constructed." << std::endl;
    }

    // Simple start method
    void start() {
        std::cout << "Engine " << name_ << " started." << std::endl;
    }
};

// Car class using composition: it contains an Engine object as a member.
class Car {
private:
    Engine engine_; // Composition: Car contains an Engine object as a direct member

public:
    // Car constructor uses an initializer list to properly construct the Engine member.
    Car(std::string engine_name = "Default Engine") : engine_(engine_name) {
        std::cout << "Car constructed with Engine " << engine_name << "." << std::endl;
    }

    // Method to start the car, which in turn starts its engine.
    void start() {
        std::cout << "Car starting its engine." << std::endl;
        engine_.start(); // Delegate the start operation to the composed Engine object
    }
};

int main() {
    // Create a Car object, which automatically constructs its Engine member.
    Car myCar("Turbo Engine");

    // Call the start method through the Car object.
    // This will in turn call the Engine's start method.
    myCar.start();

    return 0;
}