#include <iostream>
#include <string>

class Car {
private:
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
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    // Test default constructor
    Car car1;
    std::cout << "Car 1 Info: ";
    car1.displayCarInfo();

    // Test parameterized constructor
    Car car2("Toyota", "Camry");
    std::cout << "Car 2 Info: ";
    car2.displayCarInfo();

    Car car3("Ford", "Mustang");
    std::cout << "Car 3 Info: ";
    car3.displayCarInfo();

    return 0;
}