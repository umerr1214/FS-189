#include <iostream>
#include <iomanip>
using namespace std;

const int MONKEYS = 3;
const int DAYS = 5;

void getFoodData(double food[][DAYS]) {
    // ... input code ...
    // Hardcoded for testing to avoid interactive loop in driver
    for(int i=0; i<MONKEYS; i++)
        for(int j=0; j<DAYS; j++)
            food[i][j] = (i+1)*(j+1); 
}

void printReport(double food[][DAYS]) {
    double total = 0;
    double minFood = 0; // Logical Error: Initializing min to 0
    // If all food values are positive (e.g. > 5), minFood will remain 0 which is incorrect
    // unless 0 is actually in the array.
    double maxFood = 0;
    
    for (int i = 0; i < MONKEYS; i++) {
        for (int j = 0; j < DAYS; j++) {
            total += food[i][j];
            if (food[i][j] < minFood) minFood = food[i][j]; // Will never update if values > 0
            if (food[i][j] > maxFood) maxFood = food[i][j];
        }
    }
    
    cout << "Average food per day by family: " << (total / DAYS) << endl;
    cout << "Least food eaten: " << minFood << endl;
    cout << "Greatest food eaten: " << maxFood << endl;
}

int main() {
    double food[MONKEYS][DAYS];
    getFoodData(food);
    printReport(food);
    return 0;
}
