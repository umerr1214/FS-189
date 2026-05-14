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

    bool operator!() {
        _value = !_value;
        return _value;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    BooleanFlag flag(true);
    std::cout << "Initial: " << (flag.getValue() ? "true" : "false") << std::endl;
    bool result1 = !flag;
    std::cout << "After ! (1st time): Returned " << (result1 ? "true" : "false") << ", internal " << (flag.getValue() ? "true" : "false") << std::endl;
    bool result2 = !flag;
    std::cout << "After ! (2nd time): Returned " << (result2 ? "true" : "false") << ", internal " << (flag.getValue() ? "true" : "false") << std::endl;
    return 0;
}