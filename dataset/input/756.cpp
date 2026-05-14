#include <iostream>
#include <iomanip>
using namespace std;

const int MONTHS = 3;
const int DAYS = 30;

void analyzeWeather(char weather[][DAYS]) {
    int totalR = 0, totalC = 0, totalS = 0;
    int maxRain = -1;
    int rainyMonth = -1;
    
    for (int i = 0; i < MONTHS; i++) {
        int r = 0, c = 0, s = 0;
        for (int j = 0; j < DAYS; j++) {
            char condition = weather[i][j];
            if (condition == 'R') r++;
            else if (condition == 'C') c++;
            else if (condition == 'S') s++;
        }
        
        cout << "Month " << i << ": Rainy=" << r << ", Cloudy=" << c << ", Sunny=" << s << endl;
        
        totalR += r;
        totalC += c;
        totalS += s;
        
        if (r > maxRain) {
            maxRain = r;
            rainyMonth = i;
        }
    }
    
    cout << "Total Season: Rainy=" << totalR << ", Cloudy=" << totalC << ", Sunny=" << totalS << endl;
    cout << "Month with largest number of rainy days: ";
    if (rainyMonth == 0) cout << "June";
    else if (rainyMonth == 1) cout << "July";
    else if (rainyMonth == 2) cout << "August";
    cout << " (" << maxRain << " days)" << endl;
}

int main() {
    char weather[MONTHS][DAYS];
    
    // Initialize with sample data
    for (int i = 0; i < MONTHS; i++) {
        for (int j = 0; j < DAYS; j++) {
            if (j % 3 == 0) weather[i][j] = 'R';
            else if (j % 3 == 1) weather[i][j] = 'C';
            else weather[i][j] = 'S';
        }
    }
    // Make July rainier
    for (int j = 0; j < DAYS; j++) weather[1][j] = 'R';
    
    analyzeWeather(weather);
    
    return 0;
}
