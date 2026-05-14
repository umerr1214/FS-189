#include <iostream>
#include <string>
// No <utility> needed for this error type, highlighting the issue where it could be beneficial.

class Car {
private:
    std::string make;
    std::string model;
    int year; // This will be uninitialized in the default constructor

public:
    // Default constructor - Robustness Issue: 'year' is not initialized
    Car() {
        std::cout << "Default constructor called." << std::endl;
        make = "Unknown";
        model = "Unknown";
        // year is left uninitialized, leading to undefined behavior if accessed before assignment
        // A robust implementation would initialize it, e.g., year = 0;
    }

    // Parameterized constructor - uses member initializer list for strings, good practice
    Car(std::string make_param, std::string model_param, int year_param)
        : make(std::move(make_param)), model(std::move(model_param)), year(year_param) {
        std::cout << "Parameterized constructor called." << std::endl;
    }

    // Copy constructor - uses member initializer list, good practice
    Car(const Car& other)
        : make(other.make), model(other.model), year(other.year) {
        std::cout << "Copy constructor called." << std::endl;
    }

    void display() const {
        std::cout << "Car Details: Make: " << make << ", Model: " << model << ", Year: " << year << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Constructors ---" << std::endl;

    // 1. Default Constructor
    Car car1;
    // Accessing uninitialized 'year' here could lead to undefined behavior.
    // On many systems, for an int member, it might print 0 or some garbage value.
    car1.display();

    std::cout << std::endl;

    // 2. Parameterized Constructor
    Car car2("Toyota", "Camry", 2020);
    car2.display();

    std::cout << std::endl;

    // 3. Copy Constructor
    Car car3 = car2; // Calls copy constructor
    car3.display();

    std::cout << std::endl;

    return 0;
}