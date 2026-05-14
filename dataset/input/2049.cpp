#include <iostream>
#include <string>
#include <vector> // Included for completeness, though not strictly used in this example.

// Base class Vehicle
class Vehicle {
protected:
    int speed;
    std::string color;

public:
    // Constructor using initializer list and const reference for string
    Vehicle(int s, const std::string& c) : speed(s), color(c) {}

    // Virtual destructor for proper polymorphic cleanup
    virtual ~Vehicle() = default;

    // Setters with validation
    void setSpeed(int s) {
        if (s >= 0) { // Basic validation
            speed = s;
        } else {
            std::cerr << "Warning: Speed cannot be negative. Setting to 0." << std::endl;
            speed = 0;
        }
    }

    void setColor(const std::string& c) {
        color = c;
    }

    // Getters with const correctness
    int getSpeed() const {
        return speed;
    }

    const std::string& getColor() const {
        return color;
    }

    // Virtual function for polymorphic display
    virtual void displayInfo() const {
        std::cout << "Vehicle Info: Speed = " << speed << " mph, Color = " << color << std::endl;
    }
};

// Derived class Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    // Constructor using initializer list and chaining base constructor
    Car(int s, const std::string& c, int nd) : Vehicle(s, c), numDoors(nd) {
        // Additional validation for numDoors
        if (numDoors < 1) {
            std::cerr << "Warning: Car must have at least 1 door. Setting to 2." << std::endl;
            numDoors = 2;
        }
    }

    // Setter with validation
    void setNumDoors(int nd) {
        if (nd >= 1) { // Basic validation
            numDoors = nd;
        } else {
            std::cerr << "Warning: Number of doors cannot be less than 1. Keeping current value." << std::endl;
        }
    }

    // Getter with const correctness
    int getNumDoors() const {
        return numDoors;
    }

    // Specific method for Car
    void activateWipers() const {
        std::cout << "Car specific method: Wipers swishing! (This car has " << numDoors << " doors)." << std::endl;
    }

    // Override displayInfo for Car-specific details
    void displayInfo() const override {
        Vehicle::displayInfo(); // Call base method
        std::cout << "Car Specifics: Number of Doors = " << numDoors << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    // Constructor using initializer list and chaining base constructor
    Motorcycle(int s, const std::string& c, bool hs) : Vehicle(s, c), hasSidecar(hs) {}

    // Setter
    void setHasSidecar(bool hs) {
        hasSidecar = hs;
    }

    // Getter with const correctness
    bool getHasSidecar() const {
        return hasSidecar;
    }

    // Specific method for Motorcycle
    void revEngine() const {
        std::cout << "Motorcycle specific method: Vroom vroom! "
                  << (hasSidecar ? "with a sidecar!" : "on its own!") << std::endl;
    }

    // Override displayInfo for Motorcycle-specific details
    void displayInfo() const override {
        Vehicle::displayInfo(); // Call base method
        std::cout << "Motorcycle Specifics: Has Sidecar = " << (hasSidecar ? "Yes" : "No") << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Car ---" << std::endl;
    Car myCar(150, "Blue", 4);
    myCar.displayInfo(); // Polymorphic call
    myCar.activateWipers();
    myCar.setSpeed(160);
    myCar.setNumDoors(2);
    std::cout << "Updated Car Info:" << std::endl;
    myCar.displayInfo();

    std::cout << "\n--- Demonstrating Motorcycle ---" << std::endl;
    Motorcycle myMotorcycle(100, "Black", true);
    myMotorcycle.displayInfo(); // Polymorphic call
    myMotorcycle.revEngine();
    myMotorcycle.setSpeed(110);
    myMotorcycle.setHasSidecar(false);
    std::cout << "Updated Motorcycle Info:" << std::endl;
    myMotorcycle.displayInfo();

    std::cout << "\n--- Demonstrating Polymorphism and Robustness ---" << std::endl;
    // Using base class pointers for polymorphic behavior and correct cleanup
    std::vector<Vehicle*> vehicles;
    vehicles.push_back(new Car(80, "Silver", 5));
    vehicles.push_back(new Motorcycle(70, "Yellow", false));

    for (const auto& v : vehicles) {
        v->displayInfo(); // Calls appropriate derived displayInfo
        // Attempting invalid input
        v->setSpeed(-20); // Handled by validation
        std::cout << std::endl;
    }

    // Clean up dynamically allocated objects
    for (Vehicle* v : vehicles) {
        delete v;
    }
    vehicles.clear();

    // Test constructor validation
    std::cout << "\n--- Testing Constructor Validation ---" << std::endl;
    Car invalidCar(100, "White", 0); // Should trigger warning and set to default doors
    invalidCar.displayInfo();
    invalidCar.setNumDoors(-1); // Should trigger warning and keep current doors
    invalidCar.displayInfo();

    return 0;
}