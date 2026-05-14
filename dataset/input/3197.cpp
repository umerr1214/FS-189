#include <string>
#include <iostream>

class Engine {
private:
    std::string type;
    int horsepower;

public:
    Engine(std::string t, int hp) : type(t), horsepower(hp) {}

    std::string getType() const {
        return type;
    }

    int getHorsepower() const {
        return horsepower;
    }
};

class Car {
private:
    Engine myEngine; // Composition

public:
    // Logical Error: The horsepower passed to the Engine constructor is always 100, ignoring the input parameter.
    Car(std::string engineType, int engineHorsepower) : myEngine(engineType, 100) {}

    void displayCarInfo() const {
        std::cout << "Car Engine Type: " << myEngine.getType() << std::endl;
        std::cout << "Car Engine Horsepower: " << myEngine.getHorsepower() << std::endl;
    }
};

int main() {
    Car myCar("V8", 500); // Intended horsepower: 500
    myCar.displayCarInfo(); // Actual output will be 100 horsepower
    
    Car anotherCar("Electric", 250); // Intended horsepower: 250
    anotherCar.displayCarInfo(); // Actual output will be 100 horsepower
    
    return 0;
}