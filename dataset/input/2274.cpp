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
};

class Car {
private:
    Engine* engine; // Composition using a pointer

public:
    Car(int hp, const std::string& ft) {
        // Semantic Error: The engine pointer is declared but not initialized (no 'new Engine(hp, ft)').
        // This leaves 'engine' as an uninitialized pointer, which will lead to undefined behavior
        // (e.g., a crash) when dereferenced in Car::start().
        // engine = new Engine(hp, ft); // This line is missing
    }

    ~Car() {
        // If 'new' was used, 'delete' would be needed here.
        // Since 'new' was omitted, deleting an uninitialized pointer is also problematic.
        delete engine;
    }

    void start() {
        std::cout << "Car is attempting to start..." << std::endl;
        engine->start(); // Dereferencing an uninitialized or null pointer
    }
};

int main() {
    Car myCar(200, "Electric");
    myCar.start();
    return 0;
}