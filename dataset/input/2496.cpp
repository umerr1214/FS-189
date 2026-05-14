#include <iostream>

class Engine {
public:
    Engine() {
        std::cout << "Engine created." << std::endl;
    }
    ~Engine() {
        std::cout << "Engine destroyed." << std::endl;
    }

    // Semantic Error: Explicitly delete copy constructor and assignment operator
    // to prevent copying of Engine objects.
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
};

class Car {
public:
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
    Car car1;
    // Semantic Error: Attempting to copy a Car object, which implicitly
    // tries to copy its Engine member. Since Engine's copy constructor
    // is deleted, this operation is semantically invalid and will result
    // in a compilation error.
    Car car2 = car1; 
    std::cout << "--- End of main ---" << std::endl;
    return 0;
}