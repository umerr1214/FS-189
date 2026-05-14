#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr

class Vehicle {
protected:
    std::string brand;
    int year;
public:
    Vehicle(std::string brand, int year) : brand(brand), year(year) {}
    virtual ~Vehicle() {
        // Virtual destructor ensures proper cleanup of derived objects when deleted via base pointer.
        // For this example, no specific resources to free in Vehicle itself.
    }

    virtual void displayInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(std::string brand, int year, int numDoors) : Vehicle(brand, year), numDoors(numDoors) {}
    // No explicit destructor needed here, base destructor is virtual.
    
    void displayInfo() const override { // Using 'override' keyword for clarity and compile-time checks
        std::cout << "Brand: " << brand << ", Year: " << year << ", Doors: " << numDoors << std::endl;
    }
};

int main() {
    // Correct Version: Demonstrates polymorphism using modern C++ practices.
    // - Uses std::vector to manage a collection of pointers.
    // - Uses std::unique_ptr for automatic memory management, preventing leaks.
    // - Employs range-based for loop for clear iteration.
    // - `override` keyword used for clarity.

    std::vector<std::unique_ptr<Vehicle>> vehicles; // Vector of unique pointers to Vehicle objects

    // Add Vehicle and Car objects using std::make_unique
    vehicles.push_back(std::make_unique<Vehicle>("Truck", 2020));
    vehicles.push_back(std::make_unique<Car>("Sedan", 2022, 4));
    vehicles.push_back(std::make_unique<Vehicle>("Motorcycle", 2019));

    std::cout << "Demonstrating polymorphism with modern C++:" << std::endl;
    // Iterate through the vector and call displayInfo() using polymorphism
    for (const auto& vehicle_ptr : vehicles) {
        vehicle_ptr->displayInfo(); // Calls the correct displayInfo based on actual object type
    }

    // Memory is automatically managed by std::unique_ptr when 'vehicles' goes out of scope.
    // No manual delete calls are necessary.

    return 0;
}