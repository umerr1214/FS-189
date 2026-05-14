#include <iostream>
#include <string>
#include <vector>
#include <sstream> // For building string output

// Design an Engine class with a string type and int horsepower.
class Engine {
private:
    std::string type;
    int horsepower;

public:
    // Constructor allows negative horsepower and empty type string,
    // demonstrating a lack of input validation (robustness issue).
    Engine(std::string engineType, int hp) {
        this->type = engineType;
        this->horsepower = hp;
    }

    // Getters for engine properties. Missing const-correctness.
    std::string getType() {
        return type;
    }

    int getHorsepower() {
        return horsepower;
    }

    // Method to get engine information as a string.
    std::string getInfo() {
        std::stringstream ss;
        ss << "Engine Type: " << type << ", Horsepower: " << horsepower;
        return ss.str();
    }
};

// Create a Car class that uses an Engine object as a private member, demonstrating composition.
class Car {
private:
    std::string make;
    Engine engine; // Composition: Car contains an Engine object

public:
    // Constructor for Car, initializing its make and the composed Engine object.
    Car(std::string carMake, std::string engineType, int engineHp)
        : make(carMake), engine(engineType, engineHp) { // Engine is constructed directly
    }

    // Method to display car and engine information.
    void displayCarInfo() {
        std::cout << "Car Make: " << make << std::endl;
        std::cout << "  " << engine.getInfo() << std::endl;
    }
};

int main() {
    // Test case 1: Standard valid input
    Car car1("Toyota", "V6", 280);
    car1.displayCarInfo();

    // Test case 2: Demonstrating robustness issue - negative horsepower accepted
    Car car2("Ford", "V8", -350);
    car2.displayCarInfo();

    // Test case 3: Demonstrating robustness issue - empty engine type accepted
    Car car3("Honda", "", 150);
    car3.displayCarInfo();

    return 0;
}