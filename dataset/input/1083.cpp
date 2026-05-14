#include <iostream>
#include <string>
#include <stdexcept> // For more robust error handling if needed, though cerr is used here.

class Engine {
private:
    int horsepower;
    std::string fuelType;
    bool isStarted; // Added state for robust engine behavior

public:
    // Uses initializer list for all members and includes basic validation
    Engine(int hp, const std::string& ft)
        : horsepower(hp), fuelType(ft), isStarted(false) {
        if (horsepower < 0) {
            std::cerr << "Warning: Engine horsepower cannot be negative. Setting to 0." << std::endl;
            this->horsepower = 0; // Correctly sets the member
        }
    }

    void start() {
        if (!isStarted) {
            std::cout << "Engine started! Fuel: " << fuelType << ", HP: " << horsepower << std::endl;
            isStarted = true;
        } else {
            std::cout << "Engine is already running." << std::endl;
        }
    }

    void stop() {
        if (isStarted) {
            std::cout << "Engine stopped." << std::endl;
            isStarted = false;
        } else {
            std::cout << "Engine is already stopped." << std::endl;
        }
    }

    // Const-correct getters, returning by const reference for strings for efficiency
    int getHorsepower() const {
        return horsepower;
    }

    const std::string& getFuelType() const {
        return fuelType;
    }

    bool getIsStarted() const {
        return isStarted;
    }
};

class Car {
private:
    std::string make;
    std::string model;
    Engine engine; // Composition: Engine object as a private member

public:
    // Uses initializer list for all members (including the composed Engine object)
    Car(const std::string& mk, const std::string& md, int engine_hp, const std::string& engine_ft)
        : make(mk), model(md), engine(engine_hp, engine_ft) {
    }

    void startCar() {
        std::cout << "Attempting to start Car: " << make << " " << model << std::endl;
        engine.start(); // Internally calls start() on its Engine object
    }

    void stopCar() { // Added for more complete and robust behavior
        std::cout << "Attempting to stop Car: " << make << " " << model << std::endl;
        engine.stop();
    }

    // Const-correct getters, returning by const reference for efficiency
    const std::string& getMake() const {
        return make;
    }

    const std::string& getModel() const {
        return model;
    }
};

int main() {
    // Demonstrate correct functionality and robustness
    Car myCar("Tesla", "Model 3", 450, "Electric");
    myCar.startCar(); // Expected: Engine started!
    myCar.startCar(); // Expected: Engine is already running. (Robustness check)
    myCar.stopCar();  // Expected: Engine stopped.
    myCar.stopCar();  // Expected: Engine is already stopped. (Robustness check)
    std::cout << std::endl;

    Car anotherCar("Porsche", "911", 400, "Premium Gasoline");
    anotherCar.startCar();
    std::cout << "Car make: " << anotherCar.getMake() << ", model: " << anotherCar.getModel() << std::endl;
    std::cout << std::endl;

    // Test with an initial problematic engine value, handled gracefully by Engine constructor
    Car badEngineCar("Lada", "Niva", -10, "Diesel"); // Horsepower becomes 0 due to internal validation
    badEngineCar.startCar();
    std::cout << std::endl;

    return 0;
}