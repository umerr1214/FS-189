#include <iostream>
#include <string>

// Engine class definition
class Engine {
private:
    int power;
    std::string type;

public:
    // Constructor for Engine
    Engine(int p, const std::string& t) : power(p), type(t) {}

    // Method to start the engine and print its details
    void startEngine() {
        std::cout << "Engine (" << type << ", " << power << " HP) started." << std::endl;
    }

    // Optional: Getters for power and type, though not strictly needed for this problem's output
    int getPower() const { return power; }
    std::string getType() const { return type; }
};

// Car class definition
class Car {
private:
    std::string make;
    std::string model;
    Engine carEngine; // Composition: Car contains an Engine object

public:
    // Constructor for Car, initializing its own members and the composed Engine object
    Car(const std::string& mk, const std::string& md, int enginePower, const std::string& engineType)
        : make(mk), model(md), carEngine(enginePower, engineType) {}

    // Method to start the car, which internally calls the engine's startEngine method
    void start() {
        std::cout << "Starting " << make << " " << model << "..." << std::endl;
        carEngine.startEngine(); // Delegation: Car uses its Engine to perform the start action
        std::cout << make << " " << model << " is now running." << std::endl;
    }
};

// Main function to demonstrate the classes
int main() {
    // Create a Car object
    Car myCar("Honda", "Civic", 158, "Gasoline");

    // Start the car
    myCar.start();

    std::cout << "\n--------------------\n" << std::endl;

    // Create another Car object
    Car sportsCar("Porsche", "911", 443, "Premium Unleaded");
    sportsCar.start();

    return 0;
}