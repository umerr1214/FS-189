#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft) {}

    void start() {
        std::cout << "Engine with " << horsepower << " HP (" << fuelType << ") started!" << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

class Car {
private:
    Engine engine; // Composition

public:
    Car(int hp, const std::string& ft) : engine(hp, ft) {}

    void start() {
        std::cout << "Car is attempting to start..." << std::endl;
        engine.start(); // Delegate to Engine's start method
    }
};

int main() {
    Car myCar(150, "Gasoline");
    myCar.start();
    return 0;
}