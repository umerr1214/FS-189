#include <iostream>
#include <string>
#include <sstream> // Required for test driver

class Vehicle {
protected:
    std::string make;
    std::string model;

public:
    Vehicle(const std::string& make, const std::string& model)
        : make(make), model(model) {}

    // Robustness Issue: displayInfo is NOT virtual
    void displayInfo() {
        std::cout << "Make: " << make << ", Model: " << model << std::endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(const std::string& make, const std::string& model, int numDoors)
        : Vehicle(make, model), numDoors(numDoors) {}

    // This method effectively hides Vehicle::displayInfo() when called directly on Car objects
    // but does not provide polymorphic behavior when called via a Vehicle*
    void displayInfo() {
        // Call base displayInfo
        Vehicle::displayInfo();
        std::cout << "Doors: " << numDoors << std::endl;
    }
};

// Driver code for test cases
std::string run_test_case(const std::string& input_str) {
    std::stringstream input_ss(input_str);
    std::string make, model;
    int numDoors;
    input_ss >> make >> model >> numDoors;

    Car myCar(make, model, numDoors);

    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    // Demonstrate the robustness issue:
    // 1. Direct call on Car object (calls Car::displayInfo)
    // 2. Polymorphic call via Vehicle pointer (calls Vehicle::displayInfo due to missing virtual)
    
    ss << "Car Info (direct call): ";
    myCar.displayInfo(); // This will call Car's displayInfo
    
    Vehicle* vPtr = &myCar;
    ss << "Vehicle* Info (polymorphic call): ";
    vPtr->displayInfo(); // This will incorrectly call Vehicle's displayInfo

    std::cout.rdbuf(oldCout);
    return ss.str();
}

int main() {
    // Example usage for manual testing
    // Car myCar("Tesla", "ModelS", 4);
    // myCar.displayInfo();
    // Vehicle* vPtr = &myCar;
    // vPtr->displayInfo();

    // The test framework will call run_test_case
    std::cout << run_test_case("Tesla ModelS 4");
    return 0;
}