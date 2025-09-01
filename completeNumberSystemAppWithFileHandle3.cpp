/*
    Author: Ramelito Martinez
    purpose: MOCK EXAM EDPSE
*/
#include <iostream>
using namespace std;

int getIntegerEquivalent(char givenCharacter){
    int result;
    switch(givenCharacter){
        case 'A': result = 10;break;
        case 'B': result = 11;break;
        case 'C': result = 12;break;
        case 'D': result = 13;break;
        case 'E': result = 14;break;
        case 'F': result = 15;break;
        default : result = givenCharacter - '0';
    }
    return result;
}
char getCharacterEquivalent(int givenInteger){
    char result;
    switch(givenInteger){
        case 10: result = 'A';break;
        case 11: result = 'B';break;
        case 12: result = 'C';break;
        case 13: result = 'D';break;
        case 14: result = 'E';break;
        case 15: result = 'F';break;
        default : result = givenInteger + '0';
    }
    return result;
}
int convertBinaryToDecimal(string givenBinary){
    int decimalResult = 0;
    int bitValue =1;
    for(int i=givenBinary.length()-1;i>=0;i--){
        if(givenBinary[i] == '1'){
            decimalResult+=bitValue;
        }
        bitValue*=2;
    }

    return decimalResult;
}
string convertDecimalToBinary(string givenDecimal){
    int decimal = stoi(givenDecimal);
    int bitValue = 1;
    string binaryResult = "";

    while(decimal >= bitValue){
        bitValue*=2;
    }
    bitValue/=2;

    while(bitValue!=0){
        if(decimal >= bitValue){
            binaryResult+='1';
            decimal-=bitValue;
        }else{
            binaryResult+='0';
        }
        bitValue/=2;
    }
    return binaryResult;
}
string convertBinaryToOctalOrHex(string givenBinary, string mode){
    string result="";
    int binaryReference = 0;
    if(mode == "octal"){
        binaryReference = 3;
    }
    if(mode == "hex"){
        binaryReference = 4;
    }
    int quotientResult = givenBinary.length() / binaryReference;
    int moduloResult = givenBinary.length() % binaryReference;
    int arrayLength = quotientResult + moduloResult;
    string arrayContainer[arrayLength];
    int arrayElement = arrayLength-1;
    for(int i = givenBinary.length()-1;i>=0;i--){
        if(arrayContainer[arrayElement].length() >= binaryReference){
            arrayElement--;
            arrayContainer[arrayElement]+=givenBinary[i];
        }else{
            arrayContainer[arrayElement]+=givenBinary[i];
        }
    }
    //reverse the characters in the array elements
    for(int i=0;i<arrayLength;i++){
        if(arrayContainer[i].length() != binaryReference){
            int neededZeroes = binaryReference - arrayContainer[i].length();
            for(int j=1;j<=neededZeroes;j++){
                arrayContainer[i]+='0';
            }
        }
        //reverse the contents
        string temporary="";
        for(int k=binaryReference;k>=0;k--){
            temporary+=arrayContainer[i][k];
        }
        arrayContainer[i]=temporary;
        //convert
        char charResult;
        int numericalValue=convertBinaryToDecimal(arrayContainer[i]);
        int decimalResult = numericalValue;
        if(mode == "octal"){
            charResult = decimalResult+'0';
        }
        if(mode == "hex"){
            charResult = getCharacterEquivalent(numericalValue);
        }
        result+=charResult;
    }
    return result;
}
string convertOctalOrHexToBinary(string given,string mode){
    string result="";
    int binaryReference;
    if(mode == "octal"){
        binaryReference = 3;
    }
    if(mode == "hex"){
        binaryReference = 4;
    }
    for(int i=0;i<given.length();i++){
        string decimalValue = "";
        int integerValue = getIntegerEquivalent(given[i]);
        decimalValue+=to_string(integerValue);
        string binaryValue = convertDecimalToBinary(decimalValue);
        string temporary=binaryValue;
        if(binaryValue.length()!=binaryReference){
            int neededZeroes = binaryReference - binaryValue.length();
            temporary="";
            for(int j=1;j<=neededZeroes;j++){
                temporary+='0';
            }
            temporary+=binaryValue;
        }
        result+=temporary;
    }
    return result;
}
bool isValidDecimal(string decimal){
    int counter = 0;
    for(int i=0;i<decimal.length();i++){
        if(!isdigit(decimal[i])){
            counter++;
        }
    }
    if(counter > 0){
        return false;
    }
    return true;
}
bool isValidBinary(string givenBinary){
    for(int i=0;i<givenBinary.length();i++){
        if(isalpha(givenBinary[i]) || givenBinary[i]-'0' > 1){
            return false;
        }
    }
    return true;
}
bool isValidOctal(string givenOctal){
    int octalValueLimit=7;
    for(int i=0;i<givenOctal.length();i++){
        if(isalpha(givenOctal[i])){
           return false;
        }
        int integerValue = givenOctal[i] - '0';
        if(integerValue > octalValueLimit){
            return false;
        }
    }
    return true;
}
bool isValidHex(string givenHex){
    int hexValueLimit=15;
    for(int i=0;i<givenHex.length();i++){
        int integerValue = getIntegerEquivalent(givenHex[i]);
        if(integerValue > 15){
            return false;
        }
    }
    return true;
}
void runDecimalConversion(){
    string title = "DECIMAL CONVERSION";
    cout << title << endl;
    string decimal;
    cout << "Enter a number greater than zero" << endl;
    cin >> decimal;
    while(!isValidDecimal(decimal)){
        cout << "That is not a valid integer. Try Again!" << endl;
        cin >> decimal;
    }
    string binaryResult=convertDecimalToBinary(decimal);
    string octalResult=convertBinaryToOctalOrHex(binaryResult,"octal");
    string hexResult=convertBinaryToOctalOrHex(binaryResult,"hex");

    cout << "BINARY RESULT : " << binaryResult << endl;
    cout << "OCTAL RESULT : " << octalResult << endl;
    cout << "HEX RESULT : " << hexResult << endl;
}
void runBinaryConversion(){
    string title = "BINARY CONVERSION";
    cout << title << endl;
    string binary;
    cout << "Enter your binary" << endl;
    cin >> binary;
    while(!isValidBinary(binary)){
        cout << "That is not a valid binary. Try again!"<< endl;
        cin >> binary;
    }
    int decimalResult = convertBinaryToDecimal(binary);
    string octalResult = convertBinaryToOctalOrHex(binary,"octal");
    string hexResult = convertBinaryToOctalOrHex(binary,"hex");
    cout << "DECIMAL RESULT : " << decimalResult << endl;
    cout << "OCTAL RESULT : " << octalResult << endl;
    cout << "HEX RESULT : " << hexResult << endl;
}
void runOctalConversion(){
    string title = "OCTAL CONVERSION";
    cout << title << endl;
    string octal;
    cout << "Enter your octal value" << endl;
    cin >> octal;
    while(!isValidOctal(octal)){
        cout << "That is not a valid Octal. Try Again!"<< endl;
        cin >> octal;
    }
    string binaryResult = convertOctalOrHexToBinary(octal,"octal");
    int decimalResult = convertBinaryToDecimal(binaryResult);
    string hexResult = convertBinaryToOctalOrHex(binaryResult,"hex");
    cout << "BINARY RESULT : " << binaryResult << endl;
    cout << "DECIMAL RESULT : " << decimalResult << endl;
    cout << "HEX RESULT : " << hexResult << endl;
}
void runHexConversion(){
    string title = "HEX CONVERSION";
    cout << title << endl;
    string hex;
    cout << "Enter your hex" << endl;
    cin >> hex;
    while(!isValidHex(hex)){
        cout << "That is not a valid Hex. Try again!" << endl;
        cin >> hex;
    }
    string binaryResult = convertOctalOrHexToBinary(hex, "hex");
    int decimalResult = convertBinaryToDecimal(binaryResult);
    string octalResult = convertBinaryToOctalOrHex(binaryResult, "octal");
    cout << "BINARY RESULT : " << binaryResult << endl;
    cout << "DECIMAL RESULT : " << decimalResult << endl;
    cout << "OCTAL RESULT : " << octalResult << endl;
}
void showDivider(){
    cout << "================================" << endl;
}
void ignoreOtherCharacters(){
    int limit = 1000;
    cin.ignore(limit,'\n');
}
void showAppTitle(){
    string title = "Number System";
    cout << "Title: " << title << endl;
}
void showAuthor(){
    string author = "Ramelito N. Martinez";
    cout << "Author : " << author << endl;
}
void clearScreen(){
    system("cls");
}
void showOptions(){
    cout << "Select an option" << endl;
    cout << "1: run Decimal Conversion" << endl;
    cout << "2: run Binary Conversion" << endl;
    cout << "3: run Octal Conversion" << endl;
    cout << "4: run Hex Conversion" << endl;
    cout << "0: Exit" << endl;
}
void acceptUserOption(){
    char option;
    do{
        cin >> option;
        ignoreOtherCharacters();
        while(isalpha(option)){
            cout << "That is not a number! Try again" << endl;
            cin >> option;
            ignoreOtherCharacters();
        }
        switch(option){
        case '0':
            cout << "Thank you for using this application" << endl;
            break;
        case '1':
            clearScreen();
            showDivider();
            runDecimalConversion();
            showDivider();
            showOptions();
            break;
        case '2':
            clearScreen();
            showDivider();
            runBinaryConversion();
            showDivider();
            showOptions();
            break;
        case '3':
            clearScreen();
            showDivider();
            runOctalConversion();
            showDivider();
            showOptions();
            break;
        case '4':
            clearScreen();
            showDivider();
            runHexConversion();
            showDivider();
            showOptions();
            break;
        default:
            cout << "That is not in the options. Try Again!" << endl;
            break;
        }
    }while(option!='0');
}
void runApplication(){
    showDivider();
    showAppTitle();
    showAuthor();
    showDivider();
    showOptions();
    showDivider();
    acceptUserOption();
}
int main(){
    runApplication();
return 0;
}
