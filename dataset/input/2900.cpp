#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Readability/Efficiency issue: Initializes members via assignment in the body,
    // rather than using an initializer list. For `std::string fuelType`, this means
    // it's default-constructed and then assigned, which is less efficient than direct initialization.
    Engine(int hp, const std::string& ft) {
        horsepower = hp; // OK for int, but inconsistent with best practice for objects
        fuelType = ft;   // Inefficient: default constructs 'fuelType' then assigns
    }

    void displayEngineInfo() const {
        std::cout << "  Engine Horsepower: " << horsepower << " HP" << std::endl;
        std::cout << "  Engine Fuel Type: " << fuelType << std::endl;
    }

    int getHorsepower() const { return horsepower; }
    std::string getFuelType() const { return fuelType; }
};

class Car {
private:
    std::string model;
    Engine carEngine; // Composition

public:
    // Readability/Efficiency issue: Initializes 'model' via assignment in the body.
    // The `carEngine` member must be initialized via an initializer list to compile
    // because `Engine` has no default constructor.
    Car(const std::string& m, int engine_hp, const std::string& engine_ft)
        : carEngine(engine_hp, engine_ft) // Correctly uses initializer list for composed object
    {
        model = m; // Inefficient: default constructs 'model' then assigns
    }

    void displayCarInfo() const {
        std::cout << "Car Model: " << model << std::endl;
        carEngine.displayEngineInfo();
    }
};

int main() {
    Car myCar("Sedan X", 150, "Petrol");
    myCar.displayCarInfo();
    std::cout << "--------------------" << std::endl;

    Car sportsCar("Speedster Z", 300, "Premium Petrol");
    sportsCar.displayCarInfo();
    std::cout << "--------------------" << std::endl;

    return 0;
}