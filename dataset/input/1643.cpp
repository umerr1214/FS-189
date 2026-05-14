#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;

public:
    // Default constructor
    Car() : make("Unknown Make"), model("Unknown Model") {}

    // Parameterized constructor - LOGICAL ERROR HERE
    Car(std::string newMake, std::string newModel) {
        this->make = newModel; // Incorrect: Assigns newModel to make
        this->model = newMake; // Incorrect: Assigns newMake to model
    }

    // Method to display car information
    void displayCarInfo() {
        std::cout << "Make: " << make << ", Model: " << model << std::endl;
    }
};

int main() {
    // Test default constructor
    Car car1;
    std::cout << "Car 1 Info: ";
    car1.displayCarInfo(); // Expected: Unknown Make, Unknown Model

    // Test parameterized constructor
    Car car2("Toyota", "Camry");
    std::cout << "Car 2 Info: ";
    car2.displayCarInfo(); // Expected: Toyota, Camry. Actual (due to error): Camry, Toyota

    Car car3("Ford", "Mustang");
    std::cout << "Car 3 Info: ";
    car3.displayCarInfo(); // Expected: Ford, Mustang. Actual (due to error): Mustang, Ford

    return 0;
}