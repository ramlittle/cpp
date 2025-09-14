#include <iostream>
using namespace std;

string reverseTheText(string )
string cleanTheTextEntered(string givenText){
    //s23ample!@#
    //step 1: prepare variables
    string charactersToIgnore = "~!@#$%^&*()-={}[]:;' <>,.?/1234567890";
    string charactersNeeded="";
    string loweredText="";
    //step 2: loop through the givenText

    for(int i=0;i<givenText.length();i++){
        int counter = 0;
        for(int j=0;j<charactersToIgnore.length();j++){
            if(givenText[i] == charactersToIgnore[j]){
                counter++;
            }
        }
        if(counter == 0){
            charactersNeeded+=givenText[i];
        }
    }
    //step 3: lowercase the givenText
    for(int i=0;i<charactersNeeded.length();i++){
        loweredText+=tolower(charactersNeeded[i]);
    }
    return loweredText;
}


void runPalindromeCheckFromFile(){
    cout << "PALINDROME CHECK FROM FILE" << endl;
    string fileName;
    cout << "Enter the File Name. Example: file.txt" << endl;
    cin >> fileName;
    cout << "Reading file " << fileName << " ..." << endl;
}
void runPalindromeCheckFromUserInput(){
    cout << "PALINDROME CHECK FROM USER INPUT" << endl;
    string text;
    cout << "Enter the text to check "<< endl;
    getline(cin,text);
    cout << "You entereded " << text << endl;
    string cleanedText = cleanTheTextEntered(text);
    string reversedText = "";
}
void clearScreen(){
    system("cls");
}
void showDivider(){
    string divider="=============================";
    cout << divider << endl;
}

void acceptOnlyTheFirstCharacter(){
    int characterLimit = 1000;
    cin.ignore(characterLimit,'\n');
}
void acceptSelectedOption(){
    char option;
    do{
        cin >> option;
        acceptOnlyTheFirstCharacter();
        while(isalpha(option)){
            cout << "That is not a number! Please try again!"<< endl;
            cin >> option;
            acceptOnlyTheFirstCharacter();
        }
        switch(option){
            case '0':
            cout << "Thank you for using this application. See again next time" << endl;
                break;
            case '1':
                clearScreen();
                showDivider();
                runPalindromeCheckFromUserInput();
                showDivider();
                break;
            case '2':
                clearScreen();
                showDivider();
                runPalindromeCheckFromFile();
                showDivider();
                break;
            default:
                cout << "That is not in the options" << endl;
                break;
        }
    }while(option!='0');
}

void showOptions(){
    cout << "Select an option" << endl;
    cout << "1: Enter text" << endl;
    cout << "2: Enter file name to test. Example: textfile.txt"<< endl;
    cout << "0: Exit" << endl;
}
void showTitle(){
    const string title = "Palindrome App";
    cout << title<< endl;
}
void showAuthor(){
    const string author = "Ram";
    cout << "created by: " << author << endl;
}

void runApplication(){
    showTitle();
    showAuthor();
    showDivider();
    showOptions();
    showDivider();
    acceptSelectedOption();
}
int main(){
    runApplication();
    return 0;
}
