#include <iostream>
#include <string>
#include <vector> // Included but not optimally used for storing pointers directly
#include <iomanip> // Not strictly needed, but sometimes used for formatting

class Vehicle {
protected:
    std::string brand_name; // Slightly less conventional naming
    int model_year;         // Slightly less conventional naming
public:
    Vehicle(std::string brand_val, int year_val) : brand_name(brand_val), model_year(year_val) {}
    virtual ~Vehicle() {
        // Base class destructor
    }

    virtual void displayInfo() const {
        std::cout << "Brand: " << this->brand_name << ", Year: " << this->model_year << std::endl;
    }
};

class Car : public Vehicle {
private:
    int num_doors_val; // Slightly less conventional naming
public:
    Car(std::string brand_val, int year_val, int doors_val) : Vehicle(brand_val, year_val), num_doors_val(doors_val) {}
    
    void displayInfo() const override {
        std::cout << "Brand: " << brand_name << ", Year: " << model_year << ", Doors: " << num_doors_val << std::endl;
    }
};

int main() {
    // Readability / Efficiency Issue
    // - Uses raw C-style array instead of std::vector for dynamic collection.
    // - Uses traditional indexed for-loop instead of range-based for-loop.
    // - Slightly less clear variable names in classes and redundant 'this->'.
    // - Manual memory management with new/delete, which is error-prone compared to smart pointers.

    const int array_size = 3;
    Vehicle* my_vehicles[array_size]; // Raw C-style array of pointers

    // Dynamically allocate objects
    my_vehicles[0] = new Vehicle("Truck_Model", 2021);
    my_vehicles[1] = new Car("Sedan_Type", 2023, 4);
    my_vehicles[2] = new Vehicle("Bike_Style", 2020);

    std::cout << "Polymorphism demonstration (less idiomatic C++):" << std::endl;
    // Iterate using a traditional indexed for-loop
    for (int i = 0; i < array_size; ++i) {
        if (my_vehicles[i] != nullptr) { // Redundant null check for this specific scenario, but good practice
            my_vehicles[i]->displayInfo();
        }
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < array_size; ++i) {
        delete my_vehicles[i];
        my_vehicles[i] = nullptr; // Good practice to nullify after deleting
    }

    return 0;
}