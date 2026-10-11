/*
    NUMBER SYSTEM
    PREPRATION FOR ICT PROF HAND ON
    This program does conversion of decimal, binary, octal, hexa, palindrome, and leapyear
*/

#include <iostream>
#include <fstream>
using namespace std;

string convertDecimalToBinary(int givenDecimal){
    //step 1: prepare binaryResult
    string binaryResult="";
    //step 2: determine highest binaryValue for comparison
    int binaryValue = 1;
    while(binaryValue <= givenDecimal){
        binaryValue*=2;
    }
    binaryValue/=2;
    //step 3: loop until binaryValue is 0
    while(binaryValue!=0){
        //step 4: concatenate 1 to binaryResult and deduct binaryValue from givenDecimal when givenDecimal is >= binaryValue
        if(givenDecimal >= binaryValue){
            binaryResult+="1";
            givenDecimal-=binaryValue;
        }else{
            //step 5: when givenDecimal is lesser than binaryValue, 0 is concatenated to binaryResult
            binaryResult+="0";
        }
        //step 6: binaryValue is divided by 2 each iteration
        binaryValue/=2;
    }
    return binaryResult;
}

int convertBinaryToDecimal(string givenBinary){
    //step 1: prepare decimalValue and binaryValue
    int decimalValue = 0;
    int binaryValue = 1;
    //step 2: loop through the givenBinary in reverse
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 3: add the binaryValue to decimal when givenBinary character is 1
        if(givenBinary[i] == '1'){
            decimalValue += binaryValue;
        }
        //step 4: binary Value is multiplied by 2 each iteration
        binaryValue*=2;
    }
    return decimalValue;
}

string convertOctalToBinary(string givenOctal){
    //step 1: determine length of octal
    int lengthOfGivenOctal = givenOctal.length();

    //step 2: prepare binaryResult
    string concatenatedBinaryResult = "";

    //step 3: loop through the givenOctal
    for(int i=0;i<lengthOfGivenOctal;i++){
        //step 4: convert each character of givenOctal to integer
        int integerValue = givenOctal[i]-'0';
        //step 5: convert each integer to binary
        string binaryValue=convertDecimalToBinary(integerValue);
        //step 6: make sure each binaryValue length is 3
        if(binaryValue.length() != 3){
            int neededZeroes = 3-binaryValue.length();
            string temporary = ""; //additional zeroes
            for(int j=1;j<=neededZeroes;j++){
                temporary += '0';
            }
            //step 7:combine temporary and binary Value
            temporary+=binaryValue;
            //step 8: then return the value of temporary to binaryValue
            binaryValue=temporary;
        }
        concatenatedBinaryResult += binaryValue;
    }
    return concatenatedBinaryResult;
}

string convertBinaryToOctal(string givenBinary){
    //step 1: prepare array to split the givenBinary
    int quotientResult = givenBinary.length()/3;
    int moduloResult = givenBinary.length()%3;
    int lengthOfOctalArray=quotientResult+moduloResult;
    string octalArrayContainer[lengthOfOctalArray];
    //step 2: loop through the givenBinary string in reverse
    int index = lengthOfOctalArray-1;
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 3: insert each binary character to the elements in octalArrayContainer until length of each elment is three
        if(octalArrayContainer[index].length()!=3){
            octalArrayContainer[index]+=givenBinary[i];
        }else{
        //step 4: when the element length is 3, move to the next element by decrement since we started at the last element
        //then insert the binary character to the next element index
            index--;
            octalArrayContainer[index]+=givenBinary[i];
        }
    }

    //step 5: loop through the octal Array
    for(int i=0;i<lengthOfOctalArray;i++){
        //step 6: make sure each element has a max length of 3
        if(octalArrayContainer[i].length()!=3){
            int neededZeroes = 3-octalArrayContainer[i].length();
            for(int j=1;j<=neededZeroes;j++){
                octalArrayContainer[i]+='0';
            }
        }
        //step 7: reverse the characters of each element so that the order of bits is correct
        //example: if user gives 1001001 the elements became [100][100][100]
        //so target result is 001][001][001]
        string temporary = "";
        for(int k=2;k>=0;k--){
            temporary+=octalArrayContainer[i][k];
        }
        octalArrayContainer[i]=temporary; //reset the value of octalArrayContainer[i] with the temporary string
    }

    //step 8: loop through octalArrayContainer again once reordered
    string octalResult="";
    for(int i=0;i<lengthOfOctalArray;i++){
        //step 9: convert each element to its decimal value
        int decimalValue = convertBinaryToDecimal(octalArrayContainer[i]);
        //step 10: convert each element to its char value
        char charValue = decimalValue +'0';
        //step 11: concatenate result to octalResult;
        octalResult+=charValue;
    }

    //step 12: return the result;
    return octalResult;
}

int determineDecimalValue(char givenCharacter){
    //step 1: prepare decimalValue variable
    int decimalValue;
    //switch through cases for givenCharacter
    switch(givenCharacter){
        case 'A' : decimalValue = 10;break;
        case 'B' : decimalValue = 11;break;
        case 'C' : decimalValue = 12;break;
        case 'D' : decimalValue = 13;break;
        case 'E' : decimalValue = 14;break;
        case 'F' : decimalValue = 15;break;
        default : decimalValue = givenCharacter - '0';
    }
    return decimalValue;
}

string convertHexToBinary(string givenHex){
    //step 1: get length of Hex
    int lengthOfGivenHex = givenHex.length();
    //step 2: prepare string for finalResult;
    string binaryResult = "";
    //step 3: loop through the givenHex
    for(int i=0;i<lengthOfGivenHex;i++){
        //step 4: convert each character to integer-decimal value
        int decimalValue = determineDecimalValue(givenHex[i]);
        //step 5: convert each decimalValue to its binaryForm and
        string binaryValue = convertDecimalToBinary(decimalValue);
        //step 6: add zeroes to binaryValue if length is not 4
        if(binaryValue.length()!=4){
            int neededZeroes = 4 - binaryValue.length();
            string temporary = "";
            for(int j=1;j<=neededZeroes;j++){
                temporary+='0';
            }
            temporary+=binaryValue;
            binaryValue = temporary;
        }
        //step 7: concatenate the result to binaryResult;
        binaryResult+=binaryValue;
    }
    //step 6: return the result;
    return binaryResult;
}

char determineCharacterValue(int givenDecimal){
    //step 1: prepare character Result
    char characterValue;

    //step 2: switch through the hex equivalent
    switch(givenDecimal){
        case 10 : characterValue = 'A';break;
        case 11 : characterValue = 'B';break;
        case 12 : characterValue = 'C';break;
        case 13 : characterValue = 'D';break;
        case 14 : characterValue = 'E';break;
        case 15 : characterValue = 'F';break;
        default : characterValue = givenDecimal + '0';
    }

    //step 3: return characterValue
    return characterValue;
}
string convertBinaryToHex(string givenBinary){
    //step 1: determine length of array to contain the bits of givenBinary
    int quotientResult = givenBinary.length()/4;
    int moduloResult = givenBinary.length()%4;
    int arrayLength = quotientResult + moduloResult;

    //step 2: prepare array container
    string hexArrayContainer[arrayLength];

    //step 3: loop through the givenBinary in reverse
    int index = arrayLength-1;
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 4: insert the bits into each element of hexArrayContainer until length is 4; starting from the last element of hexArrayContainer
        if(hexArrayContainer[index].length() !=4 ){
            hexArrayContainer[index] += givenBinary[i];
        }else{
            //step 5: when length is at 4, move to the next element and insert the bit accordingly
            index--;
            hexArrayContainer[index] += givenBinary[i];
        }
    }

    //step 6: loop through hexArrayContainer
    string hexResult="";
    for(int i=0;i<arrayLength;i++){
        //step 7: make sure that each element is of 4 length
        if(hexArrayContainer[i].length()!=4){
            //step 8: if length of 4 is not met pad zeroes to the element
            int neededZeroes = 4-hexArrayContainer[i].length();
            for(int j=1;j<=neededZeroes;j++){
                hexArrayContainer[i]+='0';
            }
        }
        //step 9: reorder the bits so it will be ready for hex conversion
        //example: givenBinary = 100010001 ; when it was inserted the array and zeroes were padded above it became [1000][1000][1000]
        //goal is to make it look like this [0001][0001[0001]
        string temporary="";
        for(int k=3;k>=0;k--){
            temporary+=hexArrayContainer[i][k];
        }
        hexArrayContainer[i]=temporary;
        //step 10: convert each element to decimal
        int decimalValue = convertBinaryToDecimal(hexArrayContainer[i]);
        //step 11: convert each decimalValue to its hexEquivalent
        char eachHexValue = determineCharacterValue(decimalValue);
        //step 12: concatenate the result to hexResult
        hexResult+=eachHexValue;
    }
    return hexResult;
}

bool isLeapYear(int givenYear){
    //step 1: deterine if given year is divisible by 400
    if(givenYear%400==0){
        return true;
    }
    //step 2: proceed here if above is no match;
    //determine if given year is divisible by 4 and is has a remainder if divided by 100
    if(givenYear%4 == 0 && givenYear%100 !=0){
        return true;
    }
    //step 3: proceed here if the above has no match
    return false;
}

void processReadingAndWriting(){
    //step 1: prepare file stream objects for reading and writing
    ifstream readingOfFile;
    ofstream writingOfFile;
    readingOfFile.open("years.txt");
    writingOfFile.open("results.txt");

    //step 2: check if reading and writing works; stop the program if not
    if(!readingOfFile.is_open()){
        cout << "unable to read locate file"<< endl;
        return;
    }
    if(!writingOfFile.is_open()){
        cout << "unable to write to file" << endl;
        return;
    }

    //step 3: read and write the results
    int year;
    writingOfFile << "THIS PROGRAM SOLVES FOR LEAP YEAR" << endl;
    while(readingOfFile >> year){
        isLeapYear(year) ?
        writingOfFile << year << " is Leap " << endl :
        writingOfFile << year << " is Not Leap " << endl;
    }
    writingOfFile << "THIS PART OF THE PROGRAM Determines what are leap years from year 1 until year 2000" << endl;
    for(int i=1;i<=2000;i++){
        if(isLeapYear(i)){
            writingOfFile << i << " ";
        }
    }
    cout << "writing is successful" << endl;

    //step 4: close the fs objects
    readingOfFile.close();
    writingOfFile.close();
}

string cleanTheGivenText(string givenText){
    //step 1: prepare list of special characters and cleanText
    string specialCharacters = "`!@#$%^&*()-=[]\|;:',<.>/? ";
    string cleanedText="";
    //step 2: loop through the givenText
    //givenText == Ram!@# Lito
    for(int i=0;i<givenText.length();i++){
        int counter=0;
        for(int j=0;j<specialCharacters.length();j++){
            //step 3: if the givenText Character is equal to any special character, increment counter then break;
            if(givenText[i] == specialCharacters[j]){
                counter++;
                break;
            }
        }
        //step 4: concatenate the resulting character to cleanedText if the counter is still zero
        //if greater than zero, it means there was a special character found from the loop code above
        if(counter == 0){
            cleanedText+=tolower(givenText[i]);
        }
    }
    cout << "Cleaned text is " << cleanedText << endl;
    return cleanedText;
}

bool isPalindrome(string givenText){
    //step 1: clean the given text(remove special chars, make it to lower case
    string cleanedText = cleanTheGivenText(givenText);
    //step 2: make a copy of the given in reverse
    string reversedCleanedText="";
    for(int i=cleanedText.length()-1;i>=0;i--){
        reversedCleanedText+=cleanedText[i];
    }
    //step 3: compare the cleaned text and reverse version
    if(cleanedText == reversedCleanedText){
        return true;
    }
    return false;
}

void processReadingAndWritingForPalindrome(){
    //step 1: prepare file stream objects for reading and writing
    ifstream readingOfFile;
    ofstream writingOfFile;
    readingOfFile.open("texts.txt");
    writingOfFile.open("results.txt");

    //step 2: check if reading and writing works; stop the program if not
    if(!readingOfFile.is_open()){
        cout << "unable to read locate file"<< endl;
        return;
    }
    if(!writingOfFile.is_open()){
        cout << "unable to write to file" << endl;
        return;
    }

    //step 3: read and write the results
    string text;
    writingOfFile << "THIS PROGRAM CHECKS FOR PALINDROME" << endl;
    while(getline(readingOfFile,text)){
        isPalindrome(text) ?
        writingOfFile << text << " is PALINDROME " << endl :
        writingOfFile << text << " is NOT " << endl;
    }
    cout << "writing is successful" << endl;

    //step 4: close the fs objects
    readingOfFile.close();
    writingOfFile.close();
}

int main(){
    //processReadingAndWriting();
    processReadingAndWritingForPalindrome();
return 0;
}
