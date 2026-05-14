#include <iostream>
#include <string>

// Engine class
class Engine {
public:
    Engine() {
        // Constructor for Engine
    }
    void start() {
        // LOGICAL ERROR: This method should indicate the engine has started,
        // but it currently does nothing.
        // std::cout << "Engine started." << std::endl; // This line is intentionally omitted
    }
};

// Car class using composition
class Car {
private:
    Engine engine; // Composition: Car contains an Engine object
public:
    Car() {
        // Constructor for Car
    }
    void startCar() {
        std::cout << "Car starting..." << std::endl;
        engine.start(); // Calls the Engine's start method, which has a logical flaw
        std::cout << "Car is now running." << std::endl;
    }
};

// Driver code
int main() {
    Car myCar;
    myCar.startCar();
    return 0;
}