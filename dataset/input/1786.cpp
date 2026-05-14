#include <iostream>
#include <string>

// Global counter for resource IDs to make output clearer
static int resource_count = 0;

// Syntax error: 'clas' instead of 'class'
clas Resource { 
private:
    int id;
    std::string name;
public:
    Resource(const std::string& n = "unnamed") : name(n) {
        id = ++resource_count;
        std::cout << "Resource " << id << " (" << name << ") acquired." << std::endl;
    }
    ~Resource() {
        std::cout << "Resource " << id << " (" << name << ") released." << std::endl;
    }
};

void demoScope() {
    std::cout << "  Entering demoScope..." << std::endl;
    Resource r2("local_in_demo");
    {
        std::cout << "    Entering inner scope..." << std::endl;
        Resource r3("local_in_inner");
        std::cout << "    Exiting inner scope..." << std::endl;
    } // r3 destroyed here
    std::cout << "  Exiting demoScope..." << std::endl;
} // r2 destroyed here

int main() {
    Resource r1("local_in_main");
    demoScope();
    std::cout << "End of main." << std::endl;
    return 0;
}