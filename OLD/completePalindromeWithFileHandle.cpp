/*
    MOCK EXAM:
    Ram Martinez 7-5-2025
*/

#include <iostream>
#include <fstream>
using namespace std;

struct ResultObject{
    string given;
    string result;
};
void saveResults(ResultObject palindrome){
    fstream appendToFile;
    appendToFile.open("results.txt",ios::app);
    if(!appendToFile.is_open()){
        cout << "Sorry unable to append to file for some reason" << endl;
        return;
    }
    string divider = "===================";
    string title = "PALINDROME CHECKER";
    appendToFile << divider << endl;
    appendToFile << title << endl;
    appendToFile << "GIVEN : " << palindrome.given << endl;
    appendToFile << "RESULT : " << palindrome.result << endl;
    appendToFile.close();
    return;
}
string reverseTheText(string givenText){
    string reversedText = "";
    for(int i=givenText.length()-1;i>=0;i--){
        reversedText += givenText[i];
    }
    return reversedText;
}
string cleanTheText(string givenText){
    string specialCharacters = "~!@#$%^&*()-_=+[]{}\|;:',<.>/? ";
    string cleanedText = "";
    for(int i=0;i<givenText.length();i++){
        int counter = 0;
        for(int j=0;j<specialCharacters.length();j++){
            if(givenText[i] == specialCharacters[j]){
                counter++;
                break;
            }
        }
        if(counter == 0){
            cleanedText += tolower(givenText[i]);
        }
    }
    return cleanedText;
}
bool isPalindrome(string givenText){
    string cleanedText = cleanTheText(givenText);
    string reversedText = reverseTheText(cleanedText);
    if(cleanedText == reversedText){
        return true;
    }
    return false;
}
void runPalindromeChecker(){
    string title = "";
    string text;
    ResultObject palindrome;
    cout << title << endl;
    cout << "Enter your text" << endl;
    getline(cin,text);
    palindrome.given = text;
    if(isPalindrome(text)){
        palindrome.result = "\nIS PALINDROME";
    }else{
        palindrome.result = "\nIS NOT PALINDROME";
    }
    cout << "GIVEN: " << palindrome.given << endl;
    cout << "RESULT: " << palindrome.result << endl;
    saveResults(palindrome);
    cout << "Results have been saved to results.txt" <<endl;
    return;
}
void readOneCharacterOnly(){
    cin.ignore(1000,'\n');
    return;
}
void clearScreen(){
    system("cls");
    return;
}
void showOptions(){
    string divider = "===========================";
    string title = "PALINDROME APPLICATOIN";
    cout << divider << endl;
    cout << title << endl;
    cout << "Choose your option" << endl;
    cout << "1: CHECK FOR PALINDROME" << endl;
    cout << "0: EXIT " << endl;
    cout << divider << endl;

    char option;
    do{
        cin >> option;
        readOneCharacterOnly();
        while(isalpha(option)){
            cout << "That is not a number. Please try again!" << endl;
            cin >> option;
            readOneCharacterOnly();
        }
        switch(option){
        case '0' :
            clearScreen();
            cout << "Thank you for using this application!" << endl;
            break;
        case '1':
            clearScreen();
            runPalindromeChecker();
            showOptions();
            break;
        default :
            clearScreen();
            cout << "That is not in the options. Try again!" << endl;
            showOptions();
            break;
        }
    }while(option!='0');
    return;
}
void showAuthor(){
    string author = "Ramelito N. Martinez";
    string purpose = "EDPSE Mock Exam";
    cout << author << endl;
    cout << purpose << endl;
    return;
}
void runApplication(){
    showAuthor();
    showOptions();
    return;
}

int main(){
    runApplication();
return 0;
}
