#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int MONKEYS = 3;
const int DAYS = 5;

void getFoodData(double food[][DAYS]) {
    for (int i = 0; i < MONKEYS; i++) {
        for (int j = 0; j < DAYS; j++) {
            do {
                // cin >> food[i][j]; 
                // Hardcoded to simulate valid input
                food[i][j] = 5.0;
            } while (food[i][j] < 0);
        }
    }
}

void printReport(double food[][DAYS]) {
    // Efficiency Issue: Multiple passes over the array to calculate min, max, total separately.
    // Instead of one pass O(N), it does 3 passes O(3N).
    // Not a huge deal for 3x5, but bad practice for large data.
    
    double total = 0;
    for (int i = 0; i < MONKEYS; i++) {
        for (int j = 0; j < DAYS; j++) {
            total += food[i][j];
        }
    }
    
    double minFood = food[0][0];
    for (int i = 0; i < MONKEYS; i++) {
        for (int j = 0; j < DAYS; j++) {
            if (food[i][j] < minFood) minFood = food[i][j];
        }
    }
    
    double maxFood = food[0][0];
    for (int i = 0; i < MONKEYS; i++) {
        for (int j = 0; j < DAYS; j++) {
            if (food[i][j] > maxFood) maxFood = food[i][j];
        }
    }
    
    cout << "Average: " << total / DAYS << endl;
    cout << "Min: " << minFood << endl;
    cout << "Max: " << maxFood << endl;
}

int main() {
    double food[MONKEYS][DAYS];
    getFoodData(food);
    printReport(food);
    return 0;
}
