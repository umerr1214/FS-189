#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

class Engine {
private:
    int power;
    std::string type;

public:
    Engine(int p, const std::string& t) : power(p), type(t) {}

    void startEngine() {
        // Robustness Issue: Does not validate 'power'.
        // An engine with 0 or negative power can still "start" logically,
        // which is unrealistic and might indicate a design flaw or missing validation.
        if (power <= 0) {
            std::cout << "Engine (" << type << ", " << power << " HP) attempting to start... (Warning: Illogical power value)" << std::endl;
        } else {
            std::cout << "Engine (" << type << ", " << power << " HP) started successfully." << std::endl;
        }
    }

    int getPower() const { return power; }
    std::string getType() const { return type; }
};

class Car {
private:
    std::string make;
    std::string model;
    Engine carEngine; // Composition

public:
    Car(const std::string& mk, const std::string& md, int enginePower, const std::string& engineType)
        : make(mk), model(md), carEngine(enginePower, engineType) {}

    void start() {
        std::cout << "Starting " << make << " " << model << "..." << std::endl;
        carEngine.startEngine(); // Calls the engine's startEngine method
        std::cout << make << " " << model << " is ready to drive." << std::endl;
    }
};

int main() {
    // Test Case 1: Normal engine
    Car car1("Toyota", "Camry", 180, "Gasoline");
    car1.start();
    std::cout << "--------------------" << std::endl;

    // Test Case 2: Engine with zero power (robustness issue)
    Car car2("Electric", "Scooter", 0, "Electric");
    car2.start();
    std::cout << "--------------------" << std::endl;

    // Test Case 3: Engine with negative power (robustness issue)
    Car car3("Fantasy", "Unicorn-Powered", -50, "Magic");
    car3.start();
    std::cout << "--------------------" << std::endl;

    return 0;
}