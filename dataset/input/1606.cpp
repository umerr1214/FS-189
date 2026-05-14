#include <iostream>
#include <string>

// Vehicle -> Car -> SportsCar hierarchy

class Vehicle {
public:
    Vehicle() { std::cout << "Constructing Vehicle\n"; }
    virtual ~Vehicle() { std::cout << "Destroying Vehicle\n"; }
}; // SYNTAX ERROR: Missing semicolon here

class Car : public Vehicle {
public:
    Car() { std::cout << "Constructing Car\n"; }
    ~Car() override { std::cout << "Destroying Car\n"; }
};

class SportsCar : public Car {
public:
    SportsCar() { std::cout << "Constructing SportsCar\n"; }
    ~SportsCar() override { std::cout << "Destroying SportsCar\n"; }
};

// Function to encapsulate the demonstration logic
void run_destructor_demo() {
    SportsCar mySportsCar; // SportsCar object goes out of scope at the end of this function
}

int main() {
    run_destructor_demo();
    return 0;
}