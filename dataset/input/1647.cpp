#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;

public:
    // Default constructor: Initializes with generic values using an initializer list.
    Car() : make("Unknown Make"), model("Unknown Model") {
    }

    // Parameterized constructor: Initializes with provided values using an initializer list.
    Car(const std::string& carMake, const std::string& carModel)
        : make(carMake), model(carModel) {
    }

    // displayCarInfo() method: Displays car details.
    // Marked as const to indicate it does not modify the object's state,
    // enhancing robustness and allowing it to be called on const Car objects.
    void displayCarInfo() const {
        std::cout << "Car Info: Make = " << make << ", Model = " << model << '\n';
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

    // Test with custom values
    Car car4("Ford", "Mustang");
    car4.displayCarInfo();

    return 0;
}