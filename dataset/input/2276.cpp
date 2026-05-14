#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Constructor: Passes fuelType by value (inefficient copy)
    // Uses assignment instead of initializer list for members (less readable/efficient for string)
    Engine(int hp, std::string ft) { // ft is passed by value, incurring a copy
        this->horsepower = hp; // Using this-> for primitives is unnecessary and verbose
        this->fuelType = ft;   // Assignment after default construction of fuelType, then copy
        std::cout << "Engine constructed (inefficiently)." << std::endl;
    }

    void start() const {
        std::cout << "Engine with " << horsepower << " HP and fuel type '" << fuelType << "' started." << std::endl;
    }
};

class Car {
private:
    Engine engine; // Composition (will be default-constructed first)

public:
    // Car constructor: Does NOT use initializer list for the 'engine' member.
    // This results in 'engine' being default-constructed first, then assigned,
    // which is less efficient and less readable than direct initialization.
    Car(int hp, std::string ft) {
        // 'engine' is default-constructed here before the body of the constructor runs.
        // Then, a temporary Engine object is created and assigned to 'engine'.
        // This involves an extra default construction and an assignment operation.
        this->engine = Engine(hp, ft); // Inefficient assignment
        std::cout << "Car constructed (engine assigned after default construction)." << std::endl;
    }

    void start() {
        std::cout << "Car is preparing to start its engine..." << std::endl;
        engine.start();
    }
};

int main() {
    Car myCar(200, "Diesel");
    myCar.start();
    std::cout << "---" << std::endl;

    Car anotherCar(120, "Electric");
    anotherCar.start();
    std::cout << "---" << std::endl;

    return 0;
}