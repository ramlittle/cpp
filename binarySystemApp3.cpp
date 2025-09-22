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

void runDecimalConversion(){
    cout << "DECIMAL CONVERSION" << endl;
}

void runBinaryConversion(){
    cout << "BINARY CONVERSION" << endl;
}

void runOctalConversion(){
    cout << "OCTAL CONVERSION" << endl;
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
