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
    virtual void displayInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year;
    }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(std::string brand, int year, int numDoors) : Vehicle(brand, year), numDoors(numDoors) {}
    void displayInfo() const override {
        // Logical Error: Forgetting to call Vehicle::displayInfo()
        // This means the general vehicle info (brand, year) will not be printed.
        std::cout << "Doors: " << numDoors;
    }
};

class Motorcycle : public Vehicle {
private:
    bool hasSidecar;
public:
    Motorcycle(std::string brand, int year, bool hasSidecar) : Vehicle(brand, year), hasSidecar(hasSidecar) {}
    void displayInfo() const override {
        // Logical Error: Forgetting to call Vehicle::displayInfo()
        // This means the general vehicle info (brand, year) will not be printed.
        std::cout << "Sidecar: " << (hasSidecar ? "Yes" : "No");
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