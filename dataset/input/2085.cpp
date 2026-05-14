#include <iostream>
#include <string>
#include <utility> // Required for std::move

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    // Default constructor - initializes all members using initializer list
    Car() : make("Unknown"), model("Unknown"), year(0) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Parameterized constructor - takes strings by value and uses std::move for efficiency,
    // and uses member initializer list for direct initialization.
    Car(std::string p_make, std::string p_model, int p_year)
        : make(std::move(p_make)), model(std::move(p_model)), year(p_year) {
        std::cout << "Parameterized constructor called." << std::endl;
    }

    // Copy constructor - uses member initializer list for direct initialization
    Car(const Car& other)
        : make(other.make), model(other.model), year(other.year) {
        std::cout << "Copy constructor called." << std::endl;
    }

    // Display method to show car details
    void display() const {
        std::cout << "Car Details: Make: " << make << ", Model: " << model << ", Year: " << year << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Constructors (Correct Version) ---" << std::endl;

    // 1. Default Constructor
    Car car1;
    car1.display();

    std::cout << std::endl;

    // 2. Parameterized Constructor
    Car car2("Tesla", "Model 3", 2023);
    car2.display();

    std::cout << std::endl;

    // 3. Copy Constructor
    Car car3 = car2; // Calls copy constructor
    car3.display();

    std::cout << std::endl;

    return 0;
}