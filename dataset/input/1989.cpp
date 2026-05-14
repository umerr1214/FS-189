#include <iostream>
#include <string>

// Engine class
class Engine {
public:
    // Constructor using initializer list and const reference for string to avoid unnecessary copies
    Engine(int horsepower, const std::string& fuelType)
        : horsepower(horsepower), fuelType(fuelType) {}

    // Getter for horsepower
    int getHorsepower() const {
        return horsepower;
    }

    // Getter for fuelType, returning const reference to avoid copies and prevent external modification
    const std::string& getFuelType() const {
        return fuelType;
    }

    // Method to display engine information
    void displayEngineInfo() const {
        std::cout << "  Engine Horsepower: " << horsepower << " HP" << std::endl;
        std::cout << "  Engine Fuel Type: " << fuelType << std::endl;
    }

private:
    int horsepower;
    std::string fuelType;
};

// Car class demonstrating composition by containing an Engine object
class Car {
public:
    // Constructor for Car, directly initializes its Engine member and other members
    // Uses const references for string parameters for efficiency and avoids unnecessary copies
    Car(const std::string& make, const std::string& model, int year, int engineHp, const std::string& engineFt)
        : make(make), model(model), year(year), carEngine(engineHp, engineFt) {} // Initializer list for all members, including Engine

    // Method to display car and engine information
    void displayCarInfo() const {
        std::cout << "Car Make: " << make << std::endl;
        std::cout << "Car Model: " << model << std::endl;
        std::cout << "Car Year: " << year << std::endl;
        carEngine.displayEngineInfo(); // Delegate to Engine's display method
    }

private:
    std::string make;
    std::string model;
    int year;
    Engine carEngine; // Composition: Car contains an Engine object
};

int main() {
    // Create Car objects, demonstrating composition with proper class design
    Car myCar("Toyota", "Camry", 2023, 203, "Gasoline");
    std::cout << "--- My Car Info ---" << std::endl;
    myCar.displayCarInfo();
    std::cout << std::endl;

    Car electricCar("Tesla", "Model S", 2024, 670, "Electric");
    std::cout << "--- Electric Car Info ---" << std::endl;
    electricCar.displayCarInfo();
    std::cout << std::endl;

    Car sportsCar("Porsche", "911 GT3", 2022, 502, "Premium Gasoline");
    std::cout << "--- Sports Car Info ---" << std::endl;
    sportsCar.displayCarInfo();
    std::cout << std::endl;

    return 0;
}