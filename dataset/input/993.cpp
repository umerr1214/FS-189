#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Vehicle {
protected:
    std::string brand;
    int year;
public:
    Vehicle(std::string brand, int year) : brand(brand), year(year) {}
    // Semantic Error: 'virtual' keyword is missing.
    // This means `displayInfo` is not a virtual function, preventing runtime polymorphism.
    void displayInfo() const { // Not virtual
        std::cout << "Brand: " << brand << ", Year: " << year;
    }
    virtual ~Vehicle() {} // Destructor should still be virtual for proper cleanup
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(std::string brand, int year, int numDoors) : Vehicle(brand, year), numDoors(numDoors) {}
    // Because Vehicle::displayInfo is not virtual, this is a new function, not an override.
    // Removing 'override' keyword to make it compile, demonstrating the semantic issue.
    void displayInfo() const {
        Vehicle::displayInfo(); // This call is fine, but the polymorphic call will bypass this.
        std::cout << ", Doors: " << numDoors;
    }
};

class Motorcycle : public Vehicle {
private:
    bool hasSidecar;
public:
    Motorcycle(std::string brand, int year, bool hasSidecar) : Vehicle(brand, year), hasSidecar(hasSidecar) {}
    // Because Vehicle::displayInfo is not virtual, this is a new function, not an override.
    // Removing 'override' keyword to make it compile, demonstrating the semantic issue.
    void displayInfo() const {
        Vehicle::displayInfo(); // This call is fine, but the polymorphic call will bypass this.
        std::cout << ", Sidecar: " << (hasSidecar ? "Yes" : "No");
    }
};

int main() {
    // Redirect cout to a stringstream to capture output
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    Vehicle* v1 = new Car("Toyota", 2020, 4);
    Vehicle* v2 = new Motorcycle("Harley-Davidson", 2022, false);
    Vehicle* v3 = new Car("Honda", 2018, 2);

    // Due to the missing 'virtual' keyword in the base class,
    // these calls will perform static dispatch, calling Vehicle::displayInfo()
    // instead of the derived class's displayInfo().
    v1->displayInfo();
    std::cout << std::endl;
    v2->displayInfo();
    std::cout << std::endl;
    v3->displayInfo();
    std::cout << std::endl;

    delete v1;
    delete v2;
    delete v3;

    // Restore cout
    std::cout.rdbuf(oldCout);
    std::cout << ss.str(); // Print captured output to actual stdout

    return 0;
}