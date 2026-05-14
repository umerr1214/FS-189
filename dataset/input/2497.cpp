#include <iostream>
#include <string>

// Engine class
class Engine {
public:
    std::string serialNumber;

    Engine(const std::string& sn) : serialNumber(sn) {
        std::cout << "Engine " << serialNumber << " created." << std::endl;
    }

    ~Engine() {
        std::cout << "Engine " << serialNumber << " destroyed." << std::endl;
    }

    void start() const {
        std::cout << "Engine " << serialNumber << " starting..." << std::endl;
    }
};

// Car class demonstrating a robustness issue (missing copy control for raw pointer)
class Car {
private:
    Engine* engine; // Raw pointer to Engine
    std::string model;

public:
    // Constructor: Car creates its Engine
    Car(const std::string& carModel, const std::string& engineSN)
        : model(carModel) {
        engine = new Engine(engineSN); // Dynamically allocate Engine
        std::cout << "Car " << model << " created with Engine " << engineSN << "." << std::endl;
    }

    // Destructor: Car destroys its Engine
    ~Car() {
        std::cout << "Car " << model << " destroying." << std::endl;
        delete engine; // Deallocate Engine
        std::cout << "Car " << model << " destroyed." << std::endl;
    }

    // NOTE: Missing copy constructor and copy assignment operator.
    // This will lead to shallow copies of the 'engine' pointer,
    // causing double-free issues when copies are destroyed.

    void drive() const {
        if (engine) {
            std::cout << "Car " << model << " is driving." << std::endl;
            engine->start();
        } else {
            std::cout << "Car " << model << " cannot drive, no engine!" << std::endl;
        }
    }

    std::string getModel() const {
        return model;
    }
};

int main() {
    std::cout << "--- Demonstrating Robustness Issue (Double Free) ---" << std::endl;

    // Create a Car object
    Car car1("Sedan", "ENG123");
    car1.drive();

    std::cout << "\nAttempting to copy car1 to car2 (this will cause a robustness issue later)." << std::endl;
    Car car2 = car1; // Shallow copy occurs here because copy constructor is implicitly generated
                     // and just copies the raw pointer value.

    std::cout << "Car2 model: " << car2.getModel() << std::endl;
    car2.drive();

    std::cout << "\nLeaving scope. car2's destructor will be called, then car1's. "
              << "This will attempt to delete the same engine pointer twice." << std::endl;

    // When car2 goes out of scope, it deletes 'engine'.
    // When car1 goes out of scope, it attempts to delete the SAME 'engine' pointer again,
    // leading to a double-free runtime error.

    return 0;
}