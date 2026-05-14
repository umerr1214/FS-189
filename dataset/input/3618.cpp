#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5;
    int y = 10;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap(x, y); // This call is valid
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    // Semantic error: Attempting to pass a literal (rvalue) '15' to a non-const lvalue reference 'int& a'.
    // C++ rules state that a non-const lvalue reference cannot bind to an rvalue.
    swap(15, y); 

    return 0;
}