#include <iostream>
#include <memory> // For std::unique_ptr, demonstrating modern C++ practices

// Base class: Vehicle
class Vehicle {
public:
    Vehicle() { std::cout << "Constructing Vehicle\n"; }
    // Declare destructor as virtual to ensure correct cleanup in polymorphic hierarchies.
    virtual ~Vehicle() { std::cout << "Destroying Vehicle\n"; }
};

// Derived class: Car
class Car : public Vehicle {
public:
    Car() { std::cout << "Constructing Car\n"; }
    // Use 'override' specifier for clarity and compile-time checking.
    ~Car() override { std::cout << "Destroying Car\n"; }
};

// Most derived class: SportsCar
class SportsCar : public Car {
public:
    SportsCar() { std::cout << "Constructing SportsCar\n"; }
    // Use 'override' specifier for clarity and compile-time checking.
    ~SportsCar() override { std::cout << "Destroying SportsCar\n"; }
};

// Function to encapsulate the demonstration of a stack-allocated SportsCar going out of scope.
void demonstrateStackAllocatedSportsCarLifetime() {
    std::cout << "\n--- Entering demonstrateStackAllocatedSportsCarLifetime() ---\n";
    SportsCar mySportsCar; // A SportsCar object is created on the stack.
    std::cout << "  mySportsCar object is currently in scope.\n";
    // mySportsCar automatically goes out of scope when this function returns,
    // triggering its destructor and then the destructors of its base classes in reverse order.
    std::cout << "--- Exiting demonstrateStackAllocatedSportsCarLifetime() ---\n";
}

int main() {
    std::cout << "Program started.\n";

    // 1. Demonstrate destructor order for a stack-allocated object.
    // The object's lifetime is tied to the function's scope.
    demonstrateStackAllocatedSportsCarLifetime();

    // 2. Demonstrate destructor order for a dynamically-allocated object
    // deleted via a base class pointer (polymorphic deletion).
    std::cout << "\n--- Demonstrating polymorphic deletion with std::unique_ptr ---\n";
    // std::unique_ptr manages the lifetime of the dynamically allocated SportsCar.
    // When the unique_ptr goes out of scope, it will correctly call delete,
    // which, thanks to the virtual destructor in Vehicle, will invoke all destructors.
    std::unique_ptr<Vehicle> polyManagedCar = std::make_unique<SportsCar>();
    std::cout << "  SportsCar object created and managed by std::unique_ptr<Vehicle>.\n";
    // polyManagedCar goes out of scope here, automatically calling delete and all destructors.

    std::cout << "\nProgram finished.\n";
    return 0;
}