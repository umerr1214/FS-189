#include <iostream> // For standard input/output operations.
#include <string>   // For using std::string.

// The Car class definition.
class Car {
private:
    std::string make; // Private member to store the car's make.
    std::string model; // Private member to store the car's model.

public:
    // Default constructor definition.
    // Readability/Efficiency Issue: Members are assigned in the constructor body
    // instead of using an initializer list. This is less efficient as it involves
    // default construction followed by assignment.
    Car() {
        this->make = "Unknown Make"; // Assigning the generic make.
        this->model = "Unknown Model"; // Assigning the generic model.
    }

    // Parameterized constructor definition.
    // Readability/Efficiency Issue: Members are assigned in the constructor body
    // instead of using an initializer list. This is less efficient as it involves
    // default construction followed by assignment, potentially creating temporary
    // string objects.
    Car(const std::string& carMake, const std::string& carModel) {
        this->make = carMake; // Assigning the provided make.
        this->model = carModel; // Assigning the provided model.
    }

    // Method to display car information.
    // Readability/Efficiency Issue:
    // 1. Unnecessary use of `this->` for member access.
    // 2. Concatenates strings into a temporary `std::string` before printing,
    //    which can be less efficient than direct streaming (`std::cout << A << B`).
    // 3. Uses `std::endl` which flushes the buffer, potentially impacting performance
    //    if many print operations are done in a loop; `'\n'` is generally preferred.
    void displayCarInfo() const {
        // Building the output string.
        std::string info = "Car Info: Make = " + this->make + ", Model = " + this->model;
        std::cout << info << std::endl; // Printing the compiled information.
    }
};

// Main function where the program execution begins.
int main() {
    // Creating a Car object using the default constructor.
    Car car1;
    car1.displayCarInfo(); // Displaying information for the default car.

    // Creating another Car object using the parameterized constructor.
    Car car2("Toyota", "Camry");
    car2.displayCarInfo(); // Displaying information for the Toyota Camry.

    // Creating one more Car object.
    Car car3("Honda", "Civic");
    car3.displayCarInfo(); // Displaying information for the Honda Civic.

    return 0; // Indicating successful program termination.
}