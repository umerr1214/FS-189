#include <iostream>
#include <string>

class Engine {
public:
    int horsepower;
    std::string fuelType;

    Engine(int hp, std::string ft) : horsepower(hp), fuelType(ft) {}

    void displayEngine() const {
        std::cout << "Engine: " << horsepower << " HP, " << fuelType << std::endl;
    }
}; // Syntax Error: Missing semicolon here

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
    Car myCar("Sedan X", 150, "Petrol");
    myCar.displayCarDetails();

    Car anotherCar("SUV Y", 200, "Diesel");
    anotherCar.displayCarDetails();

    return 0;
}