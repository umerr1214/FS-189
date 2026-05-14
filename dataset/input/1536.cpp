#include <iostream>
#include <string>

// Engine class definition
class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // SEMANTIC ERROR: Constructor takes char for horsepower.
    // This allows implicit conversion from char to int, leading to horsepower being an ASCII value
    // instead of the intended numerical value. This compiles but is semantically incorrect.
    Engine(char hp_char, std::string ft) : horsepower(hp_char), fuelType(ft) {
        std::cout << "Engine created: " << horsepower << " HP, " << fuelType << std::endl;
    }

    // Methods (these are fine, they use the 'incorrect' horsepower value)
    void start() {
        std::cout << "Engine starting (" << horsepower << " HP, " << fuelType << ")..." << std::endl;
    }

    void stop() {
        std::cout << "Engine stopping..." << std::endl;
    }
};

// Car class definition
class Car {
private:
    std::string make;
    std::string model;
    Engine engine; // Composition: Car 'has-a' Engine

public:
    // Constructor for Car, delegating Engine construction with the problematic char
    Car(std::string mk, std::string md, char engineHpChar, std::string engineFt) // Takes char
        : make(mk), model(md), engine(engineHpChar, engineFt) { // Passes char to Engine constructor
        std::cout << "Car created: " << make << " " << model << std::endl;
    }

    // Delegate start method to the Engine
    void start() {
        std::cout << make << " " << model << " is attempting to start." << std::endl;
        engine.start();
    }

    // Delegate stop method to the Engine
    void stop() {
        std::cout << make << " " << model << " is attempting to stop." << std::endl;
        engine.stop();
    }
};

// Main function (driver)
int main() {
    // Passing char literals for horsepower, which will be implicitly converted to int (ASCII values)
    Car myCar("Toyota", "Camry", 'A', "Petrol"); // 'A' has ASCII value 65
    myCar.start();
    myCar.stop();

    Car anotherCar("Tesla", "Model 3", 'Z', "Electric"); // 'Z' has ASCII value 90
    anotherCar.start();
    anotherCar.stop();

    return 0;
}