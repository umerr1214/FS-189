#include <iostream>
#include <string>
#include <utility> // For std::move

// Base class Vehicle
class Vehicle {
private:
    std::string brand;
    int year;

public:
    // Readability/Efficiency Issue: Not using initializer list
    Vehicle(std::string brand_param, int year_param) {
        brand = std::move(brand_param); // Default construction then assignment
        year = year_param;
    }

    // Virtual destructor for proper cleanup in polymorphic scenarios
    virtual ~Vehicle() = default;

    // Public getters (good practice, not an issue here)
    std::string getBrand() const { return brand; }
    int getYear() const { return year; }

    // Readability/Efficiency Issue: Using std::endl instead of '\n'
    virtual void displayInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year << "." << std::endl;
    }
};

// Derived class Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    // Readability/Efficiency Issue: Not using initializer list for base or own member
    Car(std::string brand_param, int year_param, int numDoors_param)
        : Vehicle(std::move(brand_param), year_param) // Base constructor is called
    {
        numDoors = numDoors_param; // Member assigned in body
    }

    // Readability/Efficiency Issue: Using std::endl instead of '\n'
    void displayInfo() const override {
        std::cout << "Brand: " << getBrand() << ", Year: " << getYear() << ", Doors: " << numDoors << "." << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    // Readability/Efficiency Issue: Not using initializer list for base or own member
    Motorcycle(std::string brand_param, int year_param, bool hasSidecar_param)
        : Vehicle(std::move(brand_param), year_param) // Base constructor is called
    {
        hasSidecar = hasSidecar_param; // Member assigned in body
    }

    // Readability/Efficiency Issue: Using std::endl instead of '\n'
    void displayInfo() const override {
        std::cout << "Brand: " << getBrand() << ", Year: " << getYear() << ", Has Sidecar: " << (hasSidecar ? "Yes" : "No") << "." << std::endl;
    }
};

int main() {
    Car myCar("Toyota", 2020, 4);
    Motorcycle myMotorcycle("Harley-Davidson", 2023, true);

    myCar.displayInfo();
    myMotorcycle.displayInfo();

    Vehicle* v_car = new Car("Honda", 2018, 2);
    Vehicle* v_motorcycle = new Motorcycle("BMW", 2022, false);

    v_car->displayInfo();
    v_motorcycle->displayInfo();

    delete v_car;
    delete v_motorcycle;

    return 0;
}