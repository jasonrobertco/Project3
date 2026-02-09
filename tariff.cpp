/*
405941013 Jason Co

The main challenges that I faced for these functions were debugging
and determining the best way too go about checking/implementing certain functionaltiy


For the first 














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
    while(i < size){
        //check the first 2 elements of our new phrase if they are letters
        if (!isalpha(tariffData[i]) || !isalpha(tariffData[i+1])){
            return false;
        }

        //checking if these are valid per reqs aka not equal to NZ
        c = "";
        c += toupper(tariffData[i]);
        c += toupper(tariffData[i]);
        
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

