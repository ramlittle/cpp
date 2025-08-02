#include <iostream>
#include <fstream>
using namespace std;


bool isLeapYear(int givenYear){
    if(givenYear % 400 == 0){
        return true;
    }
    if(givenYear % 4 == 0 && givenYear%100 != 0){
        return true;
    }
    return false;
}

void processReadAndWriteOfFile(){
    ifstream readingOfFile;
    ofstream writingOfFile;
    readingOfFile.open("years.txt");
    writingOfFile.open("results.txt");

    if(!readingOfFile.is_open()){
        cout << "Sorry unable to open file" << endl;
        return;
    }
    if(!writingOfFile.is_open()){
        cout << "SOrry unable to write file"<< endl;
        return;
    }
    int year;
    string title = "THIS PROGRAM DETERMINES IF YEAR IS LEAP OR NOT";
    cout << title << endl;
    writingOfFile << title << endl;
    while(readingOfFile>>year){
        if(isLeapYear(year)){
            cout << year << " is LEAP" << endl;
            writingOfFile << year << " is LEAP" << endl;
        }else{
            cout << year << " is NOT LEAP" << endl;
            writingOfFile << year << "is NOT LEAP" << endl;
        }
    }
    cout << "Writing results to file successful"<< endl;
    readingOfFile.close();
    writingOfFile.close();
}

int main(){
    processReadAndWriteOfFile();
return 0;
}
