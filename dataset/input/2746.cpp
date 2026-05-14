#include <iostream>

class Animal {
public:
    void sound() { std::cout << "Animal makes a sound.\n" } // Syntax Error: Missing semicolon
};

class Dog : public Animal {
public:
    void sound() { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
    void sound() { std::cout << "Meow!\n"; }
};

int main() {
    std::cout << "This program contains a syntax error and will not compile.\n";
    // If it were to compile, a driver might instantiate Dog and Cat
    // and call their sound methods.
    // Dog myDog;
    // Cat myCat;
    // myDog.sound();
    // myCat.sound();
    return 0;
}