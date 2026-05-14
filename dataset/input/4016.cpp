#include <iostream>
#include <string>
#include <utility> // For std::move

// Readability / Efficiency Issue:
// 1. Arguments are passed by value (`T val1, T val2`), leading to unnecessary copies for complex or large data types.
// 2. Uses an `if-else` block for a simple comparison instead of a more concise ternary operator.
template <typename T>
T findMax(T val1, T val2) { // Efficiency issue: arguments passed by value
    if (val1 > val2) {       // Readability issue: verbose if-else for simple max
        return val1;
    } else {
        return val2;
    }
}

// A custom class to demonstrate copy constructor calls and efficiency issues
class MyData {
public:
    int value;
    std::string name;
    MyData(int v, std::string n) : value(v), name(std::move(n)) {
        // std::cout << "MyData Constructor: " << name << std::endl;
    }
    MyData(const MyData& other) : value(other.value), name(other.name + " (copied)") {
        std::cout << "MyData Copy Constructor: " << name << std::endl;
    }
    MyData(MyData&& other) noexcept : value(other.value), name(std::move(other.name)) {
        // std::cout << "MyData Move Constructor: " << name << std::endl;
    }
    MyData& operator=(const MyData& other) {
        if (this != &other) {
            value = other.value;
            name = other.name + " (assigned)";
        }
        // std::cout << "MyData Assignment Operator: " << name << std::endl;
        return *this;
    }
    bool operator>(const MyData& other) const {
        return value > other.value;
    }
    // ~MyData() {
    //     std::cout << "MyData Destructor: " << name << std::endl;
    // }
};

// Helper for printing MyData
std::ostream& operator<<(std::ostream& os, const MyData& md) {
    os << "{" << md.value << ", " << md.name << "}";
    return os;
}

int main() {
    // Demonstrate with int
    int maxInt = findMax(10, 20);
    std::cout << "Max of 10 and 20 (int): " << maxInt << std::endl; // Expected: 20

    // Demonstrate with double
    double maxDouble = findMax(3.14, 2.71);
    std::cout << "Max of 3.14 and 2.71 (double): " << maxDouble << std::endl; // Expected: 3.14

    // Demonstrate with char
    char maxChar = findMax('a', 'z');
    std::cout << "Max of 'a' and 'z' (char): " << maxChar << std::endl; // Expected: z

    // Demonstrate with custom type to show copy overhead
    std::cout << "\n--- MyData Example (expect copy constructor calls) ---" << std::endl;
    MyData d1(10, "Object1");
    MyData d2(20, "Object2");
    // When findMax(d1, d2) is called:
    // 1. d1 is copied into val1 (1st copy)
    // 2. d2 is copied into val2 (2nd copy)
    // 3. The returned value (either val1 or val2) is copied into maxMyData (3rd copy)
    MyData maxMyData = findMax(d1, d2);
    std::cout << "Max of MyData: " << maxMyData << std::endl; // Expected: {20, Object2 (copied)}
    std::cout << "--- End MyData Example ---\n" << std::endl;

    // Demonstrate with string to show implicit copy
    std::string s1 = "apple";
    std::string s2 = "banana";
    std::string maxString = findMax(s1, s2);
    std::cout << "Max of \"" << s1 << "\" and \"" << s2 << "\" (string): " << maxString << std::endl; // Expected: banana

    return 0;
}