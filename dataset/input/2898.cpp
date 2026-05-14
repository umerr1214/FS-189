#include <iostream>
#include <string>

class Engine {
public:
    int horsepower;
    std::string fuelType;

    // Only a parameterized constructor is provided. No default constructor.
    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft) {}

    void displayEngineInfo() const {
        std::cout << "Engine: " << horsepower << " HP, Fuel Type: " << fuelType << std::endl;
    }
};

class Car {
private:
    std::string model;
    Engine engine; // Composition

public:
    // SEMANTIC ERROR: The 'engine' member is not explicitly initialized in the
    // initializer list. Since the Engine class has no default constructor,
    // the compiler will attempt to default-construct 'engine' before the
    // constructor body, leading to a compilation error.
    Car(const std::string& m, int engineHp, const std::string& engineFt)
        : model(m) { // 'engine' is implicitly default-constructed here, which fails.
        // If it compiled, the following would be an assignment, not initialization:
        // engine = Engine(engineHp, engineFt);
    }

    void displayCarInfo() const {
        std::cout << "Car Model: " << model << std::endl;
        engine.displayEngineInfo();
    }
};

int main() {
    // This part of the main function will not compile due to the semantic error
    // in the Car constructor.
    Car myCar("Sedan X", 150, "Petrol");
    myCar.displayCarInfo();

    Car anotherCar("SUV Y", 200, "Diesel");
    anotherCar.displayCarInfo();

    return 0;
}