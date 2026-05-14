#include <iostream>
#include <vector>
#include <string> // For verbose messages

// Base class Vehicle
class Vehicle {
public:
    Vehicle() {
        std::cout << "A new Vehicle object is being constructed right now.\n";
    }
    virtual ~Vehicle() { // Correctly virtual destructor
        std::cout << "The general Vehicle object is now being destructed.\n";
    }

    virtual void startEngine() {
        std::cout << "This is the default implementation for starting a vehicle's engine. It's a very generic process.\n";
    }
};

// Derived class Car
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Specifically, a Car object is being constructed, which is a type of Vehicle.\n";
    }
    ~Car() {
        std::cout << "The Car object has finished its lifecycle and is now being destructed.\n";
    }

    void startEngine() { // Missing 'override' keyword (minor readability issue)
        std::cout << "The Car's powerful engine is igniting with a mighty rumble! It's quite loud and impressive.\n";
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    Motorcycle() {
        std::cout << "And here, a Motorcycle object is being created, also a specific kind of Vehicle.\n";
    }
    ~Motorcycle() {
        std::cout << "The Motorcycle object is now being disposed of, concluding its operational phase.\n";
    }

    void startEngine() { // Missing 'override' keyword (minor readability issue)
        std::cout << "The Motorcycle's engine is sputtering to life, preparing for an exhilarating ride! Hear that distinctive sound?\n";
    }
};

int main() {
    std::cout << "This program demonstrates polymorphic engine starting using C++ classes, but with overly verbose output and traditional pointer management.\n\n";

    // Using raw pointers and explicit new/delete, which is less efficient in terms of safety and readability
    // compared to smart pointers, though functionally correct if delete is called.
    Vehicle* myCarVehiclePointer = new Car();
    Vehicle* myMotorcycleVehiclePointer = new Motorcycle();

    std::cout << "\nNow, we shall proceed to call the startEngine() method on each vehicle using their base class pointers:\n";

    // Call startEngine() polymorphically
    myCarVehiclePointer->startEngine();
    myMotorcycleVehiclePointer->startEngine();

    std::cout << "\nAll vehicles have attempted to start their engines. Now, for proper resource management, we must delete the dynamically allocated objects.\n";

    // Explicitly deleting the objects
    delete myCarVehiclePointer;
    delete myMotorcycleVehiclePointer;

    std::cout << "\nThe program has successfully completed its task and cleaned up all resources. End of demonstration.\n";

    return 0;
}