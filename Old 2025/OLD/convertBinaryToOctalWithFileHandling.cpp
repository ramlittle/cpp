/*
    AUTHOR: Ramelito N. Martinez
    DATE: June 15, 2025
    PREPARATION FOR ICT PROF HANDS ON
*/

#include <iostream>
#include <fstream>
using namespace std;


int convertBinaryToDecimal(string givenBinary){
    //cout << "element Binary is " << givenBinary << endl;
    //step 1: prepare increasing value for decimal Value and binaryValue;
    int decimalResult = 0;
    int binaryValue = 1;

    //step 2: loop through givenBinary in reverse
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 3: if binary character is equal to 1, add its binary value to the decimal Result
        if(givenBinary[i] == '1'){
            decimalResult += binaryValue;
        }
        binaryValue*=2;
    }

    return decimalResult;
}
string convertBinaryToOctal(string givenBinary){
    //cout << "original binary string " << givenBinary << endl;
    //since octal is bits is max of 3 i will use 3 as basis
    //step 1: prepare the length of the array to contain the binary given
    int quotientResult = givenBinary.length()/3;
    int moduloResult = givenBinary.length()%3;
    int lengthOfArrayContainer = quotientResult + moduloResult;

    //step 2: prepare an array to put the binary given where max length of each element is 3
    string givenBinaryContainer[lengthOfArrayContainer];

    //step 3: insert the givenBinary to the array givenBinaryContainer where max length of each element is 3
    int containerIndex = lengthOfArrayContainer-1;
    for(int i=givenBinary.length()-1;i>=0;i--){
        //step 4: if container element length reaches 3, move to the next element container
        if(givenBinaryContainer[containerIndex].length() == 2){
            givenBinaryContainer[containerIndex] += givenBinary[i];
            containerIndex--;
        }else{
            givenBinaryContainer[containerIndex] += givenBinary[i];
        }
    }

    //step 5: now, each element of my container array has reversed the bits
    // example: 1001001 became ['1']['100']['100']
    //reorder the bits into proper arrangement, also if one element has not reached length of 3, add zero bits to it
    for(int i=0;i<lengthOfArrayContainer;i++){
        if(givenBinaryContainer[i].length() < 3){
            //step 6: add zeroes to element if length is less than 3
            int neededZeroes = 3-givenBinaryContainer[i].length();
            for(int j=1;j<=neededZeroes;j++){
                givenBinaryContainer[i]+="0";
            }
        }
        //step 7: reorder the bits accordingly
        string reorderedBits = "";
        for(int k = 2;k>=0;k--){
            reorderedBits += givenBinaryContainer[i][k];
        }
        givenBinaryContainer[i]=reorderedBits;
    }

    //step 8: convert each element to its decimal value, while doing so put it inside octalResult;
    string octalResult = "";
    for(int i=0;i<lengthOfArrayContainer;i++){
        octalResult+=(convertBinaryToDecimal(givenBinaryContainer[i])+'0');
    }
    //cout << "Octal Result " << octalResult << endl;
    return octalResult;
}

void processReadAndWriteFiles(){
    //step 1: prepare fstream objects
    ifstream readingOfFile;
    ofstream writingOfFile;
    readingOfFile.open("binaries.txt");
    writingOfFile.open("results.txt");

    //step 2: check if the read and write filestreams are working, exit program if not
    if(!readingOfFile.is_open()){
        cout << "Sorry, unable to read file, check if file exists " << endl;
        return;
    }
    if(!writingOfFile.is_open()){
        cout << "Sorry, unable to write to file " << endl;
        return;
    }

    //step 3: loop through the content of binaries.txt file and put result to results.txt after converting to octal
    string title = "===THIS SHORT PROGRAM CONVERTS BINARIES TO ITS OCTAL VALUES===";
    string binary;
    cout << title << endl;

    writingOfFile << title << endl;
    while(readingOfFile >> binary){
        cout << binary << " = " << convertBinaryToOctal(binary) << endl;
        writingOfFile << binary << " = " << convertBinaryToOctal(binary) << endl;
    }

    cout << "Writing of file is successful! See results.txt for reference! " << endl;

    //step 4: close the filestream objects
    readingOfFile.close();
    writingOfFile.close();
}

int main(){
    //step 1: call processReadAndWriteFiles();
    //step 2: call convertBinaryToOctal();
        //sub step 1: call convertBinaryToDecimal()while finalizing convertBinaryToOctal() ;
    processReadAndWriteFiles();

return 0;
}
