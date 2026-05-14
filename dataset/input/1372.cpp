#include <iostream>
#include <string>

// Engine class
class Engine {
public:
    Engine() {
        // Constructor for Engine
    }
    void start() {
        std::cout << "Engine started." << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here after class definition

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
        engine.start(); // Delegate to the Engine's start method
        std::cout << "Car is now running." << std::endl;
    }
};

// Driver code
int main() {
    Car myCar;
    myCar.startCar();
    return 0;
}