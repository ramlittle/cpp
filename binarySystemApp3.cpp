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

void acceptOptionSelected(){
    char option;
    cin >> option;
    cout << "You selected " << option << endl;
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
