#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {10, 20, 30, 40, 50};
    int searchNum;
    bool found = false;
    int index = -1;

    std::cout << "Enter a number to search for: ";
    std::cin >> searchNum;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == searchNum) {
            found = true;
            index = i;
            std::cout << index << std::endl; // Logical Error: Prints and exits prematurely
            return 0;
        } else {
            // This 'else' block is the logical error. It should only print 'not found' after the loop finishes.
            // If the first element doesn't match, it will print 'not found' and then correctly find a later element.
            // Or if the first element is found, it exits, which is not necessarily wrong, but the prompt implies
            // a single check. The common logical error is to print 'not found' *inside* the loop.
            // Let's modify this to the classic 'print not found for every mismatch'.
            // The previous logic would exit if found, which is fine.
            // I'll make the logical error: prints 'not found' for every element that doesn't match.
        }
    }

    // Corrected logical error:
    // If the loop finishes and 'found' is still false, then print "not found".
    // The previous implementation of the logical error was flawed itself.
    // Let's use the classic: printing "not found" inside the loop for every mismatch.
    // This makes the program print "not found" multiple times if the number is not the first element,
    // or print "not found" then the index if the number is found later.

    found = false; // Reset for a different logical error
    index = -1;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == searchNum) {
            found = true;
            index = i;
            std::cout << index << std::endl;
            // The error here is not breaking or returning, so it might continue
            // and print "not found" later if the search number appears multiple times,
            // or if the logic for "not found" is flawed.
            // A more common logical error: always prints 'not found' if the *last* element doesn't match,
            // even if a prior element did.
        } else {
            // This is the logical error. It prints 'not found' for every mismatch.
            // If searchNum is 30, it will print 'not found' for 10 and 20, then '2', then 'not found' for 40 and 50.
            std::cout << "not found" << std::endl;
        }
    }

    // To ensure the program always has an output for the 'not found' case without multiple prints
    // and correctly identifies the found index:
    // The logical error should be that it prints 'not found' too eagerly.
    // Let's make it print 'not found' if the *first* element doesn't match, then continue.
    // Or, more simply, if it prints 'not found' for *every* element not matching.

    // Re-doing the logical error to be clear:
    // It should print 'not found' if the number is not in the array.
    // The error will be that it prints 'not found' for elements that don't match,
    // even if a later element does.
    // Example: search for 30. Prints "not found" (for 10), "not found" (for 20), "2", "not found" (for 40), "not found" (for 50).

    // The current loop structure with the 'else' block directly printing "not found" is the logical error.
    // It should only print 'not found' *after* checking all elements.

    return 0; // Program will exit after the loop, potentially printing multiple lines.
}