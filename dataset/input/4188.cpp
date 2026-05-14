#include <iostream>

// Semantic Error: The function is named 'is_prime', which semantically implies a boolean return type.
// However, it is declared to return 'int' and explicitly returns 0 for false and 1 for true.
// While C++ allows implicit conversion from int (0/1) to bool in conditional contexts,
// the function's signature misrepresents its true boolean nature.
int is_prime(int n) {
    if (n <= 1) return 0; // Represents false
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return 0; // Represents false
    }
    return 1; // Represents true
}

int main() {
    for (int i = 1; i <= 100; ++i) {
        // This 'if' condition works due to implicit conversion from int (0/1) to bool.
        // The code compiles and might produce correct output, but the semantic intent
        // of the function's return type is misaligned with its name and purpose.
        if (is_prime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}