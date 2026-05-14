#include <iostream>
#include <string>
#include <vector>
using namespace std;

void lookupName(string target, string names[], string numbers[], int size) {
    // Efficiency Issue: Linear Search O(N).
    // For a phone book, a Hash Map (unordered_map) or Sorted Binary Search (O(log N)) is better.
    // Since input is parallel arrays, we are stuck with linear scan unless we sort them or build a map.
    // But rebuilding a map inside the function every time is O(N) overhead too.
    
    // Efficiency issue here: Passing string 'target' by value instead of const reference.
    // Copies the string every call.
    
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (names[i] == target) {
            cout << "Phone number: " << numbers[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Name not found." << endl;
    }
}

int main() {
    string names[] = {"Michael Myers", "Ash Williams"};
    string numbers[] = {"333-8000", "333-2323"};
    lookupName("Ash Williams", names, numbers, 2);
    return 0;
}
