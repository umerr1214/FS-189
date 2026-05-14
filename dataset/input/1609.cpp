#include <iostream>

// Base class: Vehicle
class Vehicle {
public:
    Vehicle() { std::cout << "Constructing Vehicle\n"; }
    // Robustness Issue: Missing 'virtual' keyword for the destructor.
    // This leads to undefined behavior or incorrect destructor calls
    // when deleting a derived object through a base class pointer.
    ~Vehicle() { std::cout << "Destroying Vehicle\n"; }
};

// Derived class: Car
class Car : public Vehicle {
public:
    Car() { std::cout << "Constructing Car\n"; }
    ~Car() { std::cout << "Destroying Car\n"; }
};

// Most derived class: SportsCar
class SportsCar : public Car {
public:
    SportsCar() { std::cout << "Constructing SportsCar\n"; }
    ~SportsCar() { std::cout << "Destroying SportsCar\n"; }
};

int main() {
    std::cout << "--- Demonstrating stack-allocated SportsCar (correct destructor order) ---\n";
    { // Create a local scope for the stack-allocated object
        SportsCar myStackSportsCar; // Object created on stack
        std::cout << "  myStackSportsCar is in scope.\n";
    } // myStackSportsCar goes out of scope here, destructors are called correctly (SportsCar -> Car -> Vehicle)

    std::cout << "\n--- Demonstrating dynamically-allocated SportsCar via base pointer (Robustness Issue) ---\n";
    // Create a SportsCar object dynamically, but point to it with a Vehicle*
    Vehicle* polyCarPtr = new SportsCar();
    std::cout << "  SportsCar object created via Vehicle* pointer.\n";
    // When 'delete' is called on a base class pointer to a derived object,
    // and the base class destructor is NOT virtual, only the base class destructor is called.
    // This is a memory leak and incorrect object destruction.
    delete polyCarPtr; // Only ~Vehicle() will be called, ~Car() and ~SportsCar() are skipped.

    std::cout << "\n--- Demonstrating dynamically-allocated SportsCar via derived pointer (correct destructor order) ---\n";
    SportsCar* directSportsCarPtr = new SportsCar();
    std::cout << "  SportsCar object created via SportsCar* pointer.\n";
    // Deleting via the actual derived class pointer calls all destructors correctly.
    delete directSportsCarPtr;

    return 0;
}