#ifndef HELLOCPP_APEXUFUELMAP_H
#define HELLOCPP_APEXUFUELMAP_H
#include <sstream>

using namespace std;

string createFuelMapWritePacket(int fuelRequestNumber, double (&map)[20][20]);

void readFuelMap(int fuelRequestNumber, const string& rawData);
string getCurrentNewFuelMapWritePacket();
void updateAFRData(int rpmIdx, int loadIdx, double afr);
bool handleNextFuelMapWriteRequest();

double getCurrentFuel(int row, int col);
double getNewFuel(int row, int col);

#endif //HELLOCPP_APEXUFUELMAP_H
