#include <iostream>
#include <string> // Required for std::string concatenation

class Vehicle {
public:
    void startEngine() {
        // Inefficient string construction and use of std::endl
        std::string first_part_of_message = "Vehicle engine ";
        std::string second_part_of_message = "started.";
        std::cout << first_part_of_message + second_part_of_message << std::endl; // std::endl flushes, potentially inefficient
    }
};

class Car : public Vehicle {
public:
    void startEngine() { // Hides Vehicle::startEngine
        // Inefficient string construction and use of std::endl
        std::string car_message_beginning = "Car engine ";
        std::string car_message_ending = "started with a roar!";
        std::cout << car_message_beginning + car_message_ending << std::endl; // std::endl flushes, potentially inefficient
    }
};

int main() {
    // Demonstrate Vehicle object
    Vehicle aVehicleObjectInstance; // Overly verbose variable name
    aVehicleObjectInstance.startEngine();

    // Demonstrate Car object
    Car aCarObjectInstance; // Overly verbose variable name
    aCarObjectInstance.startEngine();

    // Demonstrate method hiding using a base pointer to a derived object
    Vehicle* pointerToDerivedCarObject = &aCarObjectInstance; // Overly verbose variable name
    pointerToDerivedCarObject->startEngine(); // Calls Vehicle::startEngine due to method hiding

    // Demonstrate method hiding using a base reference to a derived object
    Vehicle& referenceToDerivedCarObject = aCarObjectInstance; // Overly verbose variable name
    referenceToDerivedCarObject.startEngine(); // Calls Vehicle::startEngine due to method hiding

    return 0;
}