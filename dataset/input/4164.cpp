#include <iostream>
#include <string>

// Function template to return the larger of two comparable values
template <typename T>
T getLarger(T val1, T val2) {
    if (val1 > val2) { // Requires operator> to be defined for type T
        return val1;
    } else {
        return val2;
    }
}

// A custom struct that does not define comparison operators
struct MyData {
    int id;
    std::string name;

    // Constructor
    MyData(int i, std::string n) : id(i), name(std::move(n)) {}
};

int main() {
    // Demonstrate with int
    int int1 = 10;
    int int2 = 20;
    std::cout << "Comparing " << int1 << " and " << int2 << ": Larger is " << getLarger(int1, int2) << std::endl;

    // Demonstrate with double
    double double1 = 15.5;
    double double2 = 7.3;
    std::cout << "Comparing " << double1 << " and " << double2 << ": Larger is " << getLarger(double1, double2) << std::endl;

    // Semantic Error: Attempting to use getLarger with MyData,
    // which does not have operator> defined. This will cause a compilation error.
    MyData data1(1, "Apple");
    MyData data2(2, "Banana");
    // std::cout << "Comparing MyData objects: Larger is " << getLarger(data1, data2) << std::endl; // This line causes the semantic error

    return 0;
}