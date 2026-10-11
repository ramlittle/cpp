/*
    EDPSE MOCK EXAM
    Author Ramelito NMartinez
*/
#include <iostream>
#include <fstream>
using namespace std;

struct ObjectToSave{
    string application;
    int given;
    string result;
};

void saveResults(ObjectToSave leapYear){
    fstream appendToFile;
    appendToFile.open("results.txt",ios::app);
    if(!appendToFile.is_open()){
        cout << "Sorry unable to write results. Do you troubleshooting techniques!" << endl;
        return;
    }
    appendToFile << leapYear.application << endl;
    appendToFile << "GIVEN : " << leapYear.given << endl;
    appendToFile << "RESULTS : " << leapYear.result << endl;
    appendToFile.close();
}

bool isLeapYear(int givenYear){
    if(givenYear%400 == 0){
        return true;
    }
    if(givenYear%4 == 0 && givenYear%100 != 0){
        return true;
    }
    return false;
}

void runLeapYearChecker(){
    string title = "LEAP YEAR CHECKER";
    cout << title << endl;
    cout << "Enter the year" << endl;
    int year;
    cin >> year;
    ObjectToSave leapYear;
    leapYear.application = title;
    leapYear.given = year;
    isLeapYear(year) ? leapYear.result = "LEAP YEAR" : leapYear.result = "NOT LEAP YEAR";
    saveResults(leapYear);
    cout << "GIVEN : " << leapYear.given << endl;
    cout << "RESULT: " << leapYear.result << endl;
    cout << "Saving successful! See results.txt for reference" << endl;
}

void clearScreen(){
    system("cls");
}
void readOnlyOneCharacter(){
    // reads only 1 character even if users enter more after enter key
    cin.ignore(1000,'\n');
}
void showOptions(){
    cout << "Select your option" << endl;
    cout << "1: Use Leap Year Checker" << endl;
    cout << "0: Exit" << endl;
}

void showDivider(){
    string divider = "=======================";
    cout << divider << endl;
}

void showAuthor(){
    string author = "Ramelito Martinez";
    string purpose = "EDPSE MOCK EXAM";
    cout << author << endl;
    cout << purpose << endl;
}

void runApplication(){
    showAuthor();
    showDivider();
    showOptions();
    showDivider();
    char option;
    do{
        cin >> option;
        readOnlyOneCharacter();

        while(isalpha(option)){
            cout << "That is not a number! Try Again!";
            cin >> option;
            readOnlyOneCharacter();
        }
        switch(option){
        case '0':
            clearScreen();
            showDivider();
            cout << "Thank you for using this application" << endl;
            break;
        case '1':
            clearScreen();
            showDivider();
            runLeapYearChecker();
            showDivider();
            showOptions();
            break;
        default :
            clearScreen();
            cout << "That is not in the options! Try Again!" << endl;
            showDivider();
            showOptions();
            break;
        }
    }while(option!='0');
}

int main(){
    runApplication();
return 0;
}
