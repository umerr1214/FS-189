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
    Car(const std::string& m, int engineHp, const std::string& engineFt)
        : model(m), engine(engineHp, engineFt) {}

    void displayCarInfo() const {
        std::cout << "Car Model: " << model << std::endl;
        engine.displayEngineInfo();
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Car myCar("Sedan X", 150, "Petrol");
    myCar.displayCarInfo();

    Car anotherCar("SUV Y", 200, "Diesel");
    anotherCar.displayCarInfo();

    return 0;
}