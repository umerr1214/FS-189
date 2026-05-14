#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Engine only has a parameterized constructor. No default constructor.
    Engine(int hp, const std::string& fuel) : horsepower(hp), fuelType(fuel) {
        std::cout << "Engine constructed: " << horsepower << "hp, " << fuelType << std::endl;
    }

    ~Engine() {
        std::cout << "Engine destroyed: " << horsepower << "hp, " << fuelType << std::endl;
    }

    void display() const {
        std::cout << "Engine details: " << horsepower << "hp, " << fuelType << std::endl;
    }
};

class Car {
public:
    Engine carEngine; // Composition

    // Semantic Error: Car's constructor attempts to initialize carEngine without
    // providing arguments to Engine's *only* parameterized constructor in the initializer list.
    // This violates C++ object construction rules because Engine cannot be default-constructed.
    Car(int hp, const std::string& fuel) { // Missing : carEngine(hp, fuel)
        std::cout << "Car constructed." << std::endl;
    }

    ~Car() {
        std::cout << "Car destroyed." << std::endl;
    }

    void start() const {
        // This line would also fail if the object wasn't properly constructed
        // carEngine.display();
        std::cout << "Car started (details would be here if engine was initialized)." << std::endl;
    }
};

int main() {
    // This line will cause a compilation error due to the Car constructor's semantic flaw:
    // trying to default-construct an Engine object that only has a parameterized constructor.
    // Car myCar(300, "Electric");
    // myCar.start();
    return 0;
}