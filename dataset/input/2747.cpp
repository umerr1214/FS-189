#include <iostream>

class Animal {
public:
    void sound() { std::cout << "Animal makes a sound.\n"; }
};

class Dog : public Animal {
public:
    void sound() { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
    void sound() { std::cout << "Woof!\n"; } // Logical Error: Cat makes a dog sound
};

int main() {
    Dog myDog;
    Cat myCat;

    std::cout << "Dog sound: ";
    myDog.sound(); // Expected: Woof!

    std::cout << "Cat sound: ";
    myCat.sound(); // Expected: Meow! (but will output Woof! due to logical error)

    return 0;
}