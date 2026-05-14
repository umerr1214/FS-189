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
    Car(std::string engineType, int engineHorsepower) : myEngine(engineType, engineHorsepower) {}

    void displayCarInfo() const {
        std::cout << "Car Engine Type: " << myEngine.getType() << std::endl;
        std::cout << "Car Engine Horsepower: " << myEngine.getHorsepower() << std::endl;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Car myCar("V8", 500);
    myCar.displayCarInfo();
    return 0;
}