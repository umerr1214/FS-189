#include <iostream>
#include <string>

// Engine class with a simple constructor and start() method.
class Engine {
private:
    std::string name_;

public:
    Engine(std::string name = "Default Engine") : name_(name) {
        std::cout << "Engine " << name_ << " constructed." << std::endl;
    }

    void start() {
        std::cout << "Engine " << name_ << " started." << std::endl;
    }
};

// Car class using composition with a Readability/Efficiency Issue:
// It uses a raw pointer for the Engine member, requiring manual memory management
// with 'new' and 'delete'. This is less idiomatic and more error-prone than
// direct composition or using smart pointers in modern C++.
class Car {
private:
    Engine* engine_; // Readability/Efficiency Issue: Uses raw pointer for composition

public:
    // Car constructor dynamically allocates the Engine.
    Car(std::string engine_name = "Default Engine") {
        std::cout << "Car constructed." << std::endl;
        engine_ = new Engine(engine_name); // Manual allocation
    }

    // Car destructor to deallocate the dynamically created Engine.
    // This is necessary to prevent memory leaks, but adds boilerplate and risk.
    ~Car() {
        std::cout << "Car destructed." << std::endl;
        delete engine_; // Manual deallocation
        engine_ = nullptr;
    }

    // Method to start the car, which in turn starts its engine.
    void start() {
        std::cout << "Car starting its engine." << std::endl;
        if (engine_) { // Check for null, though it shouldn't be null here
            engine_->start(); // Delegate the start operation to the composed Engine object
        } else {
            std::cout << "Error: Engine not initialized." << std::endl;
        }
    }
};

int main() {
    // Create a Car object
    Car myCar("Electric Motor");

    // Start the car's engine
    myCar.start();

    // The Car object will be destructed automatically when it goes out of scope,
    // triggering the Car's destructor which then deallocates the Engine.

    return 0;
}