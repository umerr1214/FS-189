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
};

class Car {
private:
    Engine engine;
    std::string model;

public:
    Car(std::string m, int engineHp, std::string engineFt)
        : model(std::move(m)), engine(engineHp, std::move(engineFt)) {}

    void displayCarDetails() const {
        std::cout << "Car Model: " << model << std::endl;
        // Logical error: Intentionally adding 100 to horsepower when displaying
        std::cout << "Engine Horsepower: " << engine.getHorsepower() + 100 << std::endl;
        std::cout << "Engine Fuel Type: " << engine.getFuelType() << std::endl;
    }
};

int main() {
    Car myCar("SUV X5", 300, "Diesel");
    myCar.displayCarDetails();

    Car anotherCar("Compact S", 150, "Electric");
    anotherCar.displayCarDetails();
    return 0;
}