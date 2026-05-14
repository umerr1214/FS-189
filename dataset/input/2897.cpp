#include <iostream>
#include <string>

class Engine {
public:
    int horsepower;
    std::string fuelType;

    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft) {}

    void displayEngineInfo() const {
        std::cout << "Engine: " << horsepower << " HP, Fuel Type: " << fuelType << std::endl;
    }
};

class Car {
private:
    std::string model;
    Engine engine; // Composition

public:
    // LOGICAL ERROR: The Car constructor ignores the provided engineHp and engineFt
    // and always initializes the engine with fixed default values.
    Car(const std::string& m, int engineHp, const std::string& engineFt)
        : model(m), engine(100, "Electric") { // Engine is initialized with fixed values
        // The parameters engineHp and engineFt are not used for the engine member.
    }

    void displayCarInfo() const {
        std::cout << "Car Model: " << model << std::endl;
        engine.displayEngineInfo();
    }
};

int main() {
    Car myCar("Sedan X", 150, "Petrol"); // Intended: 150 HP, Petrol. Actual: 100 HP, Electric.
    myCar.displayCarInfo();

    Car anotherCar("SUV Y", 200, "Diesel"); // Intended: 200 HP, Diesel. Actual: 100 HP, Electric.
    anotherCar.displayCarInfo();

    return 0;
}