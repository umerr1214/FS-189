#include <iostream>
#include <string>

class Person {
public:
    std::string name;
protected:
    std::string address;
private:
    std::string phone;

public:
    Person(std::string n, std::string addr, std::string ph) : name(n), address(addr), phone(ph) {}

    void displayPublicInfo() const {
        std::cout << "Person Name (public): " << name << std::endl;
    }
};

class Student : public Person {
public:
    Student(std::string n, std::string addr, std::string ph) : Person(n, addr, ph) {}

    void displayStudentInfo() {
        std::cout << "--- Student Access Attempt ---" << std::endl;
        std::cout << "Student Name (public): " << name << " (Accessible)" << std::endl;
        std::cout << "Student Address (protected): " << address << " (Accessible)" << std::endl;
        // LOGICAL ERROR: This line prints a statement about phone accessibility but doesn't actually attempt to access it,
        // which is required for a complete demonstration of access rules.
        std::cout << "Student Phone (private): Access attempt omitted (Inaccessible)" << std::endl;
    }
};

void demonstrateNonMemberAccess(Person& p) {
    std::cout << "\n--- Non-Member Function Access Attempt ---" << std::endl;
    std::cout << "Non-member Name (public): " << p.name << " (Accessible)" << std::endl;
    // LOGICAL ERROR: These lines print statements about protected/private member accessibility
    // but deliberately avoid the actual access attempts that would cause compilation errors,
    // thus failing to fully demonstrate the inaccessibility as implied by the question.
    std::cout << "Non-member Address (protected): Access attempt omitted (Inaccessible)" << std::endl;
    std::cout << "Non-member Phone (private): Access attempt omitted (Inaccessible)" << std::endl;
}

int main() {
    Student s("Alice Smith", "123 Main St", "555-1234");
    s.displayStudentInfo();
    demonstrateNonMemberAccess(s);
    return 0;
}