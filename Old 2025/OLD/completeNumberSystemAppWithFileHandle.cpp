/*
    AUTHOR : Ramelito Martinez
    EDPSE MOCK EXAM
*/

#include <iostream>
#include <fstream>
using namespace std;

struct ObjectToSave{
    string title;
    string given;
    int decimalValue;
    string binaryValue;
    string octalValue;
    string hexValue;
};
int getIntegerEquivalent(char givenChar){
    //step 1: prepare integerResult
    int integerResult;
    //step 2: switch through available options
    switch(givenChar){
        case 'A': integerResult = 10; break;
        case 'B': integerResult = 11; break;
        case 'C': integerResult = 12; break;
        case 'D': integerResult = 13; break;
        case 'E': integerResult = 14; break;
        case 'F': integerResult = 15; break;
        default: integerResult = givenChar - '0';
    }
    return integerResult;
}
char getCharacterEquivalent(int givenDecimal){
    //step 1: prepare variable
    char charResult;
    //step 2: switch through available equivalent
    switch(givenDecimal){
        case 10: charResult = 'A';break;
        case 11: charResult = 'B';break;
        case 12: charResult = 'C';break;
        case 13: charResult = 'D';break;
        case 14: charResult = 'E';break;
        case 15: charResult = 'F';break;
        default : charResult = givenDecimal + '0';
    }
    //step 3: return charResult
    return charResult;
}
int convertBinaryToDecimal(string givenBinary){
    //step 1: prepare variables
    int decimalValue = 0;
    int bitValue = 1;

    //step 2: loop through the givenBinary
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 3: if givenBinary Character is 1, add the bitValue of it to decimalValue
        if(givenBinary[i] == '1'){
            decimalValue+=bitValue;
        }
        //step 4: multiply by 2 the bitValue every iteration
        bitValue*=2;
    }
    //step 3: return decimalValue
    return decimalValue;
}
string convertBinaryToHex(string givenBinary){
    //step 0: preapre hexResult;
    string hexResult = "";
    //step 1: prepare array container for splitting the givenBinary
    int quotientResult = givenBinary.length()/4;
    int moduloResult = givenBinary.length()%4;
    int arraySize = quotientResult + moduloResult;
    string hexArrayContainer[arraySize];

    //step 2: loop through givenBinary
    int hexArrayIndex = arraySize-1;
    for(int i=givenBinary.length() - 1; i>=0;i--){
        //step 3: concatenate the givenBinaryBit to hexArrayContainer when length is not yet 3
        if(hexArrayContainer[hexArrayIndex].length()!=4){
            hexArrayContainer[hexArrayIndex]+=givenBinary[i];
        }else{
            //step 4: when max length per octalArray Element has reached 3, move to the next element and insert the bit
            hexArrayIndex--;
            hexArrayContainer[hexArrayIndex]+=givenBinary[i];
        }
    }

    //step 5: loop through hexArrayContainer
    for(int i=0;i<arraySize; i++){
        //step 6: add zeroes to elements that has less than 3 of length
        if(hexArrayContainer[i].length()!=4){
            int neededZeroes = 4-hexArrayContainer[i].length();
            for(int j=1;j<=neededZeroes;j++){
                hexArrayContainer[i]+='0';
            }
        }
        //step 7: reorder the bits in each hexArrayContainer so that it can be converted accurately
        //example [1000][1000][1000] will become [0001][0001][0001]
        string temporary="";
        for(int k=3;k>=0;k--){
            temporary+=hexArrayContainer[i][k];
        }
        hexArrayContainer[i] = temporary;
        //step 8: convert each element to decimal
        int decimalValue = convertBinaryToDecimal(hexArrayContainer[i]);
        //step 9: convert each decimal to character
        char characterValue = getCharacterEquivalent(decimalValue);
        //step 10: concatenate the result to the binaryResult
        hexResult+=characterValue;
    }
    return hexResult;
}
string convertBinaryToOctal(string givenBinary){
    //step 0: preapre octalREsult;
    string octalResult = "";
    //step 1: prepare array container for splitting the givenBinary
    int quotientResult = givenBinary.length()/3;
    int moduloResult = givenBinary.length()%3;
    int arraySize = quotientResult + moduloResult;
    string octalArrayContainer[arraySize];

    //step 2: loop through givenBinary
    int octalArrayIndex = arraySize-1;
    for(int i=givenBinary.length() - 1; i>=0;i--){
        //step 3: concatenate the givenBinaryBit to octalArrayElement when length is not yet 3
        if(octalArrayContainer[octalArrayIndex].length()!=3){
            octalArrayContainer[octalArrayIndex]+=givenBinary[i];
        }else{
            //step 4: when max length per octalArray Element has reached 3, move to the next element and insert the bit
            octalArrayIndex--;
            octalArrayContainer[octalArrayIndex]+=givenBinary[i];
        }
    }

    //step 5: loop through octalArrayContainer
    for(int i=0;i<arraySize; i++){
        //step 6: add zeroes to elements that has less than 3 of length
        if(octalArrayContainer[i].length()!=3){
            int neededZeroes = 3-octalArrayContainer[i].length();
            for(int j=1;j<=neededZeroes;j++){
                octalArrayContainer[i]+='0';
            }
        }
        //step 7: reorder the bits in each octalArrayElement so that it can be converted accurately
        //example [100][100][100] will become [001][001][001]
        string temporary="";
        for(int k=2;k>=0;k--){
            temporary+=octalArrayContainer[i][k];
        }
        octalArrayContainer[i] = temporary;
        //step 8: convert each element to decimal
        int decimalValue = convertBinaryToDecimal(octalArrayContainer[i]);
        //step 9: convert each decimal to character
        char characterValue = decimalValue + '0';
        //step 10: concatenate the result to the binaryResult
        octalResult+=characterValue;
    }
    return octalResult;
}
string convertDecimalToBinary(int decimal){
    //step 1: prepare variables
    int bitValue = 1;
    string binaryResult = "";

    //step 2: check if decimal needs converting
    if(decimal == 0){
        binaryResult+='0';
        return binaryResult;
    }

    //step 3: determine highest comparable bitValue for the decimal
    while (bitValue <= decimal){
        bitValue*=2;
    }
    //step 4: go back one bitValue for accurate result
    bitValue/=2;

    //step 5: loop until bitValue is zero
    while(bitValue!=0){
        //step 6: concatenate 1 to binaryResult if binary is greater or equal to bitValue and deduct bitValue from decimal
        if(decimal >= bitValue){
            binaryResult += '1';
            decimal-=bitValue;
        }else{
            //step 7: concatenate 0 if decimal is lesser than bitValue
            binaryResult += '0';
        }
        //step 8: divide by 2 bitValue every iteration
        bitValue/=2;
    }

    //step 9: return binaryResult
    return binaryResult;
}
string convertOctalToBinary(string givenOctal){
    //step 0: prepare binaryResult
    string completeBinaryResult = "";
    //step 1: loope through givenOctal
    for(int i=0;i<givenOctal.length();i++){
        //step 2: convert each octal element to integer
        int integerResult = givenOctal[i] - '0';
        //step 2: convert each integerResult to its binary value
        string binaryResult = convertDecimalToBinary(integerResult);
        //step 3: make sure each binaryResult has length of 3, if not add leading zeroes
        if(binaryResult.length() != 3){
            int neededZeroes = 3 - binaryResult.length();
            string temporary = "";
            for(int j=1;j<=neededZeroes;j++){
                temporary+='0';
            }
            temporary+=binaryResult;
            binaryResult = temporary;
        }
        //step 4: concatenate to completeBinaryResult each binaryResult
        completeBinaryResult+=binaryResult;
    }
    //step 5: return completeBinaryResult
    return completeBinaryResult;
}
string convertHexToBinary(string givenHex){
    //step 1: prepare completeBinaryResult
    string completeBinaryResult = "";
    //step 2: loop through the given hex
    for(int i=0;i<givenHex.length();i++){
        //step 3: convert each element to integer
        int integerResult = getIntegerEquivalent(givenHex[i]);
        //step 4: convert each decimal to binary
        string binaryResult = convertDecimalToBinary(integerResult);
        //step 5: make sure each element has a length of 4, if not add leading zeroes
        if(binaryResult.length() !=4 ){
            int neededZeroes = 4-binaryResult.length();
            string temporary = "";
            for(int j=1;j<=neededZeroes;j++){
                temporary+='0';
            }
            temporary+=binaryResult;
            binaryResult=temporary;
        }
        //step 6: concatenate to complateBinaryResult;
        completeBinaryResult+=binaryResult;
    }
    //step 7: return result
    return completeBinaryResult;
}
void clearScreen(){
    system("cls");
    return;
}
void saveResults(ObjectToSave objectGiven){
    //step 1: preapre object of file stream
    fstream appendToFile;
    //step 2: check if fs works
    appendToFile.open("results.txt",ios::app);
    if(!appendToFile.is_open()){
        cout << "Unable to save to results.txt" << endl;
        return;
    }
    //step 3: do the appending
    appendToFile << objectGiven.title << endl;
    appendToFile << "GIVEN IS: " << objectGiven.given << endl;
    appendToFile << objectGiven.decimalValue << endl;
    appendToFile << objectGiven.binaryValue << endl;
    appendToFile << objectGiven.octalValue << endl;
    appendToFile << objectGiven.hexValue << endl;

    //step 4: close the fstream object
    cout << "Saving was successful to results.txt" << endl;
    appendToFile.close();
    return;
}
void runDecimalConversion(){
    //step 1: clear screen, show title
    clearScreen();
    string title = "===DECIMAL CONVERSION===";
    cout << title << endl;

    //step 2: ask for user input
    cout << "Enter your Decimal" << endl;
    int decimal;
    cin >> decimal;

    //step 3: do conversions of binary, octal and hexadecimal
    string binaryResult = convertDecimalToBinary(decimal);
    string octalResult = convertBinaryToOctal(binaryResult);
    string hexResult = convertBinaryToHex(binaryResult);
    //show results
    cout << "BINARY VALE : " << binaryResult << endl;
    cout << "OCTAL VALUE: " << octalResult << endl;
    cout << "HEX RESULT: " << hexResult << endl;
    cout << endl << endl;
    //step 5: create a struct variable for the result
    ObjectToSave decimalConverted;
    decimalConverted.title = "===DECIMAL CONVERSION RESULTS===";
    decimalConverted.given = to_string(decimal);
    decimalConverted.decimalValue = decimal;
    decimalConverted.binaryValue = binaryResult;
    decimalConverted.octalValue = octalResult;
    decimalConverted.hexValue = hexResult;

    //step 6: append to saveResults
    saveResults(decimalConverted);
    return;
}
void runBinaryConversion(){
    //step 1: clear screen, show title
    clearScreen();
    string title = "===BINARY CONVERSION===";
    cout << title << endl;

    //step 2: ask for user input
    string givenBinary;
    cout << "Enter your Binary" << endl;
    cin >> givenBinary;
    //step 3: do conversions
    int decimalResult = convertBinaryToDecimal(givenBinary);
    string octalResult = convertBinaryToOctal(givenBinary);
    string hexResult = convertBinaryToHex(givenBinary);
    //show results
    cout << "DECIMAL VALE : " << decimalResult << endl;
    cout << "OCTAL VALUE: " << octalResult << endl;
    cout << "HEX RESULT: " << hexResult << endl;
    cout << endl << endl;
    //step 5: create a struct variable for the result
    ObjectToSave binaryConverted;
    binaryConverted.title = "===BINARY CONVERSION RESULTS===";
    binaryConverted.given = givenBinary;
    binaryConverted.decimalValue = decimalResult;
    binaryConverted.binaryValue = givenBinary;
    binaryConverted.octalValue = octalResult;
    binaryConverted.hexValue = hexResult;

    //step 6: append to saveResults
    saveResults(binaryConverted);
    return;
}
void runOctalConversion(){
    //step 1: clear screen and show title
    clearScreen();
    string title = "===OCTAL CONVERSION===";
    cout << title << endl;

    //step 2: obtain octal input of user
    string givenOctal;
    cout << "Enter your octal value" << endl;
    cin >> givenOctal;

    //step 3: do conversions
    string binaryResult = convertOctalToBinary(givenOctal);
    int decimalResult = convertBinaryToDecimal(binaryResult);
    string hexResult = convertBinaryToHex(binaryResult);
    //show results
    cout << "DECIMAL VALE : " << decimalResult << endl;
    cout << "BINARY VALUE: " << binaryResult << endl;
    cout << "HEX RESULT: " << hexResult << endl;
    cout << endl << endl;
    //step 5: create a struct variable for the result
    ObjectToSave octalConverted;
    octalConverted.title = "===OCTAL CONVERSION RESULTS===";
    octalConverted.given = givenOctal;
    octalConverted.decimalValue = decimalResult;
    octalConverted.binaryValue = binaryResult;
    octalConverted.octalValue = givenOctal;
    octalConverted.hexValue = hexResult;

    //step 6: append to saveResults
    saveResults(octalConverted);
    return;
}
void runHexConversion(){
    //step 1: clear screen and show title
    clearScreen();
    string title = "===HEX CONVERSION===";
    cout << title << endl;

    //step 2: accept user input
    string givenHex;
    cout << "Enter your Hex" << endl;
    cin >> givenHex;

    //step 3: do conversions
    string binaryResult = convertHexToBinary(givenHex);
    int decimalResult = convertBinaryToDecimal(binaryResult);
    string octalResult = convertBinaryToOctal(binaryResult);
    //show results
    cout << "BINARY VALE : " << binaryResult << endl;
    cout << "DECIMAL VALUE: " << decimalResult << endl;
    cout << "OCTAL RESULT: " << octalResult << endl;
    cout << endl << endl;

    //step 5: create a struct variable for the result
    ObjectToSave hexConverted;
    hexConverted.title = "===HEX CONVERSION RESULTS===";
    hexConverted.given = givenHex;
    hexConverted.decimalValue = decimalResult;
    hexConverted.binaryValue = binaryResult;
    hexConverted.octalValue = octalResult;
    hexConverted.hexValue = givenHex;

    //step 6: append to saveResults
    saveResults(hexConverted);
    return;
}
void showOptions(){
    string header = "===Number System Conversion===";
    string instruction = "Choose your option";
    string footer = "==============================";
    cout << header << endl;
    cout << instruction << endl;
    cout << "1: Convert my Decimal" << endl;
    cout << "2: Convert my Binary" << endl;
    cout << "3: Convert my Octal" << endl;
    cout << "4: Convert my Hexadecimal" << endl;
    cout << "0: Exit" << endl;
    cout << footer << endl;
}
void showAuther(){
    string author = "Ramelito N: Martinez";
    string purpose = "EDPSE Mock Exam";
    cout << author << endl;
    cout << purpose << endl;
}
void runApplication(){
    showAuther();
    showOptions();
    char option;
    do{
        cin >> option;
        while(isalpha(option)){
            cout << "That is not a number!" << endl;
            cin >> option;
        }

        switch(option){
        case '0':
            cout << "Thank you for using this Application!" << endl;
            break;
        case '1':
            runDecimalConversion();
            showOptions();
            break;
        case '2':
            runBinaryConversion();
            showOptions();
            break;
        case '3':
            runOctalConversion();
            showOptions();
            break;
        case '4':
            runHexConversion();
            showOptions();
            break;
        default:
            cout << "That is not in the options" << endl;
            break;
        }
    }while(option != '0');
    return;
}

int main(){
    runApplication();
return 0;
}
