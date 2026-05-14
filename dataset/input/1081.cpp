#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft) {
        // Robustness Issue: No validation for horsepower, e.g., negative values are allowed
    }

    void start() {
        // Robustness Issue: No actual state change or check if already started
        std::cout << "Engine started! Fuel: " << fuelType << ", HP: " << horsepower << std::endl;
    }

    int getHorsepower() { // Robustness Issue: Not const-correct
        return horsepower;
    }

    std::string getFuelType() { // Robustness Issue: Not const-correct
        return fuelType;
    }
};

class Car {
private:
    std::string make;
    std::string model;
    Engine engine; // Composition

public:
    Car(const std::string& mk, const std::string& md, int engine_hp, const std::string& engine_ft)
        : make(mk), model(md), engine(engine_hp, engine_ft) {
    }

    void startCar() {
        std::cout << "Attempting to start Car: " << make << " " << model << std::endl;
        // Robustness Issue: Calls engine's start method directly without checks or state management
        engine.start();
    }

    std::string getMake() { // Robustness Issue: Not const-correct
        return make;
    }

    std::string getModel() { // Robustness Issue: Not const-correct
        return model;
    }
};

int main() {
    // Test case 1: Normal car
    Car myCar("Toyota", "Camry", 200, "Gasoline");
    myCar.startCar();
    std::cout << std::endl;

    // Test case 2: Car with potentially problematic engine (negative horsepower)
    // Robustness issue: negative HP is allowed and printed
    Car problematicCar("Ford", "Pinto", -50, "Gasoline");
    problematicCar.startCar();
    std::cout << std::endl;

    // Test case 3: Calling startCar multiple times without state management
    // Robustness issue: prints "Engine started!" repeatedly without reflecting actual engine state
    Car repeatedStartCar("Honda", "Civic", 150, "Petrol");
    repeatedStartCar.startCar();
    repeatedStartCar.startCar();
    std::cout << std::endl;

    return 0;
}