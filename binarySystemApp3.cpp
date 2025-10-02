#include <iostream>
using namespace std;

void showDivider(){
    const string divider = "==============================";
    cout << divider << endl;
}

void showAppTitle(){
    const string title = "Simple Binary System";
    cout << title << endl;
}

void showAuthor(){
    const string author = "Ram Martinez";
    const string purpose = "EDPSE MOCK EXAM";
    cout << "AUTHOR : " << author << endl;
    cout << "PURPOSE: " << purpose << endl;
}

void showOptions(){
    cout << "SELECT AN OPTION" << endl;
    cout << "1: convert decimal" << endl;
    cout << "2: convert binary" << endl;
    cout << "3: convert octal" << endl;
    cout << "4: convert hex" << endl;
    cout << "0: exit" << endl;
}

void processOnlyOneCharacter(){
    cin.ignore(1000,'\n');
}

void clearScreen(){
    system("cls");
}

bool isDecimal(string givenDecimal){
    //step 1: loop through given Decimal
    for(int i=0;i<givenDecimal.length();i++){
        if(isalpha(givenDecimal[i])){
            return false;
        }
    }
    //step 2: make sure given decimal is greater than 0
    if(stoi(givenDecimal) < 0){
        return false;
    }
    return true;
}

string convertDecimalToBinary(string givenDecimal){
    //step 1: prepare variables
    string binaryResult = "";
    int bitValue = 1;
    //step 2: convert the givenDecimal into integer
    int decimal = stoi(givenDecimal);
    //step 3: determine bitValue to use for comparison
    while(bitValue<=decimal){
        bitValue*=2;
    }
    //step 4: step down one bitValue for final comparison
    bitValue/=2;

    //step 5: loop through bitValue until it becomes 0
    while(bitValue!=0){
        //step 6: concatenate 1 to binaryResult and
        //deduct bitValue from decimal when decimal
        //is greater or equal to bitValue
        if(decimal>=bitValue){
            binaryResult+='1';
            decimal-=bitValue;
        }else{
        //step 7: concatenate 0 if otherwise
            binaryResult+='0';
        }
        //step 8: divide by 2 bitValue every iteration
        bitValue/=2;
    }
    //step 9: return result
    return binaryResult;
}

int convertBinaryToDecimal(string givenBinary){
    //step 1: preare result
    int decimalResult = 0;
    int bitValue = 1;
    //step 2: loop through the givenBinary in reverse
    for(int i = givenBinary.length()-1;i>=0;i--){
        if(givenBinary[i] == '1'){
            decimalResult+=bitValue;
        }
        bitValue*=2;
    }
    //step 3: return result
    return decimalResult;
}
char getCharacterEquivalent(int givenDecimal){
    //step 1: prepare result variable
    char result;
    //step 2: switch through available choices
    switch(givenDecimal){
    case 10: result = 'A';break;
    case 11: result = 'B';break;
    case 12: result = 'C';break;
    case 13: result = 'D';break;
    case 14: result = 'E';break;
    case 15: result = 'F';break;
    default: result = givenDecimal+'0';break;
    }
    //step 3: return result;
    return result;
}
string convertBinaryToOctalOrHex(string givenBinary, string mode){
    //step 1: prepare variables
    int limit = 0;
    string result = "";
    //step 2: determine limit size if for octal or hex
    if(mode == "octal"){
        limit = 3;
    }
    if(mode == "hex"){
        limit = 4;
    }
    //step 3: determine arrayContainer with its size; this is where
    //we'll split the bits
    int quotientResult = givenBinary.length()/limit;
    int moduloResult = givenBinary.length()%limit;
    int arraySize = quotientResult+moduloResult;
    string arrayContainer[arraySize];
    int arrayIndex = arraySize-1;
    //step 4: loop through the givenBinary in reverse
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 5: insert the bits into the elements of arrayContainer,
        //when the element has reached its limited length, move to the next element
        if(arrayContainer[arrayIndex].length() == limit){
            arrayIndex--;
            arrayContainer[arrayIndex]+=givenBinary[i];
        }else{
            arrayContainer[arrayIndex]+=givenBinary[i];
        }
    }

    //step 6: loop through the result of the arrayContainer
    for(int i =0 ;i<arraySize;i++){
        //step 7: pad zeroes if the length of each arrayContainer
        //element is not yet reached
        if(arrayContainer[i].length()!=limit){
            int neededZeroes = limit-arrayContainer[i].length();
            for(int j=1;j<=neededZeroes;j++){
                arrayContainer[i]+='0';
            }
        }
        //step 8: rearrange each element to proper form so that we can
        //convert the bits properly to decimal
        //example: givenBinary = [100][100][100] will be rearranged to [001][001][001]
        string temp="";
        for(int k=arrayContainer[i].length()-1;k>=0;k--){
            temp+=arrayContainer[i][k];
        }
        arrayContainer[i] = temp;
        //step 9: convert each element of arrayContainer to decimal
        int decimalValue = convertBinaryToDecimal(arrayContainer[i]);
        //step 10: convert to character equivalent
        char characterValue = getCharacterEquivalent(decimalValue);
        //step 11: concatenate the decimalValue character to result
        result+=characterValue;
    }

    //step 12: return result
    return result;

}
void runDecimalConversion(){
    cout << "DECIMAL CONVERSION" << endl;
    //step 1: accept decimal number
    string decimal;
    cout << "Enter your decimal number" << endl;
    cin >> decimal;
    //step 2: validate user input
    while(!isDecimal(decimal)){
        cout << "That is not a decimal number. Make sure it is a positive number as well!" << endl;
        cin >> decimal;
    }
    //step 3: do converstions
    string binaryResult = convertDecimalToBinary(decimal);
    string octalResult = convertBinaryToOctalOrHex(binaryResult,"octal");
    string hexResult = convertBinaryToOctalOrHex(binaryResult,"hex");
    //step 4: show results
    cout << "Binary Result: " << binaryResult << endl;
    cout << "Octal Result: " << octalResult << endl;
    cout << "Hex Result: " << hexResult << endl;
}

bool isValidBinary(string givenBinary){
    //step 1: loop through the givenBinary
    for(int i=0;i<givenBinary.length();i++){
        //step 2: return false if a bit is not 1 or 0
        if(givenBinary[i] != '1'){
           if(givenBinary[i]!='0'){
                return false;
           }
        }
    }
    //step 3: return true if all good
    return true;
}
void runBinaryConversion(){
    cout << "BINARY CONVERSION" << endl;
    //step 1: ask for user input
    cout << "Enter your binary" <<endl;
    string binary;
    cin >> binary;
    //step 2: validate input
    while(!isValidBinary(binary)){
        cout << "This is not a valid binary. Try again" << endl;
        cin >> binary;
    }
    //step 3: do conversions
    int decimalResult = convertBinaryToDecimal(binary);
    string octalResult = convertBinaryToOctalOrHex(binary,"octal");
    string hexResult = convertBinaryToOctalOrHex(binary,"hex");
    //step 4: display results
    cout << "Decimal Result: " << decimalResult << endl;
    cout << "Octal Result: " << octalResult << endl;
    cout << "Hex Result: " << hexResult << endl;

}
bool isValidOctal(string octal){
    //step 1: loop through the given octal
    for(int i=0;i<octal.length();i++){
        //step 2: mark false if each character is greater than 7
        int integerValue = octal[i] - '0';
        if(integerValue > 7){
            return false;
        }
    }
    //step 3: return true if all goods
    return true;
}

string convertOctalOrHexToBinary(string givenOctalOrHex, string mode){
    //step 1: prepare variables
    string finalResult="";
    int limit = 0;
    if(mode == "octal"){
        limit = 3;
    }
    if(mode == "hex"){
        limit = 4;
    }
    //step 2: loop through the given
    for(int i=0;i<givenOctalOrHex.length();i++){
        //step 3: convert each character to string
        string stringValue="";
        stringValue+=givenOctalOrHex[i];
        //step 5: convert the string into binary
        string binaryResult = convertDecimalToBinary(stringValue);
        //step 6: pad leading zeroes if limit for each mode is not met
        if(binaryResult.length() != limit){
            int neededZeroes = limit-binaryResult.length();
            string temporary = "";
            for(int j=1;j<=neededZeroes;j++){
                temporary+='0';
            }
            temporary+=binaryResult;
            binaryResult=temporary;
        }
        //step 7: concatenate the binaryResult to finalResult
        finalResult+=binaryResult;
    }
    //step 8: return  result
    return finalResult;

}
void runOctalConversion(){
    cout << "OCTAL CONVERSION" << endl;
    //step 1: accept input
    cout << "Enter your Octal" << endl;
    string octal;
    cin >> octal;
    //step 2: validate input
    while(!isValidOctal(octal)){
        cout << "That is not a valid Octal. Try again" << endl;
        cin >> octal;
    }
    //step 3: do conversions
    string binaryResult = convertOctalOrHexToBinary(octal,"octal");
    string hexResult = convertBinaryToOctalOrHex(binaryResult,"hex");
    int decimalResult = convertBinaryToDecimal(binaryResult);
    //step 4: display results
    cout << "Binary Result: " << binaryResult << endl;
    cout << "Hex Result: " << hexResult << endl;
    cout << "Decimal Result: " << decimalResult << endl;

}

void runHexConversion(){
    cout << "HEX CONVERSION" << endl;
}
void acceptOptionSelected(){
    char option;
    do{
        cin >> option;
        processOnlyOneCharacter();
        while(isalpha(option)){
            cout << "That is not a number. Try again!" << endl;
            cin >> option;
            processOnlyOneCharacter();
        }
        switch(option){
        case '0':
            clearScreen();
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
            cout << "That is not in the options!. Try again!"<<endl;
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
    acceptOptionSelected();
}
int main(){
    runApplication();
return 0;
}
