#include <iostream>
#include <string>

// Global counter for resource IDs to make output clearer
static int resource_count = 0;

class Resource {
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

void demonstrateLeak() {
    std::cout << "  Entering demonstrateLeak (Semantic Error: Memory Leak)..." << std::endl;
    Resource* heap_res = new Resource("heap_allocated"); // Resource acquired on heap
    // SEMANTIC ERROR: No corresponding 'delete heap_res;'
    // The destructor for 'heap_res' will never be called, leading to a memory leak.
    // This violates the semantic contract of 'new' for resource management.
    std::cout << "  Exiting demonstrateLeak..." << std::endl;
} // 'heap_res' is leaked here

void demoScope() {
    std::cout << "  Entering demoScope (normal local objects)..." << std::endl;
    Resource r_local1("local_in_demo_scope1");
    {
        std::cout << "    Entering inner scope..." << std::endl;
        Resource r_local2("local_in_demo_scope2");
        std::cout << "    Exiting inner scope..." << std::endl;
    } // r_local2 destroyed here
    std::cout << "  Exiting demoScope..." << std::endl;
} // r_local1 destroyed here


int main() {
    Resource r1("main_local");
    
    // Demonstrate the memory leak semantic error
    demonstrateLeak(); 

    // Also demonstrate normal local objects as per question
    demoScope(); 

    std::cout << "End of main." << std::endl;
    return 0;
}