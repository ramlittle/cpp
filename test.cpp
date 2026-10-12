#include <iostream>
#include <string>
using namespace std;

void showDivider(){
    cout << "==================================" << endl;
}

char getCharacterValue(int givenDecimal){
    char result = givenDecimal + '0';
    switch(givenDecimal){
        case 10: result = 'A';break;
        case 11: result = 'B';break;
        case 12: result = 'C';break;
        case 13: result = 'D';break;
        case 14: result = 'E';break;
        case 15: result = 'F';break;
        default: ;break;
    }
    return result;
}

int convertBinaryToDecimal(string givenBinary){
    int result = 0;
    int bitValue = 1;
    for(int i=givenBinary.length()-1;i>=0;i--){
        if(givenBinary[i] == '1'){
            result+=bitValue;
        }
        bitValue*=2;
    }
    return result;
}
string convertBinaryToOctalorHex(string givenBinary,int limit){
    string result = "";
    //get size of container
    int quotient = givenBinary.length()/limit;
    int modulo = givenBinary.length()%limit > 0 ? 1:0;
    int arraySize = quotient + modulo;
    string arrayContainer[arraySize];

    //split the length of given Binary based on limit
    int arrayIndex = arraySize - 1;
    for(int i=givenBinary.length()-1;i>=0;i--){
        if(arrayContainer[arrayIndex].length()!=limit){
            arrayContainer[arrayIndex]+=givenBinary[i];
        }else{
            arrayIndex--;
            arrayContainer[arrayIndex]+=givenBinary[i];
        }
    }

    //loop through the arrayContainer
    for(int i=0;i<arraySize;i++){
        //pad zeroes to each array container bsed on limit size
        if(arrayContainer[i].length()!=limit){
            int neededZeroes = limit - arrayContainer[i].length();
            for(int j = 1;j<=neededZeroes;j++){
                arrayContainer[i]+='0';
            }
        }

        //invert the contents of each array elements in the arrayContainer
        string temp = "";
        for(int k = limit - 1; k>=0;k--){
            temp += arrayContainer[i][k];
        }
        arrayContainer[i] = temp;

        //convert each element to its value acordingly
        int decimalValue = convertBinaryToDecimal(arrayContainer[i]);
        char characterValue = getCharacterValue(decimalValue);
        result+=characterValue;
    }
    return result;
}
bool isValidDecimal(string givenDecimal){
    for(int i = 0 ; i<givenDecimal.length();i++){
        if(isalpha(givenDecimal[i])){
            return false;
        }
    }
    return true;
}
string convertDecimalToBinary(int givenDecimal){
    string result = "";
    int bitValue = 1;
    while(givenDecimal>=bitValue){
        bitValue*=2;
    }
    bitValue/=2;
    while(bitValue!=0){
        if(givenDecimal>=bitValue){
            result+='1';
            givenDecimal-=bitValue;
        }else{
            result+='0';
        }
        bitValue/=2;
    }
    return result;
}

bool isValidBinary(string givenBinary){
    for(int i=0;i<givenBinary.length();i++){
        int digit = givenBinary[i]-'0';
        if(digit >1){
            return false;
        }
    }
    return true;
}

bool isValidOctal(string givenOctal){
    for(int i=0;i<givenOctal.length();i++){
        int digit = givenOctal[i] - '0';
        if(digit>7){
            return false;
        }
    }
    return true;
}

int getDecimalEquivalent(char givenChar){
    int result = 0;
    switch(givenChar){
    case 'A':result = 10;break;
    case 'B':result = 11;break;
    case 'C':result = 12;break;
    case 'D':result = 13;break;
    case 'E':result = 14;break;
    case 'F':result = 15;break;
    default: result = givenChar - '0';break;
    }
    return result;
}
string convertOctalOrHexToBinary(string given, int limit){
    string result = "";
    for(int i=0;i<given.length();i++){
        int decimal = getDecimalEquivalent(given[i]);
        string binary = convertDecimalToBinary(decimal);
        if(binary.length()!=limit){
            int neededZeroes = limit - binary.length();
            string temporary = "";
            for(int j = 1;j<=neededZeroes;j++){
                temporary+='0';
            }
            temporary+=binary;
            binary = temporary;
        }
        result += binary;
    }
    return result;
}

bool isValidHex(string givenHex){
    for(int i=0;i<givenHex.length();i++){
        int decimal = getDecimalEquivalent(givenHex[i]);
        if(decimal > 15){
            return false;
        }
    }
    return true;
}
void runDecimalConversion(){
    cout << "DECIMAL CONVERNSION " << endl;
    string decimal;
    cout << "Enter your number " << endl;
    cin >> decimal;
    while(!isValidDecimal(decimal)){
        cout << "That is not a valid number " << endl;
        cin >> decimal;
    }
    string binaryResult = convertDecimalToBinary(stoi(decimal));
    string octalResult = convertBinaryToOctalorHex(binaryResult,3);
    string hexResult = convertBinaryToOctalorHex(binaryResult,4);
    cout << "YOU PROVIDED: " << decimal << endl;
    cout << "BINARY RESULT: " << binaryResult << endl;
    cout << "OCTAL RESULT: " << octalResult << endl;
    cout << "HEX RESULT: " << hexResult << endl;
}
void runBinaryConversion(){
    cout << "BINARY CONVERSION" << endl;
    string binary;
    cout << "Enter your binary " << endl;
    cin >> binary;
    while(!isValidBinary(binary)){
        cout << "That is not a valid binary" << endl;
        cin >> binary;
    }
    int decimalResult = convertBinaryToDecimal(binary);
    string octalResult = convertBinaryToOctalorHex(binary,3);
    string hexResult = convertBinaryToOctalorHex(binary,4);
    cout << "YOU PROVIDED: " << binary << endl;
    cout << "DECIMAL RESULT: " << decimalResult << endl;
    cout << "OCTAL RESULT: " << octalResult << endl;
    cout << "HEX RESULT: " << hexResult << endl;
}
void runOctalConversion(){
    cout << "OCTAL CONVERSION " << endl;
    string octal;
    cout << "Enter your octal " << endl;
    cin >> octal;
    while(!isValidOctal(octal)){
        cout << "That is not a valid octal " << endl;
        cin >> octal;
    }
    string binaryResult = convertOctalOrHexToBinary(octal,3);
    string hexResult = convertBinaryToOctalorHex(binaryResult,4);
    int decimalResult = convertBinaryToDecimal(binaryResult);
    cout << "YOU PROVIDED: " << octal << endl;
    cout << "BINARY RESULT: " << binaryResult << endl;
    cout << "HEX RESULT: " << hexResult << endl;
    cout << "DECIMAL RESULT: " << decimalResult << endl;

}
void runHexConversion(){
    cout << "HEX CONVERSION " << endl;
    string hex;
    cout << "Enter your hex" << endl;
    cin >> hex;
    while(!isValidHex(hex)){
        cout << "That is not a valid hex" << endl;
        cin >> hex;
    }
    string binaryResult = convertOctalOrHexToBinary(hex,4);
    string octalResult = convertBinaryToOctalorHex(binaryResult,3);
    int decimalResult = convertBinaryToDecimal(binaryResult);
    cout << "YOU PROVIDED: " << hex << endl;
    cout << "BINARY RESULT: " << binaryResult << endl;
    cout << "OCTAL RESULT: " << octalResult << endl;
    cout << "DECIMAL RESULT: " << decimalResult << endl;
}
void showOptions(){
    cout << "Select an Option " << endl;
    cout << "1: Convert Decimal " << endl;
    cout << "2: Convert Binary" << endl;
    cout << "3: Convert Octal" << endl;
    cout << "4: Convert Hex" << endl;
    cout << "0: Exit" << endl;
}

bool isValidOption(char givenOption){
    int option = givenOption - '0';
    if(option < 0 || option > 4){
        return false;
    }
    return true;
}
void clearScreen(){
    system("cls");
}
void acceptOption(){
    char option;
    do{
        cin >> option;
        while(!isValidOption(option)){
            cout << "That is not in the selection" << endl;
            cin >> option;
        }
        switch(option){
        case '0':
            clearScreen();
            showDivider();
            cout << "Thank you for using this application" << endl;
            showDivider();
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
        default :
            cout << "I don't know how'd you got this error " << endl;
            break;
        }
    }while(option!='0');
}
void runApplication(){
    showDivider();
    showOptions();
    acceptOption();
}

int main(){
    runApplication();
return 0;
}
