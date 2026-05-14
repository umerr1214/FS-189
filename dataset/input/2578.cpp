#include <iostream>
#include <string>

class Engine {
public:
    int horsepower;
    std::string fuelType;

    Engine(int hp, const std::string& fuel) : horsepower(hp), fuelType(fuel) {
        std::cout << "Engine constructed: " << horsepower << "hp, " << fuelType << std::endl;
    }

    ~Engine() {
        std::cout << "Engine destroyed: " << horsepower << "hp, " << fuelType << std::endl;
    }
} // ERROR: Missing semicolon here, leading to a syntax error.

class Car {
public:
    Engine carEngine; // Composition

    Car(int hp, const std::string& fuel) : carEngine(hp, fuel) {
        std::cout << "Car constructed." << std::endl;
    }

    ~Car() {
        std::cout << "Car destroyed." << std::endl;
    }

    void start() const {
        std::cout << "Car with " << carEngine.horsepower << "hp engine started." << std::endl;
    }
};

int main() {
    // This code will not compile due to the syntax error.
    // If it were to compile, it would create a Car object.
    // Car myCar(200, "Gasoline");
    // myCar.start();
    return 0;
}