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
        
        // Semantic Error: Explicitly calling the destructor on a stack-allocated object.
        // This leads to undefined behavior, as the destructor will be called twice for r1:
        // once explicitly here, and once automatically when r1 goes out of scope.
        r1.~Rectangle(); 
    } // r1 goes out of scope, its destructor is automatically called again.
    
    Rectangle r2; // r2 created on the stack

    return 0; // r2 goes out of scope, its destructor is called.
}