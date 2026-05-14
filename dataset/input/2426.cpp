#include <iostream>
#include <string>
#include <vector> // Included but not strictly necessary for this example, demonstrates potential inefficiency/redundancy.

// Base class Vehicle with verbose naming and inefficient string passing
class Vehicle {
protected:
    int m_vehicle_current_speed_in_kmph; // Overly verbose attribute name
    std::string m_vehicle_fuel_type_information; // Overly verbose attribute name

public:
    // Constructor - passes string by value, causing an unnecessary copy
    Vehicle(int initial_speed_value, std::string initial_fuel_type_string)
        : m_vehicle_current_speed_in_kmph(initial_speed_value),
          m_vehicle_fuel_type_information(initial_fuel_type_string) {
        // Redundant use of 'this->' in a constructor initializer list for clarity (bad practice)
        // this->m_vehicle_current_speed_in_kmph = initial_speed_value;
        // this->m_vehicle_fuel_type_information = initial_fuel_type_string;
    }

    // Display method with verbose name and redundant `this->`
    virtual void display_vehicle_information_details_function() const {
        std::cout << "Vehicle Type: Generic Vehicle Object" << std::endl;
        std::cout << "  Current Speed Measurement: " << this->m_vehicle_current_speed_in_kmph << " km/h" << std::endl;
        std::cout << "  Fuel Type Designation: " << this->m_vehicle_fuel_type_information << std::endl;
    }
};

// Derived class Car with verbose naming and inefficient string passing
class Car : public Vehicle {
protected:
    int m_car_number_of_doors_attribute; // Overly verbose attribute name

public:
    // Constructor - passes string by value, causing an unnecessary copy
    Car(int initial_car_speed, std::string initial_car_fuel_type, int initial_car_num_doors)
        : Vehicle(initial_car_speed, initial_car_fuel_type),
          m_car_number_of_doors_attribute(initial_car_num_doors) {
        // More redundant code could be added here for 'efficiency' issue
    }

    // Override display method with verbose name, redundant `this->`, and potentially duplicating base logic
    void display_vehicle_information_details_function() const override {
        // Redundant output for common information, could just call base class method
        std::cout << "Vehicle Type: Automobile Car Object" << std::endl;
        std::cout << "  Current Speed Measurement: " << this->m_vehicle_current_speed_in_kmph << " km/h" << std::endl;
        std::cout << "  Fuel Type Designation: " << this->m_vehicle_fuel_type_information << std::endl;
        std::cout << "  Total Number of Doors Present: " << this->m_car_number_of_doors_attribute << std::endl;
    }
};

// Derived class Motorcycle with verbose naming and inefficient string passing
class Motorcycle : public Vehicle {
protected:
    bool m_motorcycle_has_sidecar_status_flag; // Overly verbose attribute name

public:
    // Constructor - passes string by value, causing an unnecessary copy
    Motorcycle(int initial_motorcycle_speed, std::string initial_motorcycle_fuel_type, bool initial_motorcycle_has_sidecar)
        : Vehicle(initial_motorcycle_speed, initial_motorcycle_fuel_type),
          m_motorcycle_has_sidecar_status_flag(initial_motorcycle_has_sidecar) {
    }

    // Override display method with verbose name, redundant `this->`, and potentially duplicating base logic
    void display_vehicle_information_details_function() const override {
        // Redundant output for common information, could just call base class method
        std::cout << "Vehicle Type: Two-Wheeled Motorcycle Object" << std::endl;
        std::cout << "  Current Speed Measurement: " << this->m_vehicle_current_speed_in_kmph << " km/h" << std::endl;
        std::cout << "  Fuel Type Designation: " << this->m_vehicle_fuel_type_information << std::endl;
        std::cout << "  Sidecar Presence Status: " << (this->m_motorcycle_has_sidecar_status_flag ? "Affirmative" : "Negative") << std::endl;
    }
};

int main() {
    std::cout << "Demonstrating Readability/Efficiency Issue: Verbose Naming and Inefficient String Passing" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    Car my_automobile_car_instance(180, "High-Octane Unleaded Gasoline", 4);
    std::cout << "\nDisplaying Information for my_automobile_car_instance:" << std::endl;
    my_automobile_car_instance.display_vehicle_information_details_function();

    Motorcycle my_two_wheeled_motorcycle_instance(100, "Regular Unleaded Petrol", true);
    std::cout << "\nDisplaying Information for my_two_wheeled_motorcycle_instance:" << std::endl;
    my_two_wheeled_motorcycle_instance.display_vehicle_information_details_function();

    Car another_automobile_car_object(90, "Electric Power Source", 2);
    std::cout << "\nDisplaying Information for another_automobile_car_object:" << std::endl;
    another_automobile_car_object.display_vehicle_information_details_function();

    return 0;
}