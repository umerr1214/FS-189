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

    void display() const {
        std::cout << "Engine details: " << horsepower << "hp, " << fuelType << std::endl;
    }
};

class Car {
public:
    Engine* carEngine; // Logical Error: Using a raw pointer instead of direct composition

    Car(int hp, const std::string& fuel) {
        carEngine = new Engine(hp, fuel); // Allocate Engine on heap
        std::cout << "Car constructed." << std::endl;
    }

    ~Car() {
        // Logical Error: Missing 'delete carEngine;' here, leading to a memory leak.
        // The Engine object allocated on the heap is not automatically destroyed with the Car object,
        // thus failing to meet the composition requirement for automatic destruction.
        std::cout << "Car destroyed." << std::endl;
    }

    void start() const {
        if (carEngine) {
            std::cout << "Car with " << carEngine->horsepower << "hp engine started." << std::endl;
        } else {
            std::cout << "Car has no engine!" << std::endl;
        }
    }
};

int main() {
    std::cout << "--- Creating Car ---" << std::endl;
    Car myCar(250, "Diesel");
    myCar.start();
    std::cout << "--- Car goes out of scope ---" << std::endl;
    // When myCar is destroyed, Car's destructor is called, but Engine's destructor is NOT called
    // because carEngine was allocated with new and not explicitly deleted. This causes a memory leak.
    return 0;
}