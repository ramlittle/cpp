/*
    author: Ramelito N. Martinez
    purpose: MOCK EDPSE

*/

#include <iostream>
#include <fstream>
using namespace std;

bool isLeapYear(int givenYear){
    if(givenYear%400==0){
        return true;
    }
    if(givenYear%4==0 && givenYear%100!=0){
        return true;
    }
    return false;
}
bool isValidYear(string year){
    for(int i=0;i<year.length();i++){
        if(isalpha(year[i])){
            return false;
        }
    }
    if(stoi(year) < 0){
        return false;
    }
    return true;
}
void showDivider(){
    cout << "================================" << endl;
}
void runLeapYearFromUserInput(){
    cout << "LEAP YEAR: Accepting User Input..." << endl;
    cout << "Enter the year" << endl;
    string year;
    cin >> year;
    while(!isValidYear(year)){
        cout << "That is not a valid year. Try again!" << endl;
        cin >> year;
    }
    if(isLeapYear(stoi(year))){
       cout << "The year " << year << " is a leap year" << endl;
    }else{
        cout << "The year " << year << " is not a leap year" << endl;
    }
}
void readAndWriteFile(string givenFile){
    ifstream readFromFile;
    fstream writeToFile;

    readFromFile.open(givenFile);
    writeToFile.open("results.txt",ios::app);

    if(!readFromFile.is_open()){
        cout << "Sorry unable to read from file given. Make sure the file name and type is correct" << endl;
        return;
    }

    if(!writeToFile.is_open()){
        cout << "Sorry unable to write to results.txt. You may troubleshoot now" << endl;
        return;
    }

    string year;
    writeToFile << "LEAP YEAR APP" << endl;
    while(readFromFile >> year){
        string result;
        if(isValidYear(year)){
            if(isLeapYear(stoi(year))){
                result = year + " is a leap year";
            }else{
                result = year + " is not a leap year";
            }
        }else{
            result = year + " is not a valid year";
        }
        cout << result << endl;
        writeToFile << result << endl;
    }
    cout << "Writing to file is successful. Check results.txt for reference" << endl;
    readFromFile.close();
    writeToFile.close();
}
void runLeapYearFromFile(){
    cout << "LEAP YEAR: Reading from file..." << endl;
    cout << "Enter the file name and file type. Example: file.txt" << endl;
    string file;
    cin >> file;
    readAndWriteFile(file);
}
void clearScreen(){
    system("cls");
}
void readOneCharacterOnly(){
    int limit = 1000;
    cin.ignore(limit,'\n');
}
void showOptions(){
    cout << "Select an Option " << endl;
    cout << "1: Enter a year " << endl;
    cout << "2: Read from a file " << endl;
    cout << "0: Exit" << endl;
}
void acceptUserOption(){
    char option;
    do{
        cin >> option;
        readOneCharacterOnly();
        while(isalpha(option)){
            cout << "That is not a number. Try again!" << endl;
            cin >> option;
            readOneCharacterOnly();
        }
        switch(option){
        case '0':
            clearScreen();
            cout << "Thank you for using this application. See you again next time!" << endl;
            break;
        case '1':
            clearScreen();
            runLeapYearFromUserInput();
            showDivider();
            showOptions();
            break;
        case '2':
            clearScreen();
            runLeapYearFromFile();
            showDivider();
            showOptions();
            break;
        default:
            cout << "That is not in the options! Try again!" << endl;
            break;
        }
    }while(option!='0');
}
void showAuthor(){
    string author = "Ramelito N. Martinez";
    cout << "Author : " << author << endl;
}
void showApplicationTitle(){
    string title = "LEAP YEAR APP";
    cout << "Application : " << title << endl;
}
void runApplication(){
    showDivider();
    showApplicationTitle();
    showAuthor();
    showDivider();
    showOptions();
    acceptUserOption();
}
int main(){
    runApplication();
return 0;
}
