#include <string>
#include <iostream>

class Engine {
private:
    std::string type;
    int horsepower;

public:
    Engine(std::string t, int hp) : type(t), horsepower(hp) {}

    // Public getters are provided for Car to use
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

    // Semantic Error: Trying to directly access a private member of the composed Engine object
    std::string getEngineTypeDirect() const {
        return myEngine.type; // This will cause a compiler error: 'std::string Engine::type' is private
    }
};

int main() {
    Car myCar("V8", 500);
    myCar.displayCarInfo();
    // Attempting to call the method with the semantic error
    std::cout << "Direct engine type access attempt: " << myCar.getEngineTypeDirect() << std::endl;
    return 0;
}