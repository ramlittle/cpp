#include <iostream>
using namespace std;

struct MyObject{
    string name;
    int age;
};

void showDivider(){
    cout << "============================" << endl;
}
void showAppTitle(){
    cout << "Title: Practice Struct, Array Object, and Bubble Sort" << endl;
}
void showAuthor(){
    string author = "Ramelito Martinez";
    string purpose = "EDPSE Exam Practice";
    cout << "Author: " << author << endl;
    cout << "Purpose: " << purpose << endl;
}

void processOnlyTheFirstCharacterEntered(){
    cin.ignore(1000,'\n');
}
void clearScreen(){
    system("cls");
}

void runPracticeArrayObjects(){
    string title = "Practice Array Objects";
    cout << "Title: " << title << endl;
}
void showOptions(){
    cout << "What would you like to do?"<< endl;
    cout << "1: Practice Array Objects" << endl;
    cout << "2: Enter a binary, convert to octal, sort the result lowest to highest, then display the decimal result" << endl;
    cout << "3: Enter a decimal, convert to binary, convert to octal, sort result highest to lowest, then display the result in decimal" << endl;
    cout << "0: Exit" << endl;
}

void acceptUserOption(){
    char option;
    do{
        cin >> option;
        processOnlyTheFirstCharacterEntered();
        while(isalpha(option)){
            cout << "The option selected is not a number. Try again"<<endl;
            cin>>option;
            processOnlyTheFirstCharacterEntered();
        }
        switch(option){
        case '0':
            cout << "Thank you for using this application" << endl;
            break;
        case '1':
            clearScreen();
            showDivider();
            runPracticeArrayObjects();
            showDivider();
            showOptions();
            break;
        default:
            cout << "That is not in the options. Try Again!" <<endl;
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
    acceptUserOption();
}
int main(){
    runApplication();
return 0;
}
