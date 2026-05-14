#include <iostream>
#include <string>
#include <utility> // For std::move

// Engine class
class Engine {
public:
    int horsepower;
    std::string fuelType;

    // Constructor for Engine, taking fuelType by value and moving it for efficiency
    Engine(int hp, std::string ft)
        : horsepower(hp), fuelType(std::move(ft)) {
        std::cout << "Engine created: " << horsepower << "hp, " << fuelType << std::endl;
    }

    // Destructor to demonstrate automatic destruction
    ~Engine() {
        std::cout << "Engine destroyed: " << horsepower << "hp, " << fuelType << std::endl;
    }

    // Const-correctness for getters, returning by const reference for efficiency
    int getHorsepower() const { return horsepower; }
    const std::string& getFuelType() const { return fuelType; }
};

// Car class demonstrating proper composition
class Car {
public:
    Engine engine; // Direct composition: Engine object is a member of Car

    // Car constructor uses an initializer list to construct the Engine member directly.
    // This ensures Engine is created when Car is created, and avoids default construction + assignment.
    Car(int hp, const std::string& ft)
        : engine(hp, ft) { // Engine is constructed directly here with provided arguments
        std::cout << "Car created." << std::endl;
    }

    // The default destructor for Car is sufficient. When a Car object is destroyed,
    // its 'engine' member's destructor is automatically called.
    ~Car() {
        std::cout << "Car destroyed." << std::endl;
    }

    // Const-correctness for getters
    int getEngineHorsepower() const { return engine.getHorsepower(); }
    const std::string& getEngineFuelType() const { return engine.getFuelType(); }

    // A method to show car details
    void displayCarDetails() const {
        std::cout << "Car Details: Engine - " << getEngineHorsepower() << "hp, "
                  << getEngineFuelType() << std::endl;
    }
};

int main() {
    std::cout << "--- Creating Car1 ---" << std::endl;
    Car car1(200, "Gasoline");
    car1.displayCarDetails();

    std::cout << "\n--- Creating Car2 ---" << std::endl;
    Car car2(500, "Electric");
    car2.displayCarDetails();

    std::cout << "\n--- Car objects going out of scope ---" << std::endl;
    // Expected destruction order:
    // Car2's destructor is called, which in turn calls its 'engine' member's destructor.
    // Then Car1's destructor is called, which in turn calls its 'engine' member's destructor.
    return 0;
}