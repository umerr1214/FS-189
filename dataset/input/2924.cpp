#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits

// Base class P (cryptic name)
class P {
protected:
    std::string nm; // Cryptic data member name
    int ag;         // Cryptic data member name

public:
    // Inefficient: strings passed by value, leading to copies
    P(std::string n, int a) : nm(n), ag(a) {}
};

// Derived class S (cryptic name)
class S : public P {
private:
    std::string sID; // Cryptic data member name
    std::string mjr; // Cryptic data member name

public:
    // Inefficient: strings passed by value, leading to copies
    S(std::string n, int a, std::string id, std::string m)
        : P(n, a), sID(id), mjr(m) {}

    // Cryptic method name, excessive std::endl flushing
    void shwDts() {
        std::cout << "###Details###" << std::endl; // Excessive flushing
        std::cout << "N: " << nm << std::endl;     // Cryptic output label
        std::cout << "A: " << ag << std::endl;
        std::cout << "ID: " << sID << std::endl;
        std::cout << "M: " << mjr << std::endl;
        std::cout << "##############" << std::endl;
    }
};

int main() {
    std::string nI; // Cryptic input variable names
    int aI;
    std::string sIDI;
    std::string mjrI;

    // No comments explaining sections
    std::cout << "Enter N: ";
    std::getline(std::cin, nI);

    std::cout << "Enter A: ";
    std::cin >> aI;
    // Clearing input buffer after integer read. This is a good practice,
    // but the other issues (naming, passing by value, excessive endl)
    // are sufficient for readability/efficiency issues.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter ID: ";
    std::getline(std::cin, sIDI);

    std::cout << "Enter M: ";
    std::getline(std::cin, mjrI);

    S s(nI, aI, sIDI, mjrI);
    s.shwDts();

    return 0;
}