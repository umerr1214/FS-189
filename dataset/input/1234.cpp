#include <iostream>
#include <string>
#include <utility> // Required for std::move

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    Engine(int hp, std::string ft) : horsepower(hp), fuelType(std::move(ft)) {}

    int getHorsepower() const {
        return horsepower;
    }

    const std::string& getFuelType() const {
        return fuelType;
    }
}; // Missing semicolon here, causing a syntax error

class Car {
private:
    Engine engine;
    std::string model;

public:
    Car(std::string m, int engineHp, std::string engineFt)
        : model(std::move(m)), engine(engineHp, std::move(engineFt)) {}

    void displayCarDetails() const {
        std::cout << "Car Model: " << model << std::endl;
        std::cout << "Engine Horsepower: " << engine.getHorsepower() << std::endl;
        std::cout << "Engine Fuel Type: " << engine.getFuelType() << std::endl;
    }
} // Another missing semicolon after Car class definition

int main() {
    Car myCar("Sedan", 200, "Gasoline");
    myCar.displayCarDetails();
    return 0;
}