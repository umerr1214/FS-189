#include <iostream>
#include <string>

class Engine {
public:
    Engine() {
        std::cout << "Engine constructed." << std::endl;
    }

private: // Semantic Error: start() is private
    void start() {
        std::cout << "Engine starting..." << std::endl;
    }
};

class Car {
private:
    Engine engine; // Car contains an Engine object

public:
    Car() : engine() { // Initialize the engine
        std::cout << "Car constructed." << std::endl;
    }

    void start() {
        std::cout << "Car initiating start sequence." << std::endl;
        engine.start(); // This will cause a semantic error: trying to access private method
    }
};

int main() {
    Car myCar;
    myCar.start();
    return 0;
}