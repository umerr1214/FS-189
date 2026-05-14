#include <iostream>
#include <string>

class Car {
public:
    std::string make;
    std::string model;
    int year;

    // Default constructor
    Car() : make("Unknown"), model("Unknown"), year(2000) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Parameterized constructor (Logical Error: 'year' is incorrectly initialized to a fixed value)
    Car(std::string m, std::string mod, int y) : make(m), model(mod), year(1900) { // Should be year(y)
        std::cout << "Parameterized constructor called for " << make << " " << model << "." << std::endl;
    }

    // Copy constructor
    Car(const Car& other) : make(other.make), model(other.model), year(other.year) {
        std::cout << "Copy constructor called for " << other.make << " " << other.model << "." << std::endl;
    }

    void display() const {
        std::cout << "Car: " << make << " " << model << " (" << year << ")" << std::endl;
    }
};

int main() {
    // Demonstrate default constructor
    Car car1;
    car1.display();

    // Demonstrate parameterized constructor
    Car car2("Toyota", "Camry", 2020); // Expected year 2020, but due to error, will be 1900
    car2.display();

    // Demonstrate copy constructor
    Car car3 = car2;
    car3.display();

    return 0;
}