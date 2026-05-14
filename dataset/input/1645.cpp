#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;

public:
    // Default constructor - Robustness issue: Initializes with empty strings
    // instead of specified generic values like 'Unknown Make', 'Unknown Model'.
    // This can lead to ambiguity or misinterpretation of the car's state,
    // as an empty string might mean 'not set' rather than 'unknown'.
    Car() : make(""), model("") {
        // No specific generic values used as per requirement, creating a less robust default state.
    }

    // Parameterized constructor
    Car(const std::string& carMake, const std::string& carModel)
        : make(carMake), model(carModel) {
    }

    // displayCarInfo() method - Robustness issue: Not marked as const.
    // A method that merely displays information should ideally not modify the object's state,
    // and marking it const makes the class more robust against accidental modification
    // and allows it to be called on const Car objects.
    void displayCarInfo() {
        std::cout << "Car Info: Make = " << make << ", Model = " << model << std::endl;
    }
};

int main() {
    // Test default constructor
    Car car1;
    car1.displayCarInfo();

    // Test parameterized constructor
    Car car2("Toyota", "Camry");
    car2.displayCarInfo();

    Car car3("Honda", "Civic");
    car3.displayCarInfo();

    // Test with empty strings passed to parameterized constructor
    Car car4("", "");
    car4.displayCarInfo();

    return 0;
}