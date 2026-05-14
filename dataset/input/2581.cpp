#include <iostream>
#include <string>

// Engine class
class Engine {
public:
    int horsepower;
    std::string fuelType;

    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft) {
        std::cout << "Engine created: " << horsepower << "hp, " << fuelType << std::endl;
    }

    ~Engine() {
        std::cout << "Engine destroyed: " << horsepower << "hp, " << fuelType << std::endl;
    }

    int getHorsepower() const { return horsepower; }
    const std::string& getFuelType() const { return fuelType; }
};

// Car class demonstrating composition with a raw pointer, leading to a robustness issue
class Car {
public:
    Engine* engine; // Using a raw pointer for Engine composition

    Car(int hp, const std::string& ft) {
        engine = new Engine(hp, ft); // Dynamically allocate engine
        std::cout << "Car created." << std::endl;
    }

    // PROBLEM: The default copy constructor will perform a shallow copy,
    // copying the 'engine' pointer. This leads to two Car objects pointing
    // to the same Engine object.

    ~Car() {
        // PROBLEM: When the first Car object (or its copy) is destroyed,
        // it deletes the engine. When the second Car object is destroyed,
        // it attempts to delete the same engine pointer again, resulting
        // in a double-free error and undefined behavior.
        delete engine;
        std::cout << "Car destroyed." << std::endl;
    }

    int getEngineHorsepower() const {
        if (engine) return engine->getHorsepower();
        return 0; // Basic check, but doesn't prevent double deletion
    }

    const std::string& getEngineFuelType() const {
        if (engine) return engine->getFuelType();
        static const std::string empty = "N/A";
        return empty;
    }

    void displayCarDetails() const {
        std::cout << "Car Details: Engine - " << getEngineHorsepower() << "hp, "
                  << getEngineFuelType() << std::endl;
    }
};

int main() {
    std::cout << "--- Creating Car1 ---" << std::endl;
    Car car1(300, "Petrol");
    car1.displayCarDetails();

    std::cout << "\n--- Creating Car2 by copying Car1 (robustness issue expected) ---" << std::endl;
    // This line triggers the robustness issue due to shallow copy
    Car car2 = car1;
    car2.displayCarDetails();

    std::cout << "\n--- Car objects going out of scope ---" << std::endl;
    // The program is expected to crash or exhibit undefined behavior here due to double deletion.
    return 0;
}