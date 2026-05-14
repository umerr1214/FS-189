#include <iostream>

bool isValidTriangle(int a, int b, int c) {
    // Side lengths must be positive
    if (a <= 0 || b <= 0 || c <= 0) {
        return false;
    }
    
    // Correctly computes the triangle inequality conditions
    bool cond1 = (a + b > c);
    bool cond2 = (a + c > b);
    bool cond3 = (b + c > a);
    
    bool is_valid = cond1 && cond2 && cond3; // This variable correctly holds the result
    
    // Semantic error: The function always returns true, regardless of the computed 'is_valid'
    return true; 
}

int main() {
    int a, b, c;
    while (std::cin >> a >> b >> c) {
        if (isValidTriangle(a, b, c)) {
            std::cout << "true" << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }
    }
    return 0;
}