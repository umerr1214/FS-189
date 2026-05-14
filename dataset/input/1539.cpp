#include <iostream>
#include <string>
#include <stdexcept> // For robust error handling

class Engine {
private:
    int horsepower;
    std::string fuelType;
    bool isRunning;

public:
    // Constructor with validation and initializer list
    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft), isRunning(false) {
        if (hp <= 0) {
            throw std::invalid_argument("Horsepower must be positive.");
        }
        std::cout << "Engine created: " << horsepower << "hp, " << fuelType << '\n';
    }

    // Idempotent start method for robustness
    void startEngine() {
        if (!isRunning) {
            std::cout << "Engine started: " << horsepower << "hp " << fuelType << '\n';
            isRunning = true;
        } else {
            std::cout << "Engine is already running.\n";
        }
    }

    // Idempotent stop method for robustness
    void stopEngine() {
        if (isRunning) {
            std::cout << "Engine stopped.\n";
            isRunning = false;
        } else {
            std::cout << "Engine is already stopped.\n";
        }
    }

    // Const getters for proper encapsulation and const-correctness
    int getHorsepower() const { return horsepower; }
    const std::string& getFuelType() const { return fuelType; } // Return by const reference for efficiency
    bool getIsRunning() const { return isRunning; }
};

class Car {
private:
    std::string make;
    std::string model;
    Engine engine; // Composition: Car 'has-a' Engine

public:
    // Constructor using initializer list for all members and passing strings by const reference
    Car(const std::string& mk, const std::string& mdl, int hp, const std::string& ft)
        : make(mk), model(mdl), engine(hp, ft) { // Engine constructor is called here
        std::cout << "Car created: " << make << " " << model << '\n';
    }

    // Delegating methods for car actions
    void start() {
        std::cout << "Car " << make << " " << model << " starting...\n";
        engine.startEngine();
    }

    void stop() {
        std::cout << "Car " << make << " " << model << " stopping...\n";
        engine.stopEngine();
    }

    // Const method to display car information
    void displayCarInfo() const {
        std::cout << "Car Info: " << make << " " << model
                  << " with " << engine.getHorsepower() << "hp "
                  << engine.getFuelType() << " engine. Engine is "
                  << (engine.getIsRunning() ? "running" : "stopped") << ".\n";
    }
};

int main() {
    try {
        Car myCar("BMW", "X5", 300, "Diesel");
        myCar.displayCarInfo();
        myCar.start();
        myCar.start(); // Test idempotency: should print "Engine is already running."
        myCar.stop();
        myCar.stop(); // Test idempotency: should print "Engine is already stopped."

        std::cout << "\n--- Another Car ---" << '\n';
        Car anotherCar("Mercedes", "C-Class", 200, "Petrol");
        anotherCar.displayCarInfo();
        anotherCar.start();
        anotherCar.stop();

        std::cout << "\n--- Testing invalid Engine creation (handled by exception) ---" << '\n';
        // This should throw an exception due to horsepower validation
        // Car badCar("Invalid", "Car", -10, "Water"); // Uncomment to test exception handling
        // badCar.displayCarInfo();

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating engine: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
    }

    return 0;
}