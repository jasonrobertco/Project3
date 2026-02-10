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

    //valid cases
        assert(isCorrectlyFormed("us2h"));
        assert(isCorrectlyFormed("us02h"));
        //no expectation
        assert(!isCorrectlyFormed("US2"));
        //too short
        assert(!isCorrectlyFormed("US"));
        //too long
        assert(!isCorrectlyFormed("US11p78"));
        //3 digit
        assert(!isCorrectlyFormed("US100"));
        //wrong expectation
        assert(!isCorrectlyFormed("US11P"));
        //non expected char
        assert(!isCorrectlyFormed("US!"));


        
        
        double mean;
        int nUp;
        int nDown;
	// Two sample test cases

        // provided in spec
        //return 1
        mean = -999; nUp = -999; nDown = -999; 
        assert(summarizeData("FR7HjP15lUS9Hin00H", mean, nUp, nDown) == 0  &&
        isNear(mean, 7.75)  &&  nUp == 3  &&  nDown == 1);
        //return 1
        mean = -999; nUp = -999; nDown = -999; 
        assert(summarizeData("ZZ7HjP15lNZ9Hin00H", mean, nUp, nDown) == 1  &&
            mean == -999  &&  nUp == -999  &&  nDown == -999);
        //

        // empty string 0
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

        //regular case 0
        mean = -999; nUp = -999; nDown = -999; 
        assert(summarizeData("US7L", mean, nUp, nDown) == 0  &&
        isNear(mean, 7.0)   &&  nUp == 0 &&  nDown == 1);
        

        cerr << "All tests succeeded" << endl;
}

