#include <iostream>
#include <string>
// <utility> is not included for std::move, highlighting potential inefficiency

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    // Default constructor - Readability/Efficiency Issue: verbose, not using initializer list
    Car() {
        std::cout << "Default constructor called (verbose)." << std::endl;
        this->make = "Default Make"; // Using 'this' is redundant here
        this->model = "Default Model";
        this->year = 0; // Primitive type is initialized, but not via initializer list
    }

    // Parameterized constructor - Readability/Efficiency Issue:
    // 1. Takes std::string by const reference, then copies to member via assignment.
    //    This means `make` and `model` are default-constructed, then assigned, which is less efficient
    //    than direct initialization via an initializer list, especially for complex types like std::string.
    //    It also misses the opportunity to efficiently move rvalue string arguments.
    // 2. Not using member initializer list for 'year'.
    Car(const std::string& p_make, const std::string& p_model, int p_year) {
        std::cout << "Parameterized constructor called (inefficient string copies)." << std::endl;
        make = p_make;  // Copy assignment
        model = p_model; // Copy assignment
        year = p_year;    // Assignment, not direct initialization
    }

    // Copy constructor - Readability/Efficiency Issue: verbose, not using initializer list
    Car(const Car& other) {
        std::cout << "Copy constructor called (verbose)." << std::endl;
        make = other.make;  // Copy assignment
        model = other.model; // Copy assignment
        year = other.year;    // Assignment
    }

    void display() const {
        std::cout << "Car Info: Make=" << make << ", Model=" << model << ", Year=" << year << "." << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Constructors (Readability/Efficiency Issue) ---" << std::endl;

    // 1. Default Constructor
    Car myCar1;
    myCar1.display();

    std::cout << std::endl;

    // 2. Parameterized Constructor
    Car myCar2("Ford", "Focus", 2018);
    myCar2.display();

    std::cout << std::endl;

    // 3. Copy Constructor
    Car myCar3 = myCar2;
    myCar3.display();

    std::cout << std::endl;

    return 0;
}