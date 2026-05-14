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

    // Correct: displayInfo is virtual and const
    virtual void displayInfo() const {
        std::cout << "Make: " << make << ", Model: " << model << '\n';
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    // Correct: Constructor takes const references and initializes base class
    Car(const std::string& make, const std::string& model, int numDoors)
        : Vehicle(make, model), numDoors(numDoors) {}

    // Correct: Overrides base method, calls base method, and is const
    void displayInfo() const override {
        Vehicle::displayInfo(); // Call base displayInfo
        std::cout << "Doors: " << numDoors << '\n';
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

    // Demonstrate correct polymorphic behavior
    Vehicle* vPtr = &myCar;
    vPtr->displayInfo(); // This will correctly call Car::displayInfo

    std::cout.rdbuf(oldCout);
    return ss.str();
}

int main() {
    // The test framework will call run_test_case
    std::cout << run_test_case("Mercedes-Benz C-Class 4");
    return 0;
}