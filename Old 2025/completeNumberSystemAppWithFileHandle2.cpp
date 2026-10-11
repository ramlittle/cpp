/*
    Author: Ramelito N. Martinez
    Purpose: Mock Exam for EDPSE

*/

#include <iostream>
#include <fstream>
using namespace std;

struct ResultObject{
    string category;
    string given;
    int decimalResult;
    string binaryResult;
    string octalResult;
    string hexResult;
};

void saveResult(ResultObject results){
    //step 1: prepare file stream object
    fstream appendResults;
    appendResults.open("results.txt",ios::app);
    //step 2: test filestream
    if(!appendResults.is_open()){
        cout << "Sorry, unable to append to file" << endl;
        return;
    }
    //step 3: save results
    appendResults << "CATEGORY : " << results.category << endl;
    appendResults << "GIVEN : " << results.given << endl;
    appendResults << "DECIMAL RESULT: " << results.decimalResult << endl;
    appendResults << "BINARY RESULT: " << results.binaryResult << endl;
    appendResults << "OCTAL RESULT: " << results.octalResult << endl;
    appendResults << "HEX RESULT: " << results.hexResult << endl;

    //step 4: close the file
    cout << "Saving successful. Please check the results.txt file for reference" << endl;
    appendResults.close();
}
char getCharacterEquivalent(int givenDecimal){
    //step 1: prepare result variable1
    char result;
    //step 2: switch through the given options
    switch(givenDecimal){
        case 10: result = 'A';break;
        case 11: result = 'B';break;
        case 12: result = 'C';break;
        case 13: result = 'D';break;
        case 14: result = 'E';break;
        case 15: result = 'F';break;
        default : result = givenDecimal + '0';
    }
    //step 3: return result
    return result;
}

int getNumberEquivalent(char givenCharacter){
    //step 1: prepare result
    int result;
    //step 2: switch through the available options
    switch(givenCharacter){
        case 'A' : result = 10; break;
        case 'B' : result = 11; break;
        case 'C' : result = 12; break;
        case 'D' : result = 13; break;
        case 'E' : result = 14; break;
        case 'F' : result = 15; break;
        default : result = givenCharacter - '0';
    }
    //step 3: return result
    return result;

}
int convertBinaryToDecimal(string givenBinary){
    //step 1: prepare variables
    int bitValue = 1;
    int decimalResult = 0;
    //step 2: loop through givenBinary
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 3: if bit is 1, add it's bitValue to decimalResult
        if(givenBinary[i] == '1'){
            decimalResult+=bitValue;
        }
        //step 4: multiply by 2 the bitValue each iteration
        bitValue*=2;
    }
    //step 5: return the result
    return decimalResult;
}
string convertBinaryToOctalOrHex(string givenBinary, string mode){
    //step 0: prepare result variable
    string finalResult="";
    //step 1: choose mode
    int modeValue;
    if(mode == "useOctal"){
        modeValue = 3; // for octal conversion
    }else if(mode == "useHex"){
        modeValue = 4; // for hex conversion
    }
    //step 2: prepare array container
    int quotientResult = givenBinary.length()/modeValue;
    int moduloResult = givenBinary.length()%modeValue;
    int arraySize = quotientResult+moduloResult;
    string arrayContainer[arraySize];

    //step 3: loop through the givenBinary in reverse
    int arrayIndex = arraySize-1; //array index for arrayContainer
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 4: insert every bit to the arrayContainer starting from the last element of arrayContainer until each element has a length equal to modeValue
        if(arrayContainer[arrayIndex].length()!=modeValue){
            arrayContainer[arrayIndex]+=givenBinary[i];
        }else{
            //step 5: if length is already maxxed, move to the next element
            //then insert the bit accordingly
            arrayIndex--;
            arrayContainer[arrayIndex]+=givenBinary[i];
        }
    }
    //step 6: loop through the arrayContainer
    for(int i=0;i<arraySize;i++){
        //step 7: check if the length of each element is ok
        //octal = 3 length, hex = 4 length
        if(arrayContainer[i].length()!=modeValue){
            int neededZeroes = modeValue - arrayContainer[i].length();
            for(int j=1;j<=neededZeroes;j++){
                arrayContainer[i]+='0';
            }
        }
        //step 8: reorder the bits inside each element
        //example givenBinary = 1001001, when it was inserted and had padded leading zeros to the array container
        //it became [100][100][100], goal is to make it like this [001][001][001]
        string temporary="";
        for(int k=modeValue-1;k>=0;k--){
            temporary += arrayContainer[i][k];
        }
        arrayContainer[i] = temporary;
        //step 9: convert to integer
        int decimalValue = convertBinaryToDecimal(arrayContainer[i]);
        //step 10: concatenate to finalResult
        if(mode == "useHex"){
            finalResult+=getCharacterEquivalent(decimalValue);
        }else{
            finalResult+=decimalValue+'0';
        }
    }
    return finalResult;
}
string convertToBinary(int givenDecimal){
    //step 1: prepare variables
    string binaryResult="";
    int bitValue = 1;
    //step 2: determine highest bitValue
    while(bitValue<=givenDecimal){
        bitValue*=2;
    }
    //step 3: go down one bit value
    bitValue/=2;
    //step 4: loop through until bitValue is zero
    while(bitValue!=0){
        //step 5: when givenDecimal is greater or equal to bitValue, concat 1 to binaryResult
        if(givenDecimal>=bitValue){
            binaryResult+='1';
            givenDecimal-=bitValue;
        //step 6: if not concatenate 0 to binaryResult
        }else{
            binaryResult+='0';
        }
        //step 7: divide bitValue by 2 every iteration
        bitValue/=2;
    }
    //step 8: return binaryResult
    return binaryResult;
}

string convertOctalOrHexToBinary(string given, string mode){
    //step 1: determine max length of binary base on mode
    int maxLength = 0;
    if(mode == "useOctal"){
        maxLength = 3;
    }else if(mode == "useHex"){
        maxLength = 4;
    }
    string result = "";
    //step 1: loop through the given
    for(int i=0;i<given.length();i++){
        //step 2: convert each character to int
        int number;
        if(mode == "useOctal"){
            number = given[i] - '0';
        }else if(mode == "useHex"){
            number = getNumberEquivalent(given[i]);
        }
        //step 2: convert each character to binary
        string binaryValue = convertToBinary(number);
        //step 3: add leading zeroes if maxLength for binaryValue is not met
        if(binaryValue.length() != maxLength){
            int neededZeroes = maxLength - binaryValue.length();
            string temporary="";
            for(int j=1;j<=neededZeroes;j++){
                temporary+='0';
            }
            temporary+=binaryValue;
            binaryValue = temporary;
        }
        //step 4: concat the result to result
        result+=binaryValue;
    }
    return result;

}
bool isValidDecimal(string givenDecimal){
    for(int i=0;i<givenDecimal.length();i++){
        if(isalpha(givenDecimal[i])){
            return false;
        }
    }
    return true;
}


void runDecimalConversion(){
    //step 1: show title
    cout << "DECIMAL CONVERSION" << endl;
    //step 2: ask for user input
    cout << "Enter your number" << endl;
    string decimal;
    cin >> decimal;
    //step 3: validate input
    while(!isValidDecimal(decimal)){
        cout << "That is not a valid Decimal" << endl;
        cin >> decimal;
    }
    //step 4: do conversions
    string binaryResult = convertToBinary(stoi(decimal));
    string octalResult = convertBinaryToOctalOrHex(binaryResult,"useOctal");
    string hexResult = convertBinaryToOctalOrHex(binaryResult,"useHex");
    //step 5: show results
    cout << "BINARY RESULT " << binaryResult << endl;
    cout << "OCTAL RESULT " << octalResult << endl;
    cout << "HEX RESULT " << hexResult << endl;
    //step 6: save results
    ResultObject results;
    results.category = "DECIMAL CONVERSION";
    results.given = decimal;
    results.decimalResult = stoi(decimal);
    results.binaryResult = binaryResult;
    results.octalResult = octalResult;
    results.hexResult = hexResult;
    saveResult(results);
}

bool isValidBinary(string givenBinary){
    //step 1: loop through the givenBinary
    for(int i=0;i<givenBinary.length();i++){
        //step 2: return false if bits are not valid
        if(givenBinary[i] != '0'){
            if(givenBinary[i] != '1'){
                return false;
            }
        }
    }
    //step 3: return true if all good
    return true;
}
void runBinaryConversion(){
    //step 1: show title
    cout << "BINARY CONVERSION" << endl;
    //step 2: ask for user input
    cout << "Enter your Binary" << endl;
    string binary;
    cin >> binary;
    //step 3: validate input
    while(!isValidBinary(binary)){
        cout << "That is not a valid Binary. Try again!" << endl;
        cin >> binary;
    }
    //step 4: do conversions
    int decimalResult = convertBinaryToDecimal(binary);
    string octalResult = convertBinaryToOctalOrHex(binary,"useOctal");
    string hexResult = convertBinaryToOctalOrHex(binary,"useHex");
    //step 5: show results
    cout << "DECIMAL RESULT " << decimalResult << endl;
    cout << "OCTAL RESULT " << octalResult << endl;
    cout << "HEX RESULT " << hexResult << endl;
    //step 6: save results
    ResultObject results;
    results.category = "BINARY CONVERSION";
    results.given = binary;
    results.decimalResult = decimalResult;
    results.binaryResult = binary;
    results.octalResult = octalResult;
    results.hexResult = hexResult;
    saveResult(results);
}

bool isValidOctal(string givenOctal){
    //step 1: loop through givenOctal
    for(int i=0;i<givenOctal.length();i++){
        //step 2: convert octal character to digit
        int number = givenOctal[i] - '0';
        //step 3: return false when a number is greater than 7
        if(number > 7){
            return false;
        }
    }
    //step 4: return true if all is well;
    return true;
}
void runOctalConversion(){
    //step 1: show title
    cout << "OCTAL CONVERSION" << endl;
    //step 2: get user input
    cout << "Enter your Octal" << endl;
    string octal;
    cin >> octal;
    //step 3: validate input
    while(!isValidOctal(octal)){
        cout << "That is not a valid octal number. Try again!" << endl;
        cin >> octal;
    }
    //step 4: do conversions
    string binaryResult = convertOctalOrHexToBinary(octal,"useOctal");
    int decimalResult = convertBinaryToDecimal(binaryResult);
    string hexResult = convertBinaryToOctalOrHex(binaryResult,"useHex");
    //step 5: show result
    cout << "BINARY RESULT " << binaryResult << endl;
    cout << "DECIMAL RESULT " << decimalResult << endl;
    cout << "HEX RESULT " << hexResult << endl;
    ResultObject results;
    results.category = "OCTAL CONVERSION";
    results.given = octal;
    results.decimalResult = decimalResult;
    results.binaryResult = binaryResult;
    results.octalResult = octal;
    results.hexResult = hexResult;
    saveResult(results);
}

bool isValidHex(string givenHex){
    //step 1: loop through givenHex
    for(int i =0;i<givenHex.length();i++){
        //step 2: convert each character to integer
        int number = getNumberEquivalent(givenHex[i]);
        //step 3: check if the character is greater than 15
        if(number>15){
            return false;
        }
    }
    //step 4: return true if all is well
    return true;
}
void runHexConversion(){
    //step 1: show title
    cout << "HEX CONVERSION" << endl;
    //step 2: ask user input
    cout << "Enter your Hex" << endl;
    string hex;
    cin >> hex;
    //step 3: validate input
    while(!isValidHex(hex)){
        cout << "That is not a valid Hex! Try Again!" << endl;
        cin >> hex;
    }
    //step 4: do conversions
    string binaryResult = convertOctalOrHexToBinary(hex,"useHex");
    int decimalResult = convertBinaryToDecimal(binaryResult);
    string octalResult = convertBinaryToOctalOrHex(binaryResult,"useOctal");
    //step 5: show results
    cout << "BINARY RESULT " << binaryResult << endl;
    cout << "DECIMAL RESULT " << decimalResult << endl;
    cout << "OCTAL RESULT " << octalResult << endl;
    //step 6: save results
    ResultObject results;
    results.category = "HEX CONVERSION";
    results.given = hex;
    results.decimalResult = decimalResult;
    results.binaryResult = binaryResult;
    results.octalResult = octalResult;
    results.hexResult = hex;
    saveResult(results);
}

void showDivider(){
    cout << "==============================" << endl;
}

void clearScreen(){
    system("cls");
}

void showMenu(){
    cout << "NUMBER SYSTEM" << endl;
    cout << "Select an option" << endl;
    cout << "1: Decimal Conversion" << endl;
    cout << "2: Binary Conversion" << endl;
    cout << "3: Octal Conversion" << endl;
    cout << "4: Hex Conversion" << endl;
    cout << "0: Exit" << endl;
}

void showAuthor(){
    string author = "Ramelito N. Martinez";
    string purpose = "Mock Exam for EDPSE";
    cout << author << endl;
    cout << purpose << endl;
}

void readOnlyOneCharacter(){
    cin.ignore(1000,'\n');
}
void acceptAnOption(){
    char option;
    do{
        cin >> option;
        readOnlyOneCharacter();
        while(isalpha(option)){
            cout << "That is not a number! Try again!" << endl;
            cin >> option;
            readOnlyOneCharacter();
        }
        switch(option){
        case '0':
            clearScreen();
            cout << "Thank you for using this application" << endl;
            break;
        case '1':
            clearScreen();
            runDecimalConversion();
            showDivider();
            showMenu();
            break;
        case '2':
            clearScreen();
            runBinaryConversion();
            showDivider();
            showMenu();
            break;
        case '3':
            clearScreen();
            runOctalConversion();
            showDivider();
            showMenu();
            break;
        case '4':
            clearScreen();
            runHexConversion();
            showDivider();
            showMenu();
            break;
        default:
            cout << "That is not in the options. Try AGAIN!" << endl;
            break;
        }
    }while(option!='0');
}
void runApplication(){
    showDivider();
    showAuthor();
    showDivider();
    showMenu();
    acceptAnOption();
}

int main(){
    runApplication();
return 0;
}
