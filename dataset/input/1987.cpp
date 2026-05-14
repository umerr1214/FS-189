#include <iostream>
#include <string>

// Engine class - Robustness Issue: Lacks input validation for meaningful data
class Engine {
public:
    // Constructor allows potentially invalid states (negative/zero horsepower, empty fuel type)
    Engine(int hp, std::string ft) : horsepower(hp), fuelType(ft) {
        // No validation performed here. A "robust" class would validate inputs
        // or normalize them (e.g., set negative horsepower to 0).
    }

    int getHorsepower() const {
        return horsepower;
    }

    const std::string& getFuelType() const {
        return fuelType;
    }

    void displayEngineInfo() const {
        std::cout << "  Engine Horsepower: " << horsepower << " HP" << std::endl;
        // If fuelType is empty, it will just print "Fuel Type: " or a placeholder
        std::cout << "  Engine Fuel Type: " << (fuelType.empty() ? "[Not Specified]" : fuelType) << std::endl;
        // The ternary operator here slightly mitigates the display, but the object itself still holds an empty string.
        // The core robustness issue is allowing invalid data into the object state in the first place.
    }

private:
    int horsepower;
    std::string fuelType;
};

// Car class - Demonstrates composition with an Engine object
class Car {
public:
    // Constructor for Car, directly initializes its Engine member
    Car(const std::string& mdl, int yr, int engineHp, std::string engineFt)
        : model(mdl), year(yr), carEngine(engineHp, engineFt) {
        // Car doesn't validate engineHp or engineFt either, relying on Engine's (lack of) validation.
    }

    void displayCarInfo() const {
        std::cout << "Car Model: " << model << std::endl;
        std::cout << "Car Year: " << year << std::endl;
        carEngine.displayEngineInfo(); // Delegate to Engine's display method
    }

private:
    std::string model;
    int year;
    Engine carEngine; // Composition: Car contains an Engine object
};

int main() {
    // Test cases demonstrating robustness issues:
    // 1. Car with a negative horsepower engine
    Car car1("Sporty Model X", 2023, -100, "Gasoline");
    std::cout << "--- Car 1 Info (Negative Horsepower) ---" << std::endl;
    car1.displayCarInfo();
    std::cout << std::endl;

    // 2. Car with zero horsepower and an empty fuel type
    Car car2("City Commuter", 2021, 0, "");
    std::cout << "--- Car 2 Info (Zero Horsepower, Empty Fuel Type) ---" << std::endl;
    car2.displayCarInfo();
    std::cout << std::endl;

    // 3. A more "normal" car, to show it still works with valid inputs
    Car car3("Luxury Sedan", 2024, 300, "Electric");
    std::cout << "--- Car 3 Info (Normal) ---" << std::endl;
    car3.displayCarInfo();
    std::cout << std::endl;

    return 0;
}