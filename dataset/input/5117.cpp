#include <iostream>

void swap(int& a, int& b) {
    // Logical error: This logic will make both 'a' and 'b' hold the original value of 'b'.
    a = b;
    b = a; // At this point, 'a' already holds the original value of 'b'. So 'b' also gets original 'b'.
}

int main() {
    int x = 5;
    int y = 10;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;

    swap(x, y);

    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}