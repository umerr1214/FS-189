#include <iostream>
#include <string>
using namespace std;

void lookupName(string target, string names[], string numbers[], int size) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (names[i] == target) {
            cout << "Phone number: " << numbers[i] << endl;
            found = true;
            // Logical Error: Missing break statement.
            // If the name appears multiple times (unlikely in this context, but possible logic flaw),
            // or simply just continues searching unnecessarily.
            // More critical: if we wanted to find *the* number and stop.
            // But let's make it worse:
            // Suppose the arrays are not aligned correctly in the loop?
            // Or suppose we print "Name not found" inside the loop?
            
            // Let's print "Name not found" for every non-match loop iteration.
        } else {
            cout << "Name not found." << endl; // Prints "Not found" for every mismatch
        }
    }
}

int main() {
    string names[] = {"Michael Myers", "Ash Williams", "Jack Torrance"};
    string numbers[] = {"333-8000", "333-2323", "333-6128"};
    
    // Expected: Phone number: 333-2323
    // Actual: Name not found. \n Phone number: 333-2323 \n Name not found.
    lookupName("Ash Williams", names, numbers, 3);
    
    return 0;
}
