#include <iostream>

class Engine {
public:
    Engine() {
        std::cout << "Engine created." << std::endl;
    }
    ~Engine() {
        std::cout << "Engine destroyed." << std::endl;
    }
};

class Car {
pubic: // Syntax error: 'pubic' instead of 'public'
    Car() : engine_() {
        std::cout << "Car created." << std::endl;
    }
    ~Car() {
        std::cout << "Car destroyed." << std::endl;
    }

private:
    Engine engine_; // Composition: Engine is a member of Car
};

int main() {
    std::cout << "--- Starting main ---" << std::endl;
    Car myCar;
    std::cout << "--- End of main ---" << std::endl;
    return 0;
}