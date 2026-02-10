/*
405941013 Jason Co

The main challenges that I faced for these functions were debugging
and determining the best way too go about checking/implementing certain functionaltiy


For the first function instead of using an array/for loop I opted to ue a while loop

I initially struggled because I wanted to format the string in the right way by cpaitilizing to have a universal
check for the country, getting a proper int for the number and parsing, however I realized
that this was actually for the 2nd funciton.

Once I realized htis, I was able to break it down into smaller parts with pseudocode.

I knew that I needed to iterate over a string but did not know that hte stirng contained multiple
of these coutnry codes, when realizing this Iknew that I needed "2 loops in a sense"
Because I needed to pass over all these codes but evey time we encountered a new code, 
we needed to "reset" what we were looking for

As a result I made a temporary variable  called length to kepe track of these parementers
for my pseudo code

while current i index is less than the whole string
    if the first 2 indexes are not valid letters then return false
    c keeps track of the letters to get the NZ edge case capitalizes both so only hav eto check NZ vs nz etc
    then check for how many numbers if its a 1 digit or 2 digit code ie 1 vs 99
    we do this by checking against the next element vs the size of the stirng to see if its invalid
    i set the default case to len - 1
    then we check if it is a digit respecitevly
    based on this modified length we then check the next letter for expectation
    after we then index vy skipping a space based on if the whole stirn gis compelted to mvoe to the next code

For the 2nd funciton I used a similar concept the mainc hallenges I had were formatting for example to get the countyr code number
turn that string into an int and how to perform operations and store it

I also notinced that to deal with pass by reference vs pass by value (copy)
where we are directyl returning and modifying which helps with our test cases and the utility of the funciton

I created temproary coutners to treat the upper or down and other caes in order to calcualte things like mean

the above function used a similar pesuedo code 
wioth a deafult length and checks if its cirrectly formatted first because no gauarantee the user runs it first

while current i index is less than the whole string
    handle 1 case see if its calid first

    creating more temp variables than before
    i still stands for index
    size for size
    c for country
    length as a way to move between phrases

    pct standards for percent
    total and count are used to calculate mean percentage which is returned as pass by reference
    these are used in a final calc at the end of the function

    up and down are also used as coutners for a final calc respectively

    we no longer need to check if the stirng is valid stince it passed the case but we can use some of the same logic
        if the first 2 indexes are not valid letters then return false
        c keeps track of the letters to get the NZ edge case capitalizes both so only hav eto check NZ vs nz etc
        then check for how many numbers if its a 1 digit or 2 digit code ie 1 vs 99
        we do this by checking against the next element vs the size of the stirng to see if its invalid
        i set the default case to len - 1
        then we check if it is a digit respecitevly
        based on this modified length we then check the next letter for expectation
        after we then index vy skipping a space based on if the whole stirn gis compelted to mvoe to the next code

    pct = tariffData[i + 2] - '0'; //0-9 are consecutive in ascii
    i had trouble at first because we cannot just multiple this or treat is as an int for our calculations
    we need to first convert this to an int and can do so by this function since its onyl one mnumber at a time

    we can then move over 1 decimal place if needed for the 2 digit "edge" case 
    if (i + 3 < size && isdigit(tariffData[i + 3]))
        {
            //move decimal place over 1
            pct = pct * 10 + (tariffData[i + 3] - '0');
            len = 5; //increase length
        }


    after we check for the expectationc ase where 
    if ((pct == 99 && (expect == 'H' || expect == 'h')) || (pct == 0  && (expect == 'L' || expect == 'l')))
        {
            return 2;
        }
    I decided to do an explicit check here

    the way this is ordered as well helps us and is most logical for a decision tree
    by having a known index with a known pattern, we are able to add more checkers if neede to the function
    as we know what place we are in and cn bring up edge cases before proceeding

    Finally the incrmeents and aclcs are performed a thte bottom
    /for mean canculation at end
        total += pct;
        count++;
        //onyl need to check the high case
        if (expect == 'H' || expect == 'h')
            up++;
        else
            down++;
        //increment to next phrase
        i += len;













*/


#include <string>
#include "tariff.h"
using namespace std;

bool isCorrectlyFormed(string tariffData)
{
	// TODO: Correctly implement this function!!
	//return false;
    //empty string is valid

    /*return true if
    string 0+ country records
        2 letters
            valid uppercase
            not NZ
        1 or 2 digits
        one expectation letter
    */
    //empty case
    if(tariffData == ""){
            return true;
    }
    int i = 0; //indes
    int size = tariffData.size(); //length of string
    string c = ""; //declare string for country check
    int len = 4; //assume default length for country + number + expectation

    //check for length of the phrase so we can short circuit if necessary
    if(size < 4){
        return false;
    }
    //iterate through whole phrase
    while(i < size)
        len = 4; //default
        if (i + 3 >= size){ //size
            return false;
        }

        //check the first 2 elements of our new phrase if they are letters
        if (!isalpha(tariffData[i]) || !isalpha(tariffData[i+1])){
            return false;
        }

        //checking if these are valid per reqs aka not equal to NZ
        c = "";
        c += toupper(tariffData[i]);
        c += toupper(tariffData[i+1]);
        
        //checking for NZ edgecase and if the next is a number
        if(c == "NZ" || !isValidUppercaseCountryCode(c) || !isdigit(tariffData[i+2])){
            return false;
        }
        //we assume 1 digit as the normal case
        //edge case
        //check for 2nd digit
        if (i + 3 < size && isdigit(tariffData[i+3])){
            //check if we have expection after
            if(i + 4 >= size){
                return false;
            }
            //set len to 2 for 2 chars
            len = 5;
        }

        // expectation

        //use last character in the phrase 
            //len changes above based on number
        char expect = tariffData[i + len - 1];
        //if its not a valid char return false
        if (expect != 'H' && expect != 'h' && expect != 'L' && expect != 'l'){
            return false;
        }
        //move to next word to parse move i by length
        i += len;
    }
    //passes cases
    return true;
}

//function 2 :)
int summarizeData(string tariffData, double& meanPercentage, int& numUp, int& numDown)
{
	// TODO: Correctly implement this function!!
    //validate stirng first

    //if stirng not valid return 1
    if (!isCorrectlyFormed(tariffData)){
	return 1;
    }
    int i = 0; //index
    int size = tariffData.size(); //length of string
    string c = ""; //declare string for country check
    int len = 4; //assume default length for country + number + expectation

    int pct = 0; // percent
    int total = 0;
    int count = 0;

    int up = 0;
    int down = 0;
    while (i < size)
    {
        len = 4; //reset length assume deafult 4
        //need to format tariff percentages as a number -> int
        pct = tariffData[i + 2] - '0'; //0-9 are consecutive in ascii

        //same check as before for edge cases
        if (i + 3 < size && isdigit(tariffData[i + 3]))
        {
            //move decimal place over 1
            pct = pct * 10 + (tariffData[i + 3] - '0');
            len = 5; //increase length
        }

        //expectation letter indexed based on length
        char expect = tariffData[i + len - 1];

        //edge case error 2
        if ((pct == 99 && (expect == 'H' || expect == 'h')) || (pct == 0  && (expect == 'L' || expect == 'l')))
        {
            return 2;
        }
        //for mean canculation at end
        total += pct;
        count++;
        //onyl need to check the high case
        if (expect == 'H' || expect == 'h')
            up++;
        else
            down++;
        //increment to next phrase
        i += len;
    }

    //pas by reference -> & in header
    if (count == 0){
        meanPercentage = 0;
    } else {
        //need to convert this into a double
        meanPercentage = static_cast<double>(total)/count;
    }

    //pass by refernce up and down
    numUp = up;
    numDown = down;
    //return default
    return 0;
}

bool isNear(double a, double b)
{
        return abs(a - b) < 1e-7;
}

//*************************************
//  isValidUppercaseCountryCode
//*************************************

// Return true if the argument is a two-uppercase-letter country code, or
// false otherwise.

bool isValidUppercaseCountryCode(string countryCode)
{
    const string codes =
        "AD.AE.AF.AG.AI.AL.AM.AO.AQ.AR.AS.AT.AU.AW.AX.AZ.BA.BB.BD.BE.BF.BG.BH."
        "BI.BJ.BL.BM.BN.BO.BQ.BR.BS.BT.BV.BW.BY.BZ.CA.CC.CD.CF.CG.CH.CI.CK.CL."
        "CM.CN.CO.CR.CU.CV.CW.CX.CY.CZ.DE.DK.DJ.DM.DO.DZ.EC.EE.EG.EH.ER.ES.ET."
        "FI.FJ.FK.FM.FO.FR.GA.GB.GD.GE.GF.GG.GH.GI.GL.GN.GM.GP.GQ.GR.GS.GT.GU."
        "GW.GY.HK.HM.HN.HR.HT.HU.ID.IE.IL.IM.IN.IO.IQ.IR.IS.IT.JE.JM.JO.JP.KE."
        "KG.KH.KI.KM.KN.KP.KR.KW.KY.KZ.LA.LB.LC.LI.LK.LR.LS.LT.LU.LV.LY.MA.MC."
        "MD.ME.MF.MG.MH.MK.ML.MM.MN.MO.MP.MQ.MR.MS.MT.MU.MV.MW.MX.MY.MZ.NA.NC."
        "NE.NF.NG.NI.NL.NO.NP.NR.NU.NZ.OM.PA.PE.PF.PG.PH.PK.PL.PM.PN.PR.PS.PT."
        "PW.PY.QA.RE.RO.RS.RU.RW.SA.SB.SC.SD.SE.SG.SH.SI.SJ.SK.SL.SM.SN.SO.SR."
        "SS.ST.SV.SX.SY.SZ.TC.TD.TF.TG.TH.TJ.TK.TL.TM.TN.TO.TR.TT.TV.TW.TZ.UA."
        "UG.UK.UM.US.UY.UZ.VA.VC.VE.VG.VI.VN.VU.WF.WS.YE.YT.ZA.ZM.ZW";
    return (countryCode.size() == 2  &&
            countryCode.find('.') == string::npos  &&  // no '.' in countryCode
            codes.find(countryCode) != string::npos);  // match found
}

// You may implement any helper functions as needed here

