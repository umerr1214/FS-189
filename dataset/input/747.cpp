#include <iostream>
#include <iomanip>
using namespace std;

const int MONKEYS = 3;
const int DAYS = 5;

void getFoodData(double food[][DAYS]) {
    // ... input ...
    for(int i=0; i<MONKEYS; i++)
        for(int j=0; j<DAYS; j++)
            food[i][j] = 10.0;
}

void printReport(double food[][DAYS]) {
    double total = 0;
    // Semantic Error: Using pointer comparison for max?
    // Or maybe using array indexing incorrectly.
    
    // Let's use assignment in 'if'.
    // Or maybe confusing row/col indices semantically?
    
    // Let's iterate using a single index as if it's 1D array
    // but using that index on the 2D array name?
    // food[k] returns a row pointer.
    // total += food[k]; // Semantic error: adding pointer to double
    
    for (int k = 0; k < MONKEYS * DAYS; k++) {
        // Semantic Error: Trying to access 2D array linearly using one index
        // This is valid pointer arithmetic if cast, but 'food[k]' gives the k-th ROW (if k<MONKEYS)
        // or out of bounds row pointer if k >= MONKEYS.
        // And then we try to add it to total.
        
        // Let's try:
        // total += food[k]; // Error: cannot add double* to double.
        
        // Let's try:
        // total += (double)food[k]; // Cast pointer to double? (Valid in C, warning/error in C++ depending on strictness)
        // Actually (long long) is safer for pointer.
        // But this is just nonsense.
        
        // Better semantic error: 
        // Using bitwise OR to accumulate?
        // total |= (int)food[0][0]; // Operands of | must be integral. food is double.
        
        // Let's use the classic:
        // if (food[0][0] = 5) // Assignment in condition
        
        // Or swapping indices in a way that goes OOB but looks "correct" type-wise?
        // food[j][i] where i is 0..2 (monkey), j is 0..4 (day).
        // If we swap loops:
        // for i 0..2, for j 0..4
        // access food[j][i] -> food[0..4][0..2]
        // food is defined as food[3][5].
        // food[3][0] is OOB. food[4][0] is OOB.
        // This is an OOB error which is a form of semantic/logical error.
        
        // Let's assume we use bitwise operators on doubles?
        // No, that's compile error.
        
        // Let's use `sizeof` on the array parameter?
        total += sizeof(food); // Semantic error: returns size of pointer, not array
    }
    
    cout << "Average: " << total / DAYS << endl;
}

int main() {
    double food[MONKEYS][DAYS];
    getFoodData(food);
    printReport(food);
    return 0;
}
