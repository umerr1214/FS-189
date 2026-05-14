#include <iostream>
#include <string>

// Base class
class Vehicle {
public: // Using public for direct access in derived classes, bad encapsulation
    int current_speed_val; // Poorly named attribute
public:
    Vehicle(int s_val) : current_speed_val(s_val) {}

    void displayInfo() {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "This is the Vehicle's Information Section." << std::endl;
        std::cout << "The vehicle's speed is: " << current_speed_val << " mph." << std::endl;
        std::cout << "------------------------------------------" << std::endl;
    }
};

// Derived class from Vehicle
class Car : public Vehicle {
public: // Using public for direct access in derived classes, bad encapsulation
    int number_of_doors_count; // Verbose and redundant naming
public:
    Car(int s_val, int nd_count) : Vehicle(s_val), number_of_doors_count(nd_count) {}

    void displayInfo() {
        // Readability/Efficiency Issue: Calls base, then re-prints some base info,
        // and uses std::endl excessively.
        Vehicle::displayInfo(); // Calls base Vehicle's displayInfo

        std::cout << "******************************************" << std::endl;
        std::cout << "Now displaying Car-specific details." << std::endl;
        std::cout << "The vehicle's speed is still: " << current_speed_val << " mph." << std::endl; // Redundant print
        std::cout << "The number of doors for this car is: " << number_of_doors_count << "." << std::endl;
        std::cout << "******************************************" << std::endl;
    }
};

// Derived class from Car
class SportsCar : public Car {
public: // Using public for direct access in derived classes, bad encapsulation
    int spoiler_height_in_cm; // Verbose and redundant naming
public:
    SportsCar(int s_val, int nd_count, int sh_cm) : Car(s_val, nd_count), spoiler_height_in_cm(sh_cm) {}

    void displayInfo() {
        // Readability/Efficiency Issue: Calls base, then re-prints some base info,
        // and uses std::endl excessively.
        Car::displayInfo(); // Calls base Car's displayInfo

        std::cout << "==========================================" << std::endl;
        std::cout << "Finally, SportsCar unique attributes." << std::endl;
        std::cout << "The vehicle's speed is: " << current_speed_val << " mph." << std::endl; // Redundant print
        std::cout << "The number of doors is: " << number_of_doors_count << "." << std::endl; // Redundant print
        std::cout << "The spoiler's height in centimeters is: " << spoiler_height_in_cm << " cm." << std::endl;
        std::cout << "==========================================" << std::endl;
    }
};

int main() {
    SportsCar my_awesome_sports_car(100, 4, 30);
    my_awesome_sports_car.displayInfo();
    return 0;
}