#include <iostream>
#include <string>

class Car {
public:
    std::string make;
    std::string model;
    int year;

    // Default constructor
    Car() : make("Unknown"), model("Unknown"), year(2000) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Parameterized constructor
    Car(std::string m, std::string mod, int y) : make(m), model(mod), year(y) {
        std::cout << "Parameterized constructor called for " << make << " " << model << "." << std::endl;
    }

    // Copy constructor (Semantic Error: Missing 'const' qualifier for the reference parameter)
    // This compiles but restricts the copy constructor's usability, preventing it from copying from const objects or rvalues.
    Car(Car& other) : make(other.make), model(other.model), year(other.year) { // Should be 'const Car& other'
        std::cout << "Copy constructor called for " << other.make << " " << other.model << "." << std::endl;
    }

    void display() const {
        std::cout << "Car: " << make << " " << model << " (" << year << ")" << std::endl;
    }
};

int main() {
    // Demonstrate default constructor
    Car car1;
    car1.display();

    // Demonstrate parameterized constructor
    Car car2("Toyota", "Camry", 2020);
    car2.display();

    // Demonstrate copy constructor
    // This will compile because car2 is a non-const object.
    Car car3 = car2;
    car3.display();

    // If you uncomment the following lines, it would cause a compilation error
    // due to the semantic error in the copy constructor's signature:
    // const Car car4("Honda", "Civic", 2022);
    // Car car5 = car4; // Error: invalid initialization of non-const reference from a temporary of type 'const Car'

    return 0;
}