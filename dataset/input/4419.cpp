#include <iostream>

// Correct and efficient function template `printValue`
// Takes an argument of any type by const reference to avoid unnecessary copies and ensure efficiency.
template <typename T>
void printValue(const T& val) {
    std::cout << "Value: " << val << '\n';
}

int main() {
    int i = 123;
    char c = 'A';

    // Demonstrate its use with an int
    printValue(i);

    // Demonstrate its use with a char
    printValue(c);

    return 0;
}