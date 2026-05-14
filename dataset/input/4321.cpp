#include <iostream>
#include <string>

void solve() {
    std::string name;
    int age;

    std::cout << "Enter your name: ";
    std::cin >> name; // Reads a single word

    std::cout << "Enter your age: ";
    std::cin >> age; // Reads an integer

    // This program doesn't handle non-integer input for age.
    // If a non-integer is entered, std::cin will enter a fail state,
    // and 'age' will remain uninitialized or hold a garbage value.
    // Subsequent uses of std::cin might also fail or lead to an infinite loop
    // if not cleared.

    std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;
}

int main() {
    solve();
    return 0;
}