#include "ApexuFuelMap.h"
#include <iostream>
#include <iomanip>

using namespace std;

double sampleFuelMap[20][20] = {
    {1.0,1.1,1.2,1.3,1.5,1.6,1.8,2.0,2.2,2.4,2.6,2.9,3.2,3.5,3.8,4.2,4.6,5.1,5.6,6.2},
    {1.1,1.2,1.3,1.4,1.6,1.7,1.9,2.1,2.3,2.5,2.7,3.0,3.3,3.7,4.0,4.4,4.9,5.4,5.9,6.5},
    {1.1,1.2,1.3,1.5,1.6,1.8,2.0,2.2,2.4,2.6,2.9,3.2,3.5,3.8,4.2,4.6,5.1,5.6,6.2,6.8},
    {1.2,1.3,1.4,1.6,1.7,1.9,2.1,2.3,2.5,2.8,3.0,3.3,3.7,4.0,4.4,4.9,5.4,5.9,6.5,7.1},
    {1.2,1.3,1.5,1.6,1.8,2.0,2.2,2.4,2.6,2.9,3.2,3.5,3.8,4.2,4.7,5.1,5.6,6.2,6.8,7.5},
    {1.3,1.4,1.6,1.7,1.9,2.1,2.3,2.5,2.8,3.0,3.3,3.7,4.0,4.4,4.9,5.4,5.9,6.5,7.2,7.9},
    {1.3,1.5,1.6,1.8,2.0,2.2,2.4,2.6,2.9,3.2,3.5,3.9,4.2,4.7,5.1,5.6,6.2,6.8,7.5,8.3},
    {1.4,1.6,1.7,1.9,2.1,2.3,2.5,2.8,3.0,3.3,3.7,4.1,4.5,4.9,5.4,5.9,6.5,7.2,7.9,8.7},
    {1.5,1.6,1.8,2.0,2.2,2.4,2.6,2.9,3.2,3.5,3.9,4.3,4.7,5.1,5.7,6.2,6.9,7.5,8.3,9.1},
    {1.6,1.7,1.9,2.1,2.3,2.5,2.8,3.1,3.4,3.7,4.1,4.5,4.9,5.4,5.9,6.5,7.2,7.9,8.7,9.6},
    {1.6,1.8,2.0,2.2,2.4,2.6,2.9,3.2,3.5,3.9,4.3,4.7,5.2,5.7,6.2,6.9,7.6,8.3,9.1,10.1},
    {1.7,1.9,2.1,2.3,2.5,2.8,3.1,3.4,3.7,4.1,4.5,4.9,5.4,6.0,6.6,7.2,7.9,8.7,9.6,10.6},
    {1.8,2.0,2.2,2.4,2.7,2.9,3.2,3.5,3.9,4.3,4.7,5.2,5.7,6.3,6.9,7.6,8.3,9.2,10.1,11.1},
    {1.9,2.1,2.3,2.5,2.8,3.1,3.4,3.7,4.1,4.5,4.9,5.4,6.0,6.6,7.2,7.9,8.7,9.6,10.6,11.6},
    {2.0,2.2,2.4,2.7,2.9,3.2,3.5,3.9,4.3,4.7,5.2,5.7,6.3,6.9,7.6,8.3,9.2,10.1,11.1,12.2},
    {2.1,2.3,2.5,2.8,3.1,3.4,3.7,4.1,4.5,4.9,5.4,6.0,6.6,7.2,8.0,8.8,9.6,10.6,11.7,12.8},
    {2.2,2.4,2.7,2.9,3.2,3.5,3.9,4.3,4.7,5.2,5.7,6.3,6.9,7.6,8.4,9.2,10.1,11.1,12.2,13.5},
    {2.3,2.5,2.8,3.1,3.4,3.7,4.1,4.5,5.0,5.5,6.0,6.6,7.3,8.0,8.8,9.7,10.6,11.7,12.9,14.1},
    {2.4,2.7,2.9,3.2,3.6,3.9,4.3,4.7,5.2,5.7,6.3,6.9,7.6,8.4,9.2,10.1,11.2,12.3,13.5,14.9},
    {2.5,2.8,3.1,3.4,3.7,4.1,4.5,5.0,5.5,6.0,6.6,7.3,8.0,8.8,9.7,10.7,11.7,12.9,14.2,15.6}
};

void debugPrint() {
    cout << "Initial fuel map\n";
    for (int row=0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            cout << setw(5) << fixed << setprecision(2) << sampleFuelMap[row][col];
            if (col < 19) {
                cout << ",";
            }
        }
        cout << "\n";
    }
    cout << "Final fuel map\n";
    for (int row=0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            cout << setw(5) << fixed << setprecision(2) << getCurrentFuel(row, col);
            if (col < 19) {
                cout << ",";
            }
        }
        cout << "\n";
    }
    cout << "Fuel map diff (final - initial)\n";
    for (int row =0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            cout << setw(5) << fixed << setprecision(2) << getCurrentFuel(row, col) - sampleFuelMap[row][col];
            if (col < 19) {
                cout << ",";
            }
        }
        cout << "\n";
    }
}

void checkReadWrite() {
    bool diffFound = false;
    for(int r=0; r<20; r++) {
        for(int c=0; c<20; c++) {
            if (getCurrentFuel(r, c) != getNewFuel(r, c)) {
                throw std::runtime_error("Current and newMap should not identical initially.");
            }
            if (abs(getCurrentFuel(r, c) - sampleFuelMap[r][c]) > 0.005) {
                diffFound = true;
                cerr << "Values deffer at [" << r << ", " << c << "]";
                cerr << "Expected value: " << sampleFuelMap[r][c] << " Actual value: " << getCurrentFuel(r, c) << endl;
            }
        }
    }
    if (diffFound) {
        throw std::runtime_error("Fuel map read/write error.");
    } else {
        cout << "Reading and writing fuel map was successful!\n";
    }
}

void simulateAutoTune() {
    int row = 0;
    int col = 0;
    int samples = 0;
    int cellsRange = 19;
    while (samples<=10000) {
        updateAFRData(row, col, 15.7);

        while (handleNextFuelMapWriteRequest()) {
            // loop in order to send all 8 writes requests
        }

        samples++;
        col++;
        if (col > cellsRange) {
            row++;
            col = 0;
        }
        if (row > cellsRange){
            row = 0;
        }
    }
    debugPrint();
}

int main() {
    for(int r = 1; r<=8; r++) {
        char* rawData = createFuelMapWritePacket(r, sampleFuelMap);
        readFuelMap(r, rawData);
    }
    checkReadWrite();
    simulateAutoTune();
}
