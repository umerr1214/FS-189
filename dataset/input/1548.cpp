#include <iostream>
#include <string>

// Vehicle class
class Vehicle {
public:
    Vehicle() {
        // SEMANTIC ERROR: 'cout' and 'endl' are not declared in this scope without 'std::' or 'using namespace std;'
        cout << "Vehicle constructor" << endl;
    }
    void startEngine() {
        std::cout << "Vehicle engine started." << std::endl;
    }
};

// Car class
class Car : public Vehicle {
public:
    Car() {
        // SEMANTIC ERROR: 'cout' and 'endl' are not declared in this scope without 'std::' or 'using namespace std;'
        cout << "Car constructor" << endl;
    }
    void drive() {
        std::cout << "Car is driving." << std::endl;
    }
};

// SportsCar class
class SportsCar : public Car {
public:
    SportsCar() {
        // SEMANTIC ERROR: 'cout' and 'endl' are not declared in this scope without 'std::' or 'using namespace std;'
        cout << "SportsCar constructor" << endl;
    }
    void activateBoost() {
        std::cout << "SportsCar boost activated!" << std::endl;
    }
};

int main() {
    SportsCar mySportsCar;
    mySportsCar.startEngine();
    mySportsCar.drive();
    mySportsCar.activateBoost();
    return 0;
}