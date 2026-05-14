#include <iostream>
#include <string>

// Vehicle -> Car -> SportsCar hierarchy

class Vehicle {
public:
    Vehicle() { std::cout << "Constructing Vehicle\n"; }
    virtual ~Vehicle() { std::cout << "Destroying Vehicle\n"; }
};

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
    // LOGICAL ERROR: Dynamically allocate a SportsCar object but forget to delete it.
    // This means the destructors will not be explicitly called when the pointer goes out of scope,
    // leading to a memory leak and incorrect demonstration of destructor calls.
    SportsCar* mySportsCarPtr = new SportsCar();
    // The object pointed to by mySportsCarPtr is constructed, but its destructors
    // will not be called because 'delete mySportsCarPtr;' is missing.
    // The program will exit, but the object's memory will not be freed, and its destructors
    // will not execute as intended by the question's scope demonstration.
}

int main() {
    run_destructor_demo();
    return 0;
}