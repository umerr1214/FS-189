#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Robustness issue: No validation for horsepower. Allows negative or zero values,
    // which are physically nonsensical for engine power and could lead to incorrect
    // behavior if other parts of the system assume positive horsepower.
    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft) {}

    void displayEngineInfo() const {
        std::cout << "  Engine Horsepower: " << horsepower << " HP" << std::endl;
        std::cout << "  Engine Fuel Type: " << fuelType << std::endl;
    }

    int getHorsepower() const { return horsepower; }
    std::string getFuelType() const { return fuelType; }
};

class Car {
private:
    std::string model;
    Engine carEngine; // Composition: Car contains an Engine object

public:
    // Car constructor initializes its Engine member
    Car(const std::string& m, int engine_hp, const std::string& engine_ft)
        : model(m), carEngine(engine_hp, engine_ft) {}

    void displayCarInfo() const {
        std::cout << "Car Model: " << model << std::endl;
        carEngine.displayEngineInfo();
    }
};

int main() {
    // Standard case
    Car car1("Sedan X", 150, "Petrol");
    car1.displayCarInfo();
    std::cout << "--------------------" << std::endl;

    // Robustness issue demonstrated: Car with a physically impossible engine horsepower
    Car car2("Electric Y", -50, "Electric"); // Negative horsepower is nonsensical
    car2.displayCarInfo();
    std::cout << "--------------------" << std::endl;

    // Another problematic case: zero horsepower
    Car car3("Truck Z", 0, "Diesel");
    car3.displayCarInfo();
    std::cout << "--------------------" << std::endl;

    return 0;
}