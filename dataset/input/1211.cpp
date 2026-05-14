#include <iostream>
#include <string>

class ResourceHandler {
private:
    std::string resourceName;
public:
    ResourceHandler(std::string name = "System Resource") : resourceName(name) {
        std::cout << "Resource '" << resourceName << "' acquired." << std::endl;
    }

    // Logical error: The destructor prints a message that doesn't explicitly indicate release.
    ~ResourceHandler() {
        std::cout << "Resource '" << resourceName << "' handled." << std::endl; // This message is misleading
    }
};

void manageResource() {
    ResourceHandler r1("Database Connection");
    // r1 destructor will be called here
}

int main() {
    std::cout << "Entering main scope." << std::endl;
    ResourceHandler r2("File Handle");
    manageResource();
    std::cout << "Exiting main scope." << std::endl;
    // r2 destructor will be called here
    return 0;
}