#include <iostream>
#include <string>
#include <utility> // Included, but std::move not used effectively

// Vehicle class definition for Readability/Efficiency Issue
class Vehicle {
public:
    std::string brand; // Public member
protected:
    std::string model; // Protected member
private:
    int year; // Private member

public:
    // Constructor with verbose parameter names, redundant 'this->', and excessive std::endl
    Vehicle(std::string b_param, std::string m_param, int y_param) {
        this->brand = b_param; // Redundant 'this->'
        this->model = m_param;
        this->year = y_param;
        std::cout << "Vehicle object created with brand: " << this->brand << std::endl; // Excessive std::endl
    }

    // Getter for year, not const-correct, uses redundant 'this->'
    int getYear() { // Should be 'const'
        return this->year; // Redundant 'this->'
    }

    // Setter for year, passes int by value (minor issue, but for string it would be an efficiency issue), uses 'this->', excessive std::endl
    void setYear(int y_val) {
        this->year = y_val;
        std::cout << "Year has been set to: " << this->year << std::endl; // Excessive std::endl
    }

    // Redundant print method for brand with excessive std::endl
    void printMyBrand() {
        std::cout << "Current vehicle brand is: " << this->brand << std::endl; // Excessive std::endl
    }
};

// Car class derived from Vehicle for Readability/Efficiency Issue
class Car : public Vehicle {
public:
    // Constructor, verbose naming, excessive std::endl in base call output
    Car(std::string b_arg, std::string m_arg, int y_arg) : Vehicle(b_arg, m_arg, y_arg) {
        std::cout << "Car object created, derived from Vehicle." << std::endl; // Excessive std::endl
    }

    // Method to access/modify protected model, passes string by value (efficiency issue), uses 'this->', excessive std::endl
    void changeCarModel(std::string new_model_name) { // Should ideally be 'const std::string& new_model_name' or 'std::string new_model_name' with std::move
        this->model = new_model_name; // Redundant 'this->'
        std::cout << "Car model successfully changed to: " << this->model << std::endl; // Excessive std::endl
    }

    // Redundant print method for model with excessive std::endl
    void printCarModel() {
        std::cout << "The car's model is: " << this->model << std::endl; // Excessive std::endl
    }

    // Comprehensive display method with excessive std::endl and verbose output, not const-correct
    void displayEveryDetail() { // Should be 'const'
        std::cout << "--- START OF ALL CAR INFORMATION ---" << std::endl;
        std::cout << "  Vehicle Brand Field: " << this->brand << std::endl; // Direct access to public
        std::cout << "  Vehicle Model Field: " << this->model << std::endl; // Access to protected
        std::cout << "  Vehicle Year Field: " << this->getYear() << std::endl; // Access via getter (which is not const)
        std::cout << "--- END OF ALL CAR INFORMATION ---" << std::endl;
    }
};

int main() {
    Car my_first_car("Nissan", "Altima", 2018); // Verbose constructor output
    std::cout << "\n--- Initial State Demonstration ---" << std::endl;
    my_first_car.displayEveryDetail(); // Verbose display output

    // Demonstrate direct access to public brand
    my_first_car.brand = "Infiniti";
    std::cout << "\n--- After directly changing brand ---" << std::endl;
    my_first_car.printMyBrand(); // Verbose print

    // Demonstrate modifying protected model via derived class method
    my_first_car.changeCarModel("Q50"); // Verbose setter output
    std::cout << "\n--- After modifying model via derived class method ---" << std::endl;
    my_first_car.printCarModel(); // Verbose print

    // Demonstrate modifying private year via public setter
    my_first_car.setYear(2021); // Verbose setter output
    std::cout << "\n--- After modifying year via setter method ---" << std::endl;
    std::cout << "Retrieved Year Value: " << my_first_car.getYear() << std::endl; // Getter not const

    std::cout << "\n--- Final State Demonstration ---" << std::endl;
    my_first_car.displayEveryDetail(); // Verbose display output

    return 0;
}