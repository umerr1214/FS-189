#include <iostream>
#include <iomanip>
using namespace std;

const int MONKEYS = 3;
const int DAYS = 5;

void getFoodData(double food[][DAYS]) {
    for (int i = 0; i < MONKEYS; i++) {
        for (int j = 0; j < DAYS; j++) {
            do {
                cout << "Enter food for monkey " << (i + 1) << " on day " << (j + 1) << ": ";
                cin >> food[i][j];
                if (food[i][j] < 0) {
                    cout << "Invalid input. Food cannot be negative." << endl;
                }
            } while (food[i][j] < 0);
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
    getFoodData(food) // Syntax Error: Missing semicolon
    printReport(food);
    return 0;
}
