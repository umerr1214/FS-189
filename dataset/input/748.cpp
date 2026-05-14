#include <iostream>
#include <iomanip>
using namespace std;

const int MONKEYS = 3;
const int DAYS = 5;

void getFoodData(double food[][DAYS]) {
    // Robustness Issue: No validation for negative input in this implementation.
    // The requirement explicitly says "Input Validation: Do not accept negative numbers".
    // This code accepts anything.
    
    for (int i = 0; i < MONKEYS; i++) {
        for (int j = 0; j < DAYS; j++) {
            cout << "Enter food: ";
            cin >> food[i][j]; // Accepts -5
        }
    }
}

void printReport(double food[][DAYS]) {
    double total = 0;
    double minFood = food[0][0];
    double maxFood = food[0][0];
    
    for (int i = 0; i < MONKEYS; i++) {
        for (int j = 0; j < DAYS; j++) {
            total += food[i][j];
            if (food[i][j] < minFood) minFood = food[i][j];
            if (food[i][j] > maxFood) maxFood = food[i][j];
        }
    }
    
    cout << "Average food per day by family: " << (total / DAYS) << endl;
    cout << "Least food eaten: " << minFood << endl;
    cout << "Greatest food eaten: " << maxFood << endl;
}

int main() {
    double food[MONKEYS][DAYS];
    // This allows negative numbers, violating requirements and potentially messing up logic 
    // (though "Least food" would correctly show negative if accepted).
    getFoodData(food); 
    printReport(food);
    return 0;
}
