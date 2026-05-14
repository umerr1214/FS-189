#include <cstdio> // For C-style I/O
#include <string>

// Base class
class Vehicle {
public:
    Vehicle() {
        printf("Vehicle constructor\n"); // Using C-style I/O
        fflush(stdout); // Ensure immediate output, less efficient than std::endl for streams
    }

    ~Vehicle() {
        printf("Vehicle destructor\n");
        fflush(stdout);
    }
    
    // An unnecessary member function to illustrate verbosity/less directness
    void identifyVehicle() {
        printf("This is a vehicle.\n");
        fflush(stdout);
    }
};

// Derived class
class Car : public Vehicle {
public:
    Car() {
        printf("Car constructor\n"); // Using C-style I/O
        fflush(stdout);
    }

    ~Car() {
        printf("Car destructor\n");
        fflush(stdout);
    }
};

int main() {
    // Creating the object indirectly or with unnecessary steps
    Car* myCarPtr = new Car(); // Using heap allocation unnecessarily for a simple object
    myCarPtr->identifyVehicle(); // Calling an unnecessary function
    delete myCarPtr; // Remember to deallocate
    return 0;
}