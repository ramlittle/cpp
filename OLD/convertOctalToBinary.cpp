#include <iostream>
#include <string>

using namespace std;

string convertToBinary(int decimalNumber){
    string binaryResult="";
    //determine maximum binValue to use
    int binValue=1;
    while(binValue<=decimalNumber){
        binValue*=2;
    }
    //converto to binary
    while(binValue!=0){
        if(decimalNumber >= binValue){
            binaryResult+="1";
            decimalNumber-=binValue;
        }else{
            binaryResult+="0";
            //remove created front zero
            if(binaryResult[0]=='0'){
                binaryResult="";
            }
        }
        binValue/=2;
    }
    return binaryResult;
}

string convertOctalToBinary(int givenOctal){
    //convert to string
    string givenOctalToString = to_string(givenOctal);
    int lengthOfGiven = givenOctalToString.length();

    //predefined array based on legnth
    string octalArray[lengthOfGiven];

    //conver each element to bin
    for(int i=0;i<lengthOfGiven;i++){
        int perDigit = givenOctalToString[i] - '0';
        string binResult=convertToBinary(perDigit);
        octalArray[i]=binResult;
    }

    //process each octalArray Element
    string finalResult="";
    for(int i=0;i<lengthOfGiven;i++){
        int lengthOfEachElement = octalArray[i].length();
        int neededStartingZeroes = 3-lengthOfEachElement;

        //add zeroes to the resulting binary if length is not 3
        if(neededStartingZeroes>0){
            string temp = octalArray[i]; // move the content of element to temp location
            octalArray[i] = "";     //reset the content of octalArray;
            //add zeroes needed to complete octal value of the element6
            for(int j=1;j<=neededStartingZeroes;j++){
                octalArray[i]+="0";
            }
            //add the temp to new octalArray Element
            octalArray[i]+=temp;
        }

        //combine the elements into one string variable
        finalResult += octalArray[i];
    }

    return finalResult;
}



int main(){
int octalMo;
cout << "provide octal" << endl;
cin >> octalMo;
cout << convertOctalToBinary(octalMo);

return 0;
}
