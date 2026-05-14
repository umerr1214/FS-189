#include <iostream>
#include <string>

class Engine {
public:
    int horsepower;
    std::string fuelType;

    Engine(int hp, std::string ft) : horsepower(hp), fuelType(ft) {}

    void start() {
        std::cout << "Engine started! Horsepower: " << horsepower << ", Fuel Type: " << fuelType << std::endl;
    }
} // Missing semicolon here

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
        engine.start(); // Delegate to the Engine's start method
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