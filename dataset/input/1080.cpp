#include <iostream>
#include <string>

class Engine {
public:
    int horsepower;
    std::string fuelType;

    Engine(int hp, std::string ft) : horsepower(hp), fuelType(ft) {}

private: // Semantic Error: Making start() private, violating composition principle
    void start() {
        std::cout << "Engine started! Horsepower: " << horsepower << ", Fuel Type: " << fuelType << std::endl;
    }
};

class Car {
private:
    std::string make;
    std::string model;
    Engine engine; // Composition

public:
    Car(std::string mk, std::string md, int engineHP, std::string engineFT)
        : make(mk), model(md), engine(engineHP, engineFT) {}

    void startCar() {
        std::cout << "Starting the " << make << " " << model << "..." << std::endl;
        engine.start(); // This will cause a semantic error (access violation)
    }

    void displayCarInfo() {
        std::cout << "Car: " << make << " " << model << std::endl;
        std::cout << "Engine HP: " << engine.horsepower << ", Fuel Type: " << engine.fuelType << std::endl;
    }
};

int main() {
    Car myCar("Toyota", "Camry", 180, "Petrol");
    myCar.startCar();
    myCar.displayCarInfo();
    return 0;
}