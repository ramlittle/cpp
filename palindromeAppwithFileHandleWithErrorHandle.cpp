#include <iostream>
using namespace std;

void showDivider(){
    cout << "====================================" << endl;
}

string reverseTheText(string givenText){
    string reversedText = "";
    for(int i=givenText.length()-1;i>=0;i--){
        reversedText+=givenText[i];
    }
    return reversedText;
}

bool isPalindrome(string givenText,string reversedText){
    if(reversedText == givenText){
        return true;
    }
    return false;
}

string cleanTheTextEntered(string givenText){
    string specialCharacters = "~!@#$%^&*()-=[]{};':<>,.?/_+ ";
    string cleanedText = "";
    for(int i=0;i<givenText.length();i++){
        int counter = 0;
        for(int j=0;j<specialCharacters.length();j++){
            if(givenText[i]==specialCharacters[j]){
                counter++;
            }
        }
        if(counter == 0){
            cleanedText+=tolower(givenText[i]);
        }
    }
    return cleanedText;
}
void runPalindromeFromUserInput(){
    cout << "Palindrome Text Input" << endl;
    cout << "Enter your text: " << endl;
    string text;
    getline(cin,text);
    cout << "You Entered: " << text << endl;
    string cleanedText = cleanTheTextEntered(text);
    cout << "Cleaned Text: " << cleanedText << endl;
    string reversedText = reverseTheText(cleanedText);
    cout << "Reversed Text: " << reversedText << endl;
    if(isPalindrome(cleanedText, reversedText)){
        cout << "Result: Palindrome" << endl;
    }else{
        cout << "Result: Not Palindrome" << endl;
    }
}

void runPalindromeFromFile(){
    cout << "Palindrome From File" << endl;
    string fileName;
    cout << "Enter the file name and file type. Example: file.txt" << endl;
    cin >> fileName;
    cout << "You entered " << fileName << endl;

}
void showAppTitle(){
    string appTitle = "Palindrome Application";
    cout << appTitle << endl;
}
void showAuthor(){
    string author = "Ram Martinez";
    cout << "Author : " << author << endl;
}
void clearScreen(){
    system("cls");
}

void processFirstCharacter(){
    cin.ignore(1000,'\n');
}
void showOptions(){
    cout << "Select Options" << endl;
    cout << "1: Enter text " << endl;
    cout << "2: Read from file " << endl;
    cout << "0: Exit " << endl;
}

void acceptOption(){
    char option;
    do{
        cin >> option;
        processFirstCharacter();
        while(isalpha(option)){
            cout << "That is not a number. Try Again!" << endl;
            cin >> option;
            processFirstCharacter();
        }
        switch(option){
        case '0':
            clearScreen();
            cout << "Thank you for using the application"<< endl;
            break;
        case '1':
            clearScreen();
            showDivider();
            runPalindromeFromUserInput();
            showOptions();
            break;
        case '2':
            clearScreen();
            showDivider();
            runPalindromeFromFile();
            showOptions();
            break;
        default:
            cout << "That is not in the options! Try again" << endl;
            break;
        }
    }while(option!='0');
}
void runApplication(){
    showDivider();
    showAuthor();
    showAppTitle();
    showDivider();
    showOptions();
    showDivider();
    acceptOption();
}

int main(){
    runApplication();
return 0;
}
