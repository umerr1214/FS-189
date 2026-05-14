#include <iostream>
// No need for <string> if status is managed by bool, which is more efficient for simple state.

// Represents the Engine component of a car.
class Engine {
private:
    bool is_running = false; // Internal state of the engine.
public:
    // Constructor for Engine.
    Engine() {
        std::cout << "Engine constructed.\n";
    }

    // Starts the engine. Prints a message indicating success or if already running.
    void start() {
        if (!is_running) {
            std::cout << "Engine started.\n";
            is_running = true;
        } else {
            std::cout << "Engine is already running.\n";
        }
    }

    // Optional: A method to stop the engine, not required by the problem but good for completeness.
    void stop() {
        if (is_running) {
            std::cout << "Engine stopped.\n";
            is_running = false;
        } else {
            std::cout << "Engine is already off.\n";
        }
    }
};

// Represents a Car, which contains an Engine.
class Car {
private:
    Engine engine; // Composition: Car has an Engine object as a member.
public:
    // Constructor for Car.
    Car() {
        std::cout << "Car constructed.\n";
    }

    // Starts the car by delegating the call to its contained Engine object.
    void startCar() {
        std::cout << "Car attempting to start its engine...\n";
        engine.start(); // Calls the start() method of the Engine object.
        std::cout << "Car's engine operation confirmed.\n";
    }

    // Optional: A method to stop the car, delegating to the engine.
    void stopCar() {
        std::cout << "Car attempting to stop its engine...\n";
        engine.stop();
        std::cout << "Car's engine shutdown confirmed.\n";
    }
};

int main() {
    // Create an instance of the Car.
    Car myCar;

    // Demonstrate starting the car for the first time.
    std::cout << "\n--- First Start Attempt ---\n";
    myCar.startCar();

    // Demonstrate attempting to start the car again (should report already running).
    std::cout << "\n--- Second Start Attempt ---\n";
    myCar.startCar();

    // Demonstrate stopping the car.
    std::cout << "\n--- Stop Attempt ---\n";
    myCar.stopCar();

    // Demonstrate starting the car after stopping.
    std::cout << "\n--- Third Start Attempt (after stop) ---\n";
    myCar.startCar();

    return 0;
}