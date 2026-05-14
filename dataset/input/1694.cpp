#include <iostream>
#include <string>
#include <chrono> // For dummy delay
#include <thread> // For dummy delay

using namespace std; // Readability/Efficiency: Using namespace std in global scope

class Vehicle {
public:
    void strtEng() { // Readability: Bad method name
        cout << "   -  Vehicle's engine is now trying to start.  -   " << endl; // Readability: Overly verbose output
        // Efficiency issue: Dummy loop for simulating heavy, unnecessary work
        for (int i = 0; i < 100000; ++i) {
            string temp_str = "processing"; // Efficiency: Repeated string creation
        }
        this_thread::sleep_for(chrono::milliseconds(50)); // Simulating a delay
        cout << "   -  Vehicle's engine has successfully been initiated.  -   " << endl;
    }

    virtual ~Vehicle() {} // No specific issue here, just default.
};

class Car : public Vehicle {
public:
    void drive() {
        cout << "  ===> Car is preparing to move. <===  " << endl;
        strtEng(); // Calling base method
        cout << "  ===> Car is now in motion, driving on the road. <===  " << endl;
    }
};

class Motorcycle : public Vehicle {
public:
    void ride() {
        cout << "  ===> Motorcycle is getting ready for a ride. <===  " << endl;
        strtEng(); // Calling base method
        cout << "  ===> Motorcycle is now cruising. <===  " << endl;
    }
};

int main() {
        Car   c; // Readability: Abbreviated object name
    Motorcycle m; // Readability: Abbreviated object name

cout << "--- First demonstration with Car ---" << endl;
    c.drive(); // Inconsistent indentation
cout << endl;

    cout << "--- Second demonstration with Motorcycle ---" << endl;
    m.ride(); // Inconsistent indentation
    cout << endl;

    return 0;
}