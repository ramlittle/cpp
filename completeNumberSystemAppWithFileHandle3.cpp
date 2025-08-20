/*
    Author: Ramelito Martinez
    purpose: MOCK EXAM EDPSE
*/
#include <iostream>
using namespace std;

string convertDecimalToBinary(string givenDecimal){
    int decimal = stoi(givenDecimal);
    int bitValue = 1;
    string binaryResult = "";

    while(decimal >= bitValue){
        bitValue*=2;
    }
    bitValue/=2;

    while(bitValue!=0){
        if(decimal >= bitValue){
            binaryResult+='1';
            decimal-=bitValue;
        }else{
            binaryResult+='0';
        }
        bitValue/=2;
    }
    return binaryResult;
}
bool isValidDecimal(string decimal){
    int counter = 0;
    for(int i=0;i<decimal.length();i++){
        if(!isdigit(decimal[i])){
            counter++;
        }
    }
    if(counter > 0){
        return false;
    }
    return true;
}

void runDecimalConversion(){
    string title = "DECIMAL CONVERSION";
    cout << title << endl;
    string decimal;
    cout << "Enter a number greater than zero" << endl;
    cin >> decimal;
    while(!isValidDecimal(decimal)){
        cout << "That is not a valid integer. Try Again!" << endl;
        cin >> decimal;
    }
    string binaryResult=convertDecimalToBinary(decimal);
    cout << "BINARY RESULT : " << binaryResult << endl;
}
void runBinaryConversion(){
    string title = "BINARY CONVERSION";
    cout << title << endl;

}
void runOctalConversion(){
    string title = "OCTAL CONVERSION";
    cout << title << endl;
}
void runHexConversion(){
    string title = "HEX CONVERSION";
    cout << title << endl;
}
void showDivider(){
    cout << "================================" << endl;
}
void ignoreOtherCharacters(){
    int limit = 1000;
    cin.ignore(limit,'\n');
}
void showAppTitle(){
    string title = "Number System";
    cout << "Title: " << title << endl;
}
void showAuthor(){
    string author = "Ramelito N. Martinez";
    cout << "Author : " << author << endl;
}
void clearScreen(){
    system("cls");
}
void showOptions(){
    cout << "Select an option" << endl;
    cout << "1: run Decimal Conversion" << endl;
    cout << "2: run Binary Conversion" << endl;
    cout << "3: run Octal Conversion" << endl;
    cout << "4: run Hex Conversion" << endl;
    cout << "0: Exit" << endl;
}

void acceptUserOption(){
    char option;
    do{
        cin >> option;
        ignoreOtherCharacters();
        while(isalpha(option)){
            cout << "That is not a number! Try again" << endl;
            cin >> option;
            ignoreOtherCharacters();
        }
        switch(option){
        case '0':
            cout << "Thank you for using this application" << endl;
            break;
        case '1':
            clearScreen();
            showDivider();
            runDecimalConversion();
            showOptions();
            break;
        case '2':
            clearScreen();
            showDivider();
            runBinaryConversion();
            showOptions();
            break;
        case '3':
            clearScreen();
            showDivider();
            runOctalConversion();
            showOptions();
            break;
        case '4':
            clearScreen();
            showDivider();
            runHexConversion();
            showOptions();
            break;
        default:
            cout << "That is not in the options. Try Again!" << endl;
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
    acceptUserOption();
}
int main(){
    runApplication();
return 0;
}
