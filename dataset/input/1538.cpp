#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Readability/Efficiency Issue: Passing strings by value - potential inefficiency due to copying
    Engine(int hp, std::string ft) {
        this->horsepower = hp; // Readability Issue: Unnecessary use of 'this->'
        this->fuelType = ft;   // Readability Issue: Unnecessary use of 'this->'
        // Readability Issue: Overly verbose print statement
        std::cout << "Engine object initialized with " << this->horsepower << " horsepower and " << this->fuelType << "." << std::endl; // Efficiency Issue: Using std::endl
    }

    void startEngine() { // Readability Issue: Not const-correct, though it doesn't modify state
        std::cout << "Engine is now starting up..." << std::endl; // Efficiency Issue: Using std::endl
    }

    void stopEngine() { // Readability Issue: Not const-correct
        std::cout << "Engine is now shutting down..." << std::endl; // Efficiency Issue: Using std::endl
    }

    int getHorsepower() { // Readability Issue: Not const-correct
        return this->horsepower; // Readability Issue: Unnecessary use of 'this->'
    }

    std::string getFuelType() { // Readability/Efficiency Issue: Not const-correct, returns string by value (copy)
        return this->fuelType;   // Readability Issue: Unnecessary use of 'this->'
    }
};

class Car {
private:
    std::string make;
    std::string model;
    Engine engine; // Composition

public:
    // Readability/Efficiency Issue: Passing strings by value for make and model
    Car(std::string mk, std::string mdl, int hp, std::string ft)
        : make(mk), model(mdl), engine(hp, ft) // Engine constructor also takes by value
    {
        // Readability Issue: Overly verbose print statement
        std::cout << "A new Car object has been constructed for " << this->make << " " << this->model << "." << std::endl; // Efficiency Issue: Using std::endl
    }

    void start() { // Readability Issue: Not const-correct
        std::cout << "Attempting to start the car: " << this->make << " " << this->model << std::endl; // Efficiency Issue: Using std::endl
        this->engine.startEngine(); // Delegation
    }

    void stop() { // Readability Issue: Not const-correct
        std::cout << "Attempting to stop the car: " << this->make << " " << this->model << std::endl; // Efficiency Issue: Using std::endl
        this->engine.stopEngine(); // Delegation
    }

    void printDetails() { // Readability Issue: Not const-correct, verbose name
        std::cout << "Car Details:" << std::endl; // Efficiency Issue: Using std::endl
        std::cout << "  Make: " << this->make << std::endl; // Efficiency Issue: Using std::endl
        std::cout << "  Model: " << this->model << std::endl; // Efficiency Issue: Using std::endl
        std::cout << "  Engine Horsepower: " << this->engine.getHorsepower() << std::endl; // Efficiency Issue: Using std::endl
        std::cout << "  Engine Fuel Type: " << this->engine.getFuelType() << std::endl; // Efficiency Issue: Using std::endl, getFuelType returns by value
    }
};

int main() {
    Car myCar("Honda", "Civic", 120, "Gasoline"); // All strings passed by value
    myCar.printDetails();
    myCar.start();
    myCar.stop();

    std::cout << std::endl; // Efficiency Issue: Extra std::endl

    Car anotherCar("Tesla", "Model 3", 450, "Electric");
    anotherCar.printDetails();
    anotherCar.start();
    anotherCar.stop();

    return 0;
}