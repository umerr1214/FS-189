#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Included but not optimally utilized for deletion

// Base class - Virtual destructor is correctly implemented
class Shape {
public:
    Shape(const std::string& name) : name_(name) {
        std::cout << "Shape base object '" << name_ << "' is being constructed." << std::endl;
    }
    virtual ~Shape() { // Virtual destructor is correctly implemented
        std::cout << "  ~Shape() destructor called for base object '" << name_ << "'." << std::endl;
    }
    virtual void draw() const = 0; // Pure virtual function
    std::string getName() const { return name_; }
protected:
    std::string name_;
};

// Derived class 1
class Rectangle : public Shape {
public:
    Rectangle(double width, double height)
        : Shape("Rectangle"), width_(width), height_(height) {
        std::cout << "  Rectangle object is being constructed with width " << width << " and height " << height << "." << std::endl;
    }
    ~Rectangle() override {
        std::cout << "    ~Rectangle() destructor called for '" << getName() << "'." << std::endl;
    }
    void draw() const override {
        std::cout << "Drawing a Rectangle: dimensions " << width_ << "x" << height_ << "." << std::endl;
    }
private:
    double width_;
    double height_;
};

// Derived class 2
class Circle : public Shape {
public:
    Circle(double radius)
        : Shape("Circle"), radius_(radius) {
        std::cout << "  Circle object is being constructed with radius " << radius << "." << std::endl;
    }
    ~Circle() override {
        std::cout << "    ~Circle() destructor called for '" << getName() << "'." << std::endl;
    }
    void draw() const override {
        std::cout << "Drawing a Circle: radius " << radius_ << "." << std::endl;
    }
private:
    double radius_;
};

// Driver code
int main() {
    std::vector<Shape*> myShapesCollection;

    std::cout << "--- Beginning of shape creation process ---" << std::endl;
    myShapesCollection.push_back(new Rectangle(12.5, 7.0));
    myShapesCollection.push_back(new Circle(5.0));
    myShapesCollection.push_back(new Rectangle(4.0, 9.5));
    myShapesCollection.push_back(new Circle(8.2));
    std::cout << "--- Shape creation process completed ---" << std::endl << std::endl;

    std::cout << "--- Initiating drawing operations for all shapes ---" << std::endl;
    for (size_t i = 0; i < myShapesCollection.size(); ++i) { // Readability Issue: Uses indexed loop for iteration
        std::cout << "  Shape #" << (i + 1) << ": ";
        myShapesCollection[i]->draw();
        std::cout << std::endl; // Efficiency Issue: Frequent std::endl
    }
    std::cout << "--- Drawing operations concluded ---" << std::endl << std::endl;

    std::cout << "--- Starting memory cleanup for shape objects (Readability/Efficiency Issue: manual indexed deletion) ---" << std::endl;
    // Readability/Efficiency Issue:
    // Using an old-style indexed loop for deletion is less readable and more error-prone
    // than a range-based for loop or std::for_each for simple iteration and deletion.
    // Also, frequent use of std::endl can be less efficient than '\n'.
    for (size_t i = 0; i < myShapesCollection.size(); ++i) {
        std::cout << "  Deleting shape at index " << i << "..." << std::endl;
        delete myShapesCollection[i];
        myShapesCollection[i] = nullptr; // Verbose but good practice
    }
    myShapesCollection.clear(); // Clear the vector after deletion
    std::cout << "--- Memory cleanup finished ---" << std::endl;

    std::cout << std::endl << "Program has successfully executed and is now terminating." << std::endl;
    return 0;
}