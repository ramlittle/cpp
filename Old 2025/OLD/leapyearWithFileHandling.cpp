#include <iostream>
#include <fstream>
using namespace std;

bool isLeapYear(int givenYear){
    //step 1: return true if given year is divisible by 400
    if(givenYear % 400 == 0){
        return true;
    }
    //step 2: return true if given year is divisible by 4 and if has a remainder when divided by 100
    if(givenYear % 4 == 0 && givenYear % 100 != 0){
        return true;
    }
    //step 3: return false if the neither of the two conditions above does not match
    return false;
}

void processReadAndWriteOfFile(){
    //step 0: prepare objects for reading and writing to files
    ifstream readFile;
    ofstream writeToFile;

    //step 1: open the files using the objects created
    readFile.open("years.txt");
    writeToFile.open("results.txt");

    //step 2: check if the files are readable and writable, exit the program if either one does not work
    if(!readFile.is_open()){
        cout << "Unable to read the damn file" << endl;
        return;
    }

    if(!writeToFile.is_open()){
        cout << "Unable to write to the damn file " << endl;
        return;
    }

    //step 3: check per line the years text file and determine which ones are leap years and those that are not while writing to the results.txt file
    int year;
    cout << "THIS PROGRAM CHECKS FOR YEARS AND DETERMINES WHAT IS LEAP AND WHAT IS NOT" << endl;
    writeToFile << "THIS PROGRAM CHECKS FOR YEARS AND DETERMINES WHAT IS LEAP AND WHAT IS NOT" << endl;

    while(readFile >> year){
        if(isLeapYear(year)){
            cout << year << " is LEAP" << endl;
            writeToFile << year << " is LEAP " << endl;
        }else{
            cout << year << " is NOT" << endl;
            writeToFile << year << " is NOT" << endl;
        }
    }
    cout << "Writing to File is a success! You may check results.txt for reference"<<endl;

    //step 4: close the filestream objects
    readFile.close();
    writeToFile.close();
}
int main(){
    processReadAndWriteOfFile();
return 0;
}
