#ifndef TARIFF_H
#define TARIFF_H
#include <string>
using namespace std;

bool isCorrectlyFormed(string tariffData);

int summarizeData(string tariffData, double& meanPercentage, int& numUp, int& numDown);

bool isNear(double a, double b);

bool isValidUppercaseCountryCode(string countryCode);

// You can add more helper functions if needed



#endif
