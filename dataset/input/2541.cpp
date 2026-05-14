#include <iostream>
#include <string>
#include <utility> // Required for std::move

// Vehicle class definition for Correct Version
class Vehicle {
public:
    std::string brand; // Public member
protected:
    std::string model; // Protected member
private:
    int year; // Private member

public:
    // Constructor using initializer list and std::move for efficient string handling
    Vehicle(std::string brand_name, std::string model_name, int production_year)
        : brand(std::move(brand_name)), model(std::move(model_name)), year(production_year) {}

    // Public getter for year (const-correct)
    int getYear() const {
        return year;
    }

    // Public setter for year with basic validation
    void setYear(int new_year) {
        // Basic validation: year must be after the invention of the automobile and not in the future
        if (new_year >= 1886 && new_year <= 2024) {
            year = new_year;
        } else {
            std::cerr << "Warning: Invalid year (" << new_year << ") provided. Year not updated." << std::endl;
        }
    }

    // Display method for Vehicle information (const-correct)
    void displayVehicleBrandAndYear() const {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Year: " << year << std::endl;
    }
};

// Car class derived from Vehicle
class Car : public Vehicle {
public:
    // Constructor calling base class constructor using initializer list and std::move
    Car(std::string brand_name, std::string model_name, int production_year)
        : Vehicle(std::move(brand_name), std::move(model_name), production_year) {}

    // Method to access and modify protected member 'model' with validation and std::move
    void setCarModel(std::string new_model) {
        // Basic validation: model string should not be empty
        if (!new_model.empty()) {
            model = std::move(new_model); // Use std::move to avoid unnecessary copy
        } else {
            std::cerr << "Warning: Model cannot be empty. Model not updated." << std::endl;
        }
    }

    // Method to display model (accessing protected member) (const-correct)
    void displayCarModel() const {
        std::cout << "Model: " << model << std::endl;
    }

    // Comprehensive display method for Car (accessing all members) (const-correct)
    void displayFullCarDetails() const {
        std::cout << "--- Car Details ---" << std::endl;
        std::cout << "  Brand: " << brand << std::endl; // Direct access to public
        std::cout << "  Model: " << model << std::endl; // Access to protected
        std::cout << "  Year: " << getYear() << std::endl; // Access via public getter
        std::cout << "-------------------" << std::endl;
    }
};

int main() {
    Car myCar("Mercedes-Benz", "C-Class", 2022);
    std::cout << "--- Initial State ---" << std::endl;
    myCar.displayFullCarDetails();

    // 1. Demonstrate modifying public member 'brand' directly
    myCar.brand = "BMW";
    std::cout << "\n--- After modifying brand directly ---" << std::endl;
    myCar.displayVehicleBrandAndYear(); // Using a more specific display for Vehicle info

    // 2. Demonstrate modifying protected member 'model' through a derived class method
    myCar.setCarModel("3 Series");
    std::cout << "\n--- After modifying model via derived class ---" << std::endl;
    myCar.displayCarModel();

    // 3. Demonstrate modifying private member 'year' through a public getter/setter
    myCar.setYear(2024);
    std::cout << "\n--- After modifying year via setter ---" << std::endl;
    std::cout << "New Year (via getter): " << myCar.getYear() << std::endl;

    std::cout << "\n--- Final State (valid data) ---" << std::endl;
    myCar.displayFullCarDetails();

    // --- Demonstrate Input Validation ---
    std::cout << "\n--- Demonstrating Input Validation ---" << std::endl;

    // Attempt to set invalid year (outside defined range)
    myCar.setYear(1800); // Too old
    myCar.setYear(2030); // Future year
    std::cout << "Current Year after invalid attempts: " << myCar.getYear() << std::endl;

    // Attempt to set empty model
    myCar.setCarModel("");
    myCar.displayCarModel();

    std::cout << "\n--- State after Validation Attempts ---" << std::endl;
    myCar.displayFullCarDetails();

    return 0;
}