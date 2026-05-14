#include <iostream>
#include <string>

// Engine class
class Engine {
public:
    int horsepower;
    std::string fuelType;

    // A default constructor is implicitly or explicitly needed for the Car's constructor
    // if the Engine member is not initialized via an initializer list.
    Engine() : horsepower(0), fuelType("Unknown") {
        std::cout << "Engine default-constructed." << std::endl;
    }

    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft) {
        std::cout << "Engine created: " << horsepower << "hp, " << fuelType << std::endl;
    }

    ~Engine() {
        std::cout << "Engine destroyed: " << horsepower << "hp, " << fuelType << std::endl;
    }

    // Readability/Efficiency Issue: Lack of const-correctness on getters
    int getHorsepower() { return horsepower; }
    // Readability/Efficiency Issue: Returns by value, which involves an unnecessary copy
    std::string getFuelType() { return fuelType; }
};

// Car class demonstrating composition with readability/efficiency issues
class Car {
public:
    Engine engine; // Direct composition

    // Readability/Efficiency Issue: Car constructor initializes Engine using assignment,
    // not an initializer list. This causes 'engine' to be default-constructed first,
    // then assigned a new Engine object, which is less efficient.
    Car(int hp, const std::string& ft) {
        engine = Engine(hp, ft); // Default construct + assign (less efficient)
        std::cout << "Car created." << std::endl;
    }

    ~Car() {
        std::cout << "Car destroyed." << std::endl;
    }

    // Readability/Efficiency Issue: Lack of const-correctness on getters
    int getEngineHorsepower() { return engine.getHorsepower(); }
    std::string getEngineFuelType() { return engine.getFuelType(); } // Returns by value

    void displayCarDetails() {
        std::cout << "Car Details: Engine - " << getEngineHorsepower() << "hp, "
                  << getEngineFuelType() << std::endl;
    }
};

int main() {
    std::cout << "--- Creating Car1 ---" << std::endl;
    Car car1(250, "Diesel");
    car1.displayCarDetails();

    std::cout << "\n--- Creating Car2 ---" << std::endl;
    Car car2(400, "Electric");
    car2.displayCarDetails();

    std::cout << "\n--- Car objects going out of scope ---" << std::endl;
    return 0;
}