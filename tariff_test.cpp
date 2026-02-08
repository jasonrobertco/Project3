#include <iostream>
#include <string>
#include <cassert>
#include "tariff.h"
using namespace std;


int main()
{
	// Two sample test cases
//	assert(isCorrectlyFormed("FR7HjP15lUS9Hin00H"));
        assert(!isCorrectlyFormed("ZZ7HjP15lNZ9Hin00H"));
        double mean;
        int nUp;
        int nDown;
	// Two sample test cases
        //mean = -999; nUp = -999; nDown = -999; 
        //assert(summarizeData("FR7HjP15lUS9Hin00H", mean, nUp, nDown) == 0  &&
         //   isNear(mean, 7.75)  &&  nUp == 3  &&  nDown == 1);
        mean = -999; nUp = -999; nDown = -999; 
        assert(summarizeData("ZZ7HjP15lNZ9Hin00H", mean, nUp, nDown) == 1  &&
            mean == -999  &&  nUp == -999  &&  nDown == -999);
        cerr << "All tests succeeded" << endl;
}

