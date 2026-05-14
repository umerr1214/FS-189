#include <iostream>

bool isValidTriangle(int a, int b, int c) {
    // Side lengths must be positive
    if (a <= 0 || b <= 0 || c <= 0) {
        return false;
    }
    // Triangle inequality theorem
    return (a + b > c) &&
           (a + c > b) &&
           (b + c > a);
}

int main() {
    int a, b, c;
    while (std::cin >> a >> b >> c) {
        if (isValidTriangle(a, b, c)) {
            std::cout << "true" << std::endl
        } else {
            std::cout << "false" << std::endl;
        }
    }
    return 0;
}