#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include "tariff.h"
using namespace std;


bool isNear(double a, double b)
{
    return abs(a - b) < 0.001;
}

int main()
{
	// Two sample test cases
	assert(isCorrectlyFormed("FR7HjP15lUS9Hin00H"));
        assert(!isCorrectlyFormed("ZZ7HjP15lNZ9Hin00H"));
        double mean;
        int nUp;
        int nDown;
	// Two sample test cases



        // provided in spec
        mean = -999; nUp = -999; nDown = -999; 
        assert(summarizeData("FR7HjP15lUS9Hin00H", mean, nUp, nDown) == 0  &&
        isNear(mean, 7.75)  &&  nUp == 3  &&  nDown == 1);
        mean = -999; nUp = -999; nDown = -999; 
        assert(summarizeData("ZZ7HjP15lNZ9Hin00H", mean, nUp, nDown) == 1  &&
            mean == -999  &&  nUp == -999  &&  nDown == -999);


        // empty string
        mean = -999; nUp = -999; nDown = -999; 
        assert(summarizeData("", mean, nUp, nDown) == 0  &&
        mean == 0  &&  nUp == 0 &&  nDown == 0);
        
        // return 2
        mean = -999; nUp = -999; nDown = -999; 
        assert(summarizeData("US99H", mean, nUp, nDown) == 2  &&
        mean == -999  &&  nUp == -999 &&  nDown == -999);

        mean = -999; nUp = -999; nDown = -999; 
        assert(summarizeData("US0L", mean, nUp, nDown) == 2  &&
        mean == -999  &&  nUp == -999 &&  nDown == -999);
        

        cerr << "All tests succeeded" << endl;
}

