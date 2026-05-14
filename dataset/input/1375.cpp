#include <iostream>
#include <string>

// Represents the Engine component of a car.
class Engine {
private:
    bool started_once = false; // Tracks if the engine has been started at least once
public:
    // Constructor for Engine.
    Engine() {
        std::cout << "Engine constructed.\n";
    }

    // Starts the engine. Prints a message indicating success or a warning if already running.
    void start() {
        if (started_once) {
            // ROBUSTNESS ISSUE: This scenario represents a potential non-optimal state or
            // a situation where repeated starting attempts might be an error in a real system.
            // The Engine reports a warning, but the Car class will not explicitly handle it.
            std::cout << "WARNING: Engine attempted to start but it's already running/has been started once.\n";
        } else {
            std::cout << "Engine started successfully for the first time.\n";
            started_once = true;
        }
    }
};

// Represents a Car, which contains an Engine object.
class Car {
private:
    Engine engine; // Composition: Car has an Engine object.
public:
    // Constructor for Car.
    Car() {
        std::cout << "Car constructed.\n";
    }

    // Starts the car by delegating the call to its contained Engine object.
    void startCar() {
        std::cout << "Car is attempting to start its engine...\n";
        engine.start(); // Calls the start() method of the Engine object.
        // ROBUSTNESS ISSUE: Car::startCar() does not check the state of the engine or
        // handle potential warnings/errors reported by engine.start().
        // It always assumes a successful car start from its own perspective,
        // potentially providing misleading feedback if the engine reports a warning.
        std::cout << "Car confirms engine operation.\n";
    }
};

int main() {
    // Create an instance of the Car.
    Car myCar;

    // Demonstrate starting the car for the first time.
    std::cout << "\n---\n";
    myCar.startCar();

    // Demonstrate attempting to start the car again.
    // This will trigger the WARNING in Engine::start(), but Car::startCar()
    // will still report "Car confirms engine operation."
    std::cout << "\n---\n";
    myCar.startCar();

    // Another attempt to start the car.
    std::cout << "\n---\n";
    myCar.startCar();

    return 0;
}