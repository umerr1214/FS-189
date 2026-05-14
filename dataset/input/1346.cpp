#include <iostream>
#include <string>
#include <sstream> // Required for test driver

class Vehicle {
protected:
    std::string make;
    std::string model;

public:
    // Readability/Efficiency Issue: Constructor takes string by value (unnecessary copy)
    Vehicle(std::string make_val, std::string model_val)
        : make(make_val), model(model_val) {} // Members are copied again here

    // Readability/Efficiency Issue: displayInfo is virtual but not const
    virtual void displayInfo() {
        std::cout << "Make: " << make << ", Model: " << model << std::endl; // Excessive use of std::endl
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    // Readability/Efficiency Issue: Constructor takes string by value (unnecessary copy)
    Car(std::string make_val, std::string model_val, int numDoors_val)
        : Vehicle(make_val, model_val), numDoors(numDoors_val) {} // Members are copied again here

    // Readability/Efficiency Issue: Duplicates base logic instead of calling base method
    // Also not const
    void displayInfo() override {
        // Duplicating logic instead of calling Vehicle::displayInfo()
        std::cout << "Make: " << make << ", Model: " << model << std::endl; // Excessive use of std::endl
        std::cout << "Doors: " << numDoors << std::endl; // Excessive use of std::endl
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

    myCar.displayInfo(); // This will call Car's displayInfo

    std::cout.rdbuf(oldCout);
    return ss.str();
}

int main() {
    // The test framework will call run_test_case
    std::cout << run_test_case("Honda Civic 4");
    return 0;
}