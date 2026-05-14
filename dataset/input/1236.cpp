#include <iostream>
#include <string>
#include <utility> // Required for std::move

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Constructor is public
    Engine(int hp, std::string ft) : horsepower(hp), fuelType(std::move(ft)) {}

    // No public getters for horsepower or fuelType,
    // making them inaccessible from outside the Engine class.
    // int getHorsepower() const { return horsepower; }
    // const std::string& getFuelType() const { return fuelType; }
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
        // Semantic error: Attempting to access private members of Engine directly.
        // This violates encapsulation and will result in a compile-time error.
        std::cout << "Engine Horsepower: " << engine.horsepower << std::endl;
        std::cout << "Engine Fuel Type: " << engine.fuelType << std::endl;
    }
};

int main() {
    Car myCar("Sports 911", 450, "Premium Gasoline");
    myCar.displayCarDetails();
    return 0;
}