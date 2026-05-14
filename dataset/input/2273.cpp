#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft) {}

    void start() {
        // Logical Error: This message does not indicate the engine is *starting*
        std::cout << "Engine is currently running at " << horsepower << " HP." << std::endl;
    }
};

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
    Car myCar(180, "Diesel");
    myCar.start();
    return 0;
}