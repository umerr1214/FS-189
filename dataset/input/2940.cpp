#include <iostream>
#include <string>

class BooleanFlag {
private:
    bool _value;

public:
    BooleanFlag(bool initialValue) : _value(initialValue) {}

    bool getValue() const {
        return _value;
    }

    // Semantic Error: operator! is declared const but attempts to modify _value.
    // This violates const-correctness.
    bool operator!() const { // 'const' keyword here
        _value = !_value; // Error: cannot assign to non-static data member '_value' within a const member function
        return _value;
    }
};

int main() {
    BooleanFlag flag(true);
    std::cout << "Initial: " << (flag.getValue() ? "true" : "false") << std::endl;
    bool result1 = !flag;
    std::cout << "After ! (1st time): Returned " << (result1 ? "true" : "false") << ", internal " << (flag.getValue() ? "true" : "false") << std::endl;
    bool result2 = !flag;
    std::cout << "After ! (2nd time): Returned " << (result2 ? "true" : "false") << ", internal " << (flag.getValue() ? "true" : "false") << std::endl;
    return 0;
}