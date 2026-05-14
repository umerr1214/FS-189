#include <iostream>
#include <string>

class Engine {
public:
    int power;
    std::string type;

    Engine(int p, std::string t) : power(p), type(t) {}

    void startEngine() {
        std::cout << "Engine (" << type << ", " << power << " HP) starting..." << std::endl;
    }
};

class Car {
public:
    std::string make;
    std::string model;
    Engine engine; // Composition

    Car(std::string mk, std::string md, int enginePower, std::string engineType)
        : make(mk), model(md), engine(enginePower, engineType) {}

    void start() {
        std::cout << "Car " << make << " " << model << " attempting to start." << std::endl;
        // LOGICAL ERROR: The start() method does NOT call engine.startEngine()
        // as required by the problem statement, but still claims the car started.
        std::cout << "Car started!" << std::endl;
    }
};

int main() {
    // Driver code for testing
    Car myCar("Toyota", "Camry", 180, "Gasoline");
    myCar.start();

    std::cout << std::endl;

    Car electricCar("Tesla", "Model 3", 450, "Electric");
    electricCar.start();

    return 0;
}