#include <iostream>
#include <string>

class Engine {
public:
    int horsepower;
    std::string fuelType;

    Engine(int hp, std::string ft) : horsepower(hp), fuelType(ft) {}
    Engine() : horsepower(0), fuelType("Unknown") {} // Default constructor for flexibility

    void displayEngine() const {
        std::cout << "Engine: " << horsepower << " HP, " << fuelType << std::endl;
    }
};

class Car {
public:
    std::string model;
    Engine engine; // Composition

    // Logical Error: The Car constructor ignores the provided horsepower and fuelType
    // for the engine and instead initializes the engine with hardcoded default values.
    Car(std::string m, int hp, std::string ft) : model(m), engine(100, "Standard Fuel") {
        // The parameters 'hp' and 'ft' are received but not used to initialize the 'engine' member,
        // leading to a logical error where the car's engine details are not as expected.
    }

    void displayCarDetails() const {
        std::cout << "Car Model: " << model << std::endl;
        engine.displayEngine();
    }
};

int main() {
    Car myCar("Sedan X", 150, "Petrol");
    myCar.displayCarDetails(); // Expected: 150 HP, Petrol. Actual: 100 HP, Standard Fuel

    Car anotherCar("SUV Y", 200, "Diesel");
    anotherCar.displayCarDetails(); // Expected: 200 HP, Diesel. Actual: 100 HP, Standard Fuel

    return 0;
}