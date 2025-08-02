/*
    AUTHOR : Ramelito N. Martinez
    DATE : June 17, 2025
    PURPOSE: Preparation for ICT PROF HANDS ON
*/

#include <iostream>
#include <fstream>
using namespace std;

int convertBinaryToDecimal(string givenBinary){
    //step 1:prepare decimalResult and binaryValue
    int decimalResult = 0;
    int binaryValue = 1;

    //step 2: loop through the givenBinary in reverse
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 3: add to decimalResult the current binaryValue when the character from givenBinary is equal to 1
        if(givenBinary[i] == '1'){
            decimalResult+=binaryValue;
        }
        //step 4: increase the binaryValue by 2 each iteration
        binaryValue*=2;
    }

    //step 5: return decimalResult
    return decimalResult;
}

char getCharacterValue(int givenDecimal){
    //step 1: prepare charValue as null
    char charValue;
    //step 2: switch through cases for givenDecimal
    switch(givenDecimal){
        case 10: charValue = 'A';break;
        case 11: charValue = 'B';break;
        case 12: charValue = 'C';break;
        case 13: charValue = 'D';break;
        case 14: charValue = 'E';break;
        case 15: charValue = 'F';break;
        default: charValue = givenDecimal + '0';break;
    }
    //step 3: return generated charValue;
    return charValue;
}

string convertBinaryToHex(string givenBinary){
    //step 1: determine size of array container based on the length of the givenBinary
    int quotientResult = givenBinary.length()/4;
    int moduloResult = givenBinary.length()%4;
    int arrayLength = quotientResult+moduloResult;

    //step 2: create an array and put arrayLength as the size of the array
    string hexArrayContainer[arrayLength];

    //step 3: loop through the givenBinary in reverse
    int indexOffHexArray = arrayLength-1;
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 4: insert each givenBinary character to the hexContainer array in reverse as well
        //each hexContainer element must have a max of 4 in length
        if(hexArrayContainer[indexOffHexArray].length() == 3){
            hexArrayContainer[indexOffHexArray]+=givenBinary[i];
            indexOffHexArray--;
        }else{
            hexArrayContainer[indexOffHexArray]+=givenBinary[i];
        }
    }

    //step 5: loop through the hexArrayContainer
    for(int i=0;i<arrayLength;i++){
        //step 6: add zeroes to the hexArray Element if the length is not 4
        if(hexArrayContainer[i].length() !=4){
            int neededZeroes = 4 - hexArrayContainer[i].length();
            for(int j=1;j<=neededZeroes;j++){
                hexArrayContainer[i]+='0';
            }
        }
        //step 7: reorder each element to its original position
        //example: givenBinary is 100010001 when it was inserted to the hexArrayContainer it became [1] [1000] [1000]
        string reorderedBits = "";
        for(int k=3;k>=0;k--){
            reorderedBits+=hexArrayContainer[i][k];
        }
        hexArrayContainer[i]=reorderedBits;
    }

    //step 8: loop through each hexArrayContainer element
    string hexResult = "";
    for(int i=0;i<arrayLength;i++){
        //step 9: convert each to decimal
        int decimalValue = convertBinaryToDecimal(hexArrayContainer[i]);
        //step 10: get its letter equivalent if greater than 9
        char charValue = getCharacterValue(decimalValue);
        //step 11: concatenate all results in hexResult;
        hexResult+=charValue;
    }

    //step 12: return result
    return hexResult;
}

void processReadingAndWritingOfFile(){
    //step 1: prepare file stream objects
    ifstream readFromFile;
    ofstream writeToFile;
    readFromFile.open("binaries.txt");
    writeToFile.open("results.txt");

    //step 2: check if read and write works, exit program if it doesn't
    if(!readFromFile.is_open()){
        cout << "unable to read from file. make sure file exist! " << endl;
        return;
    }

    if(!writeToFile.is_open()){
        cout << "unable to write to results.txt " << endl;
        return;
    }

    //step 3: do the reading and writing
    string binary;
    string title = "THIS PROGRAM CONVERTS BINARY TO HEX";
    string header = "BINARY\tHEXADECIMAL";
    writeToFile << title;
    writeToFile << header;
    cout << header << endl;
    while(readFromFile >> binary){
        cout << binary << "\t" << convertBinaryToHex(binary) << endl;
        writeToFile << binary << "\t" << convertBinaryToHex(binary) << endl;
    }

    //step 4: close the file stream objects when done
    readFromFile.close();
    writeToFile.close();
}
int main(){
    processReadingAndWritingOfFile();
return 0;
}
