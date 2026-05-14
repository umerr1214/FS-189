#include <iostream>

class Rectangle {
public:
    Rectangle() {
        // Constructor, not explicitly required by the question.
    }

    // Destructor as required by the question
    ~Rectangle() {
        std::cout << "Rectangle object destroyed." << std::endl;
    }
};

int main() {
    {
        Rectangle r1; // r1 created on the stack
    } // r1 goes out of scope, its destructor is called.
    
    Rectangle r2; // r2 created on the stack

    // Logical Error: An object is created on the heap but never deleted.
    // Its destructor will not be called, leading to a memory leak and incorrect output count.
    Rectangle* r_heap = new Rectangle(); 
    // To fix this logical error, one would add: delete r_heap;

    return 0; // r2 goes out of scope, its destructor is called.
              // r_heap's destructor is never called.
}