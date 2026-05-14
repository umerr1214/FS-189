#include <iostream>
#include <string>

// Engine class with a simple constructor and start() method.
// This version has a robustness issue: the start() method
// does not check if the engine is already running, leading to
// redundant operations and output if called multiple times.
class Engine {
private:
    std::string name_;
    bool is_running_; // State to track if engine is running

public:
    Engine(std::string name = "Default Engine") : name_(name), is_running_(false) {
        std::cout << "Engine " << name_ << " constructed." << std::endl;
    }

    void start() {
        // Robustness Issue: Does not check 'is_running_' before performing action.
        // It will always print "started" and set 'is_running_' to true,
        // even if it's already true.
        std::cout << "Engine " << name_ << " started." << std::endl;
        is_running_ = true;
    }

    bool isRunning() const {
        return is_running_;
    }
};

// Car class using composition: it contains an Engine object as a member.
class Car {
private:
    Engine engine_; // Composition: Car contains an Engine object

public:
    // Car constructor initializes the Engine member.
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
    // Create a Car object
    Car myCar("V8 Engine");

    // Start the car's engine
    myCar.start();

    // Demonstrate the robustness issue: calling start again without
    // checking if the engine is already running.
    // The engine's start() method will redundantly print "started"
    // and set its state, even though it's already running.
    myCar.start();

    return 0;
}