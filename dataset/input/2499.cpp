#include <iostream>
#include <string>

// Engine class
class Engine {
public:
    std::string serialNumber;

    // Constructor for Engine
    Engine(const std::string& sn) : serialNumber(sn) {
        std::cout << "Engine " << serialNumber << " created." << std::endl;
    }

    // Destructor for Engine
    ~Engine() {
        std::cout << "Engine " << serialNumber << " destroyed." << std::endl;
    }

    // Member function to demonstrate engine functionality
    void start() const {
        std::cout << "Engine " << serialNumber << " starting..." << std::endl;
    }
};

// Car class demonstrating composition with Engine
class Car {
private:
    Engine engine; // Direct member composition: Engine is part of Car
    std::string model;

public:
    // Constructor for Car:
    // The Engine member 'engine' is initialized in the member initializer list.
    // Its constructor is called before Car's constructor body.
    Car(const std::string& carModel, const std::string& engineSN)
        : engine(engineSN), model(carModel) { // Engine constructor called here
        std::cout << "Car " << model << " created with Engine " << engineSN << "." << std::endl;
    }

    // Destructor for Car:
    // The Engine member 'engine' is automatically destroyed after Car's destructor body finishes.
    ~Car() {
        std::cout << "Car " << model << " destroying." << std::endl;
        // The 'engine' member's destructor is implicitly called here
        std::cout << "Car " << model << " destroyed." << std::endl;
    }

    // Member function to demonstrate car functionality
    void drive() const {
        std::cout << "Car " << model << " is driving." << std::endl;
        engine.start(); // Accessing composed Engine's functionality
    }

    std::string getModel() const {
        return model;
    }
};

int main() {
    std::cout << "--- Demonstrating Correct Composition and Lifetime Management ---" << std::endl;

    { // Scope block to clearly show object lifetimes
        std::cout << "\nCreating a Car object: myCar." << std::endl;
        Car myCar("Sedan X", "V8-12345"); // Car and its Engine are created
        myCar.drive();
        std::cout << "myCar model: " << myCar.getModel() << std::endl;

        std::cout << "\nCreating another Car object: yourCar." << std::endl;
        Car yourCar("SUV Z", "V6-67890"); // Another Car and its Engine are created
        yourCar.drive();

        std::cout << "\nBoth cars are active. Now leaving the scope." << std::endl;
    } // yourCar goes out of scope, then its Engine is destroyed.
      // myCar goes out of scope, then its Engine is destroyed.

    std::cout << "\nAll Car objects (and their Engines) have been destroyed." << std::endl;

    return 0;
}