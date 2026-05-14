#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // For std::invalid_argument
#include <sstream>   // For building string output

// Design an Engine class with a string type and int horsepower.
class Engine {
private:
    std::string type_;      // Member variable names follow common convention (trailing underscore)
    int horsepower_;

public:
    // Constructor: Uses const reference for string to avoid unnecessary copies.
    // Uses initializer list for efficient member initialization.
    // Includes basic input validation for horsepower.
    Engine(const std::string& type, int horsepower)
        : type_(type) {
        if (horsepower < 0) {
            throw std::invalid_argument("Engine horsepower cannot be negative.");
        }
        horsepower_ = horsepower;
    }

    // Getters: Marked const as they do not modify the object's state.
    // Returns const reference for string to avoid copy.
    const std::string& getType() const {
        return type_;
    }

    int getHorsepower() const {
        return horsepower_;
    }

    // Method to get engine information as a formatted string.
    std::string getInfo() const {
        std::stringstream ss;
        ss << "Engine Type: " << type_ << ", Horsepower: " << horsepower_;
        return ss.str();
    }
};

// Create a Car class that uses an Engine object as a private member, demonstrating composition.
class Car {
private:
    std::string make_; // Member variable names follow common convention
    Engine engine_;    // Composition: Car contains an Engine object

public:
    // Constructor for Car: Uses const references for strings for efficiency.
    // Uses initializer list for all members, including the composed Engine object.
    Car(const std::string& make, const std::string& engine_type, int engine_hp)
        : make_(make), engine_(engine_type, engine_hp) { // Engine is constructed directly in initializer list
    }

    // Method to display car and engine information. Marked const.
    void displayCarInfo() const {
        std::cout << "Car Make: " << make_ << std::endl;
        std::cout << "  " << engine_.getInfo() << std::endl;
    }
};

int main() {
    // Test case 1: Standard valid input
    Car car1("Tesla", "Electric", 500);
    car1.displayCarInfo();

    // Test case 2: Another standard valid input
    Car car2("Porsche", "Flat-6", 450);
    car2.displayCarInfo();

    // Test case 3: Demonstrate robustness with invalid input (negative horsepower)
    // This part will cause an exception, showing correct error handling.
    try {
        Car car3("BrokenCar", "V4", -100);
        car3.displayCarInfo();
    } catch (const std::invalid_argument& e) {
        std::cout << "Error creating car3: " << e.what() << std::endl;
    }

    return 0;
}