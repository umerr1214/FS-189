#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

class Engine {
public:
    // Semantic Error: Using 'short' for horsepower instead of 'int'.
    // While syntactically valid, this can lead to data loss (truncation/overflow)
    // for large horsepower values, which is a semantic misuse of the type.
    short horsepower; // Changed from int to short
    std::string fuelType;

    Engine(int hp, std::string ft) : fuelType(ft) {
        // The assignment will compile, but if 'hp' is out of 'short' range,
        // its value will be truncated, leading to incorrect data.
        horsepower = static_cast<short>(hp);
    }

    void displayEngine() const {
        std::cout << "Engine: " << horsepower << " HP, " << fuelType << std::endl;
    }
};

class Car {
public:
    std::string model;
    Engine engine; // Composition

    Car(std::string m, int hp, std::string ft) : model(m), engine(hp, ft) {}

    void displayCarDetails() const {
        std::cout << "Car Model: " << model << std::endl;
        engine.displayEngine();
    }
};

int main() {
    Car myCar("Sedan X", 150, "Petrol"); // 150 fits within 'short' range
    myCar.displayCarDetails();

    Car anotherCar("SUV Y", 40000, "Diesel"); // 40000 exceeds typical 'short' max (e.g., 32767)
    anotherCar.displayCarDetails(); // Semantic error manifests here: horsepower will be an incorrect value due to truncation

    return 0;
}