#include <iostream>
#include <string>

// Engine class
class Engine {
public:
    Engine() {
        // Constructor for Engine
    }
    void start() {
        std::cout << "Engine started." << std::endl;
    }
};

// Car class using composition
class Car {
private:
    Engine* engine; // SEMANTIC ERROR: Using a raw pointer for composition,
                    // but it is not initialized in the constructor.
public:
    Car() {
        // This constructor does not initialize the 'engine' pointer.
        // It should be 'engine = new Engine();' or use a member initializer list
        // if using a pointer, or simply 'Engine engine;' for direct composition.
    }
    void startCar() {
        std::cout << "Car starting..." << std::endl;
        // Attempting to dereference an uninitialized/wild pointer will lead to a runtime crash.
        engine->start();
        std::cout << "Car is now running." << std::endl;
    }

    // A destructor would also be needed if 'new' was used to allocate engine,
    // but the current error prevents proper object lifecycle management.
    // ~Car() {
    //     delete engine;
    // }
};

// Driver code
int main() {
    Car myCar;
    myCar.startCar(); // This will crash when engine->start() is called due to uninitialized pointer
    return 0;
}