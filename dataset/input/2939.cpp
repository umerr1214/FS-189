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

    // Logical Error: The operator! returns the inverted value but does not update the internal _value.
    bool operator!() {
        // _value = !_value; // This line is missing, causing the logical error
        return !_value;
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