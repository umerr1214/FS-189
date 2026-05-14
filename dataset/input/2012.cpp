#include <iostream>
#include <string>
#include <cstdio> // Required for printf

class Printer {
public:
    void print(int value) {
        // Readability/Efficiency Issue: Mixing C-style I/O (printf) with C++ classes.
        // It's generally less idiomatic and can be less type-safe than std::cout.
        printf("Integer: %d\n", value);
    }

    void print(double value) {
        // Readability/Efficiency Issue: Mixing C-style I/O (printf) with C++ classes.
        // Default precision of printf for doubles can also be inconsistent with std::cout without explicit formatting.
        printf("Double: %f\n", value);
    }

    void print(const char* value) {
        // Readability/Efficiency Issue: Unnecessary conversion from const char* to std::string.
        // This adds overhead (memory allocation, copying) that is not needed as printf can directly handle const char*.
        // Also, continues the mixed I/O style.
        std::string s_value = (value != nullptr) ? value : "(null)";
        printf("String: %s\n", s_value.c_str());
    }
};

int main() {
    // This main is for local compilation/testing. The JSON driver will be used for evaluation.
    Printer p;
    p.print(20);
    p.print(2.718);
    p.print("Readability Test");
    p.print(static_cast<const char*>(nullptr));
    return 0;
}