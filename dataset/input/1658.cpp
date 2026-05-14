#include <iostream> // Inconsistent indentation and spacing

class Vector2D {
private:
    double x; // Poor variable spacing
    double y;

public:
    // Parameterized constructor - initializes members in the body (less efficient) and adds verbose output
    Vector2D(double initialX, double initialY) {
        std::cout << "--- Parameterized constructor called. Initializing a new Vector2D object. ---" << std::endl;
        // Assigning the initial X component. This involves default construction followed by assignment,
        // which is less efficient than using an initializer list.
        this->x = initialX;
        // Assigning the initial Y component.
        this->y = initialY;
        std::cout << "Vector2D object successfully created with x = " << this->x << " and y = " << this->y << "." << std::endl;
        std::cout << "--- End of parameterized constructor. ---" << std::endl;
    }

    // Copy constructor - initializes members in the body and includes overly verbose comments
    Vector2D(const Vector2D& originalVector) {
        std::cout << "--- Copy constructor called. Creating a duplicate Vector2D object. ---" << std::endl;
        // It is crucial to perform a 'deep copy' here. For primitive 'double' members,
        // a simple member-wise assignment copies the values themselves, which constitutes
        // a deep copy of the data, as there are no pointers or dynamically allocated memory.
        this->x = originalVector.x; // Copying the X-coordinate value from the source object.
        this->y = originalVector.y; // Copying the Y-coordinate value from the source object.
        std::cout << "Vector2D object successfully copied. New vector is (" << this->x << ", " << this->y << ")." << std::endl;
        std::cout << "--- End of copy constructor. ---" << std::endl;
    }

    // Getter for x
    double getX() const { return x; }

    // Getter for y
    double getY() const { return y; }

    // Utility method to print the vector
    void print() const {
        std::cout.precision(2);
        std::cout << std::fixed << "(" << x << ", " << y << ")";
    }
};

int main() {
    // Create a Vector2D using the parameterized constructor
    std::cout << "\n>>> Creating v1 (1.0, 2.0) <<<" << std::endl;
    Vector2D v1(1.0, 2.0);
    std::cout << "v1: "; v1.print(); std::cout << std::endl;

    // Create another Vector2D using the copy constructor
    std::cout << "\n>>> Creating v2 as a copy of v1 <<<" << std::endl;
    Vector2D v2 = v1; // Uses copy constructor
    std::cout << "v2 (copy of v1): "; v2.print(); std::cout << std::endl;

    // Demonstrate that they are independent objects (conceptually)
    std::cout << "\n>>> Demonstrating independence <<<" << std::endl;
    std::cout << "v1.getX(): " << v1.getX() << ", v1.getY(): " << v1.getY() << std::endl;
    std::cout << "v2.getX(): " << v2.getX() << ", v2.getY(): " << v2.getY() << std::endl;

    return 0;
}