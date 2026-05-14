#include <iostream>
#include <string>
#include <utility> // Not strictly needed for robustness, but good practice to include if std::move might be used

// Vehicle class definition for Robustness Issue
class Vehicle {
public:
    std::string brand; // Public member
protected:
    std::string model; // Protected member
private:
    int year; // Private member

public:
    // Constructor
    Vehicle(std::string b, std::string m, int y) : brand(b), model(m), year(y) {}

    // Public getter for year (const correct)
    int getYear() const { return year; }

    // Public setter for year - Robustness Issue: No validation for year
    void setYear(int y) {
        year = y; // Allows any integer, e.g., negative or zero, without checking
    }

    // Helper to display brand
    void displayVehicleBrand() const {
        std::cout << "Brand: " << brand << std::endl;
    }
};

// Car class derived from Vehicle
class Car : public Vehicle {
public:
    // Constructor calling base class constructor
    Car(std::string b, std::string m, int y) : Vehicle(b, m, y) {}

    // Method to access and modify protected member 'model'
    // Robustness Issue: No validation for model string
    void setModel(std::string m) {
        model = m; // Allows empty string or other invalid values without checking
    }

    // Method to display model (accessing protected member)
    void displayModel() const {
        std::cout << "Model: " << model << std::endl;
    }

    // Comprehensive display method for Car (accessing all members)
    void displayFullCarDetails() const {
        std::cout << "Vehicle Details:" << std::endl;
        std::cout << "  Brand: " << brand << std::endl; // Direct access to public
        std::cout << "  Model: " << model << std::endl; // Access to protected
        std::cout << "  Year: " << getYear() << std::endl; // Access via public getter
    }
};

int main() {
    Car myCar("Toyota", "Camry", 2020);
    std::cout << "--- Initial State ---" << std::endl;
    myCar.displayFullCarDetails();

    // 1. Demonstrate direct access to public brand
    myCar.brand = "Honda";
    std::cout << "\n--- After modifying brand directly ---" << std::endl;
    myCar.displayVehicleBrand();

    // 2. Demonstrate modifying protected model via derived class method (with valid input)
    myCar.setModel("Civic");
    std::cout << "\n--- After modifying model via derived class ---" << std::endl;
    myCar.displayModel();

    // 3. Demonstrate modifying private year via public setter (with valid input)
    myCar.setYear(2023);
    std::cout << "\n--- After modifying year via setter ---" << std::endl;
    std::cout << "New Year (via getter): " << myCar.getYear() << std::endl;

    std::cout << "\n--- Final State (valid data) ---" << std::endl;
    myCar.displayFullCarDetails();

    // --- Demonstrating Robustness Issues with Invalid Data ---
    std::cout << "\n--- Demonstrating Robustness Issues with Invalid Data ---" << std::endl;

    // Robustness Issue 1: Setting an invalid year without validation
    myCar.setYear(-100);
    std::cout << "Attempted to set year to -100." << std::endl;
    std::cout << "Current Year (via getter): " << myCar.getYear() << std::endl;

    // Robustness Issue 2: Setting an empty model without validation
    myCar.setModel("");
    std::cout << "Attempted to set model to empty string." << std::endl;
    myCar.displayModel(); // This will print "Model: "

    // Robustness Issue 3: Setting an empty brand directly (no validation on public member)
    myCar.brand = "";
    std::cout << "Attempted to set brand to empty string." << std::endl;
    myCar.displayVehicleBrand(); // This will print "Brand: "

    std::cout << "\n--- State after Robustness Issues ---" << std::endl;
    myCar.displayFullCarDetails();

    return 0;
}