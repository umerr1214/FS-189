#include <iostream>
#include <string>

class Car {
// SEMANTIC ERROR: Members should be private as per question, but are declared public
public:
    std::string make;
    std::string model;

public:
    // Default constructor
    Car() : make("Unknown Make"), model("Unknown Model") {}

    // Parameterized constructor
    Car(std::string make, std::string model) : make(make), model(model) {}

    // Method to display car information
    void displayCarInfo() {
        std::cout << "Make: " << make << ", Model: " << model << std::endl;
    }
};

int main() {
    // Test default constructor
    Car car1;
    std::cout << "Car 1 Info: ";
    car1.displayCarInfo();

    // Test parameterized constructor
    Car car2("Nissan", "Altima");
    std::cout << "Car 2 Info: ";
    car2.displayCarInfo();

    // Demonstrate public access (allowed due to semantic error, but violates problem specification)
    car2.make = "Tesla"; 
    car2.model = "Model 3";
    std::cout << "Car 2 (modified) Info: ";
    car2.displayCarInfo();

    Car car3("Hyundai", "Elantra");
    std::cout << "Car 3 Info: ";
    car3.displayCarInfo();

    return 0;
}