#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For std::fixed, std::setprecision
#include <sstream> // For output to string stream

// Less precise PI for efficiency/readability concern (minor impact on correctness, but an efficiency/quality point)
#define MY_PI 3.14159

// Base class
class Shape {
public:
    virtual double calculateArea() = 0; // Missing const qualifier, less robust/efficient
    virtual ~Shape() {} // Correct virtual destructor, but manual memory management is still inefficient/less readable
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius_val; // Less descriptive name
public:
    Circle(double r) : radius_val(r) {}
    double calculateArea() override { // Missing const qualifier
        return MY_PI * radius_val * radius_val;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width_val;  // Less descriptive name
    double height_val; // Less descriptive name
public:
    Rectangle(double w, double h) : width_val(w), height_val(h) {}
    double calculateArea() override { // Missing const qualifier
        return width_val * height_val;
    }
};

// Test cases driver function
std::string run_test_cases() {
    std::vector<Shape*> myShapesCollection; // Using raw pointers, requiring manual memory management

    // Populate with Circle and Rectangle objects
    myShapesCollection.push_back(new Circle(5.0));
    myShapesCollection.push_back(new Rectangle(4.0, 6.0));
    myShapesCollection.push_back(new Circle(2.5));
    myShapesCollection.push_back(new Rectangle(10.0, 2.0));

    std::ostringstream resultStream;
    resultStream << std::fixed << std::setprecision(2);

    // Iterate and call calculateArea() using a C-style loop, less idiomatic C++ than range-based for
    for (int i = 0; i < myShapesCollection.size(); ++i) {
        Shape* currentShape = myShapesCollection[i];
        resultStream << "Shape " << (i + 1) << " Area: " << currentShape->calculateArea() << "\n";
    }

    // Manual memory cleanup - verbose, error-prone, and less readable than using smart pointers
    for (int i = 0; i < myShapesCollection.size(); ++i) {
        delete myShapesCollection[i];
        myShapesCollection[i] = nullptr; // Good practice, but adds verbosity to manual management
    }
    myShapesCollection.clear(); // Clear the vector after deleting contents

    return resultStream.str();
}

int main() {
    std::cout << run_test_cases();
    return 0;
}