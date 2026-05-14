#include <iostream>

class Counter {
private:
    int count;
public:
    Counter(int c = 0) : count(c) {}
    int getCount() const { return count; }

    // SEMANTIC ERROR: operator++ declared const, but attempts to modify 'count'.
    // A const member function cannot modify non-static member data.
    Counter& operator++() const { // This will cause a compilation error
        ++count; // Error: increment of member 'count' in read-only object
        return *this;
    }
};

int main() {
    // This part of the code will not compile due to the semantic error above.
    // It's included to make it a complete C++ program, but won't execute.
    Counter c1(5);
    std::cout << "Initial count: " << c1.getCount() << std::endl;
    
    Counter& c2 = ++c1;
    std::cout << "After prefix increment (c1): " << c1.getCount() << std::endl;
    std::cout << "After prefix increment (c2): " << c2.getCount() << std::endl;

    return 0;
}