#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr

// Engine class
class Engine {
public:
    std::string serialNumber;

    Engine(const std::string& sn) : serialNumber(sn) {
        std::cout << "[Engine Lifecycle]: Engine " << serialNumber << " is being constructed now." << std::endl;
    }

    ~Engine() {
        std::cout << "[Engine Lifecycle]: Engine " << serialNumber << " is being destructed now." << std::endl;
    }

    void start() const {
        std::cout << "[Engine Operation]: Engine " << serialNumber << " initiating start sequence..." << std::endl;
    }

    void performMaintenance() const {
        std::cout << "[Engine Maintenance]: Performing routine check on Engine " << serialNumber << "." << std::endl;
    }
};

// Car class demonstrating readability/efficiency issues
class Car {
private:
    // Using std::unique_ptr for composition, which involves heap allocation and indirection
    // when direct member composition would be simpler and more efficient for strict ownership.
    std::unique_ptr<Engine> engine;
    std::string model;
    std::string color;

public:
    // Constructor: Car creates its Engine
    Car(const std::string& carModel, const std::string& engineSN, const std::string& carColor)
        : model(carModel), color(carColor) {
        // Explicitly creating Engine on the heap using new, then wrapping in unique_ptr
        engine = std::make_unique<Engine>(engineSN); 
        std::cout << "[Car Lifecycle]: Car " << model << " (" << color << ") object created. Engine " << engineSN << " has been installed." << std::endl;
        logCarDetails(); // Overly verbose logging
    }

    // Destructor: Car destroys its Engine (handled automatically by unique_ptr)
    ~Car() {
        std::cout << "[Car Lifecycle]: Car " << model << " (" << color << ") object is being destructed. Associated Engine " << engine->serialNumber << " will be destroyed." << std::endl;
    }

    void drive() const {
        std::cout << "[Car Operation]: Car " << model << " (" << color << ") is preparing to drive." << std::endl;
        if (engine) { // Check for engine existence, though unique_ptr guarantees it if constructed
            engine->start();
            std::cout << "[Car Operation]: Car " << model << " is now moving." << std::endl;
        } else {
            std::cout << "[Car Operation]: Warning! Car " << model << " cannot drive without an engine!" << std::endl;
        }
    }

    void checkEngineStatus() const {
        std::cout << "[Car Status]: Querying engine status for Car " << model << "." << std::endl;
        if (engine) {
            engine->performMaintenance();
        } else {
            std::cout << "[Car Status]: No engine found to check." << std::endl;
        }
    }

    void logCarDetails() const {
        std::cout << "--- Car Details ---" << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Color: " << color << std::endl;
        if (engine) {
            std::cout << "Engine Serial: " << engine->serialNumber << std::endl;
        } else {
            std::cout << "Engine: Not installed" << std::endl;
        }
        std::cout << "-------------------" << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Readability / Efficiency Issue ---" << std::endl;

    std::cout << "\nCreating a luxurious sports car." << std::endl;
    Car sportsCar("Speedster X", "SPRT-E9000", "Red");
    sportsCar.drive();
    sportsCar.checkEngineStatus();

    std::cout << "\nCreating a standard family sedan." << std::endl;
    Car familyCar("Family Cruiser", "FAM-E5000", "Blue");
    familyCar.drive();

    std::cout << "\nObjects going out of scope." << std::endl;
    return 0;
}