#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    std::string fuelType;
    bool isRunning; // State tracking, but not fully utilized for robustness issue

public:
    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft), isRunning(false) {
        // Robustness Issue: No validation for horsepower, allowing negative values
        std::cout << "Engine created: " << horsepower << "hp, " << fuelType << std::endl;
    }

    void startEngine() {
        // Robustness Issue: Not idempotent. Prints message every time, even if already running.
        std::cout << "Engine started: " << horsepower << "hp " << fuelType << std::endl;
        isRunning = true;
    }

    void stopEngine() {
        // Robustness Issue: Not idempotent. Prints message every time, even if already stopped.
        std::cout << "Engine stopped." << std::endl;
        isRunning = false;
    }

    int getHorsepower() const { return horsepower; }
    const std::string& getFuelType() const { return fuelType; }
};

class Car {
private:
    std::string make;
    std::string model;
    Engine engine; // Composition

public:
    Car(const std::string& mk, const std::string& mdl, int hp, const std::string& ft)
        : make(mk), model(mdl), engine(hp, ft) { // Engine constructor called here
        std::cout << "Car created: " << make << " " << model << std::endl;
    }

    void start() {
        std::cout << "Car " << make << " " << model << " starting..." << std::endl;
        engine.startEngine(); // Delegates to engine, inheriting non-idempotent behavior
    }

    void stop() {
        std::cout << "Car " << make << " " << model << " stopping..." << std::endl;
        engine.stopEngine(); // Delegates to engine, inheriting non-idempotent behavior
    }

    void displayCarInfo() const {
        std::cout << "Car Info: " << make << " " << model
                  << " with " << engine.getHorsepower() << "hp "
                  << engine.getFuelType() << " engine." << std::endl;
    }
};

int main() {
    Car myCar("Toyota", "Camry", 150, "Petrol");
    myCar.displayCarInfo();
    myCar.start();
    myCar.start(); // Calling start again without checking state
    myCar.stop();
    myCar.stop(); // Calling stop again without checking state

    std::cout << "\n--- Testing with invalid horsepower (Robustness Issue) ---" << std::endl;
    Car badCar("Ford", "Pinto", -50, "Diesel"); // Robustness issue: negative horsepower allowed
    badCar.displayCarInfo(); // Will display -50hp
    badCar.start();
    badCar.stop();

    return 0;
}