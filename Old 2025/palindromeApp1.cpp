#include <iostream>
#include <fstream>
using namespace std;


bool isPalindrome(string cleanedText, string reversedText){
    if(cleanedText == reversedText){
        return true;
    }
    return false;
}
string reverseTheText(string givenText){
    //step 1: prepare result variable
    string result = "";
    //step 2: loop through the givenText in reverse
    for(int i = givenText.length()-1;i>=0;i--){
        result+=givenText[i];
    }
    //step 3: return the result
    return result;
}
string cleanTheTextEntered(string givenText){
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
void readFromFile(string fileName){
    //step 1: create the readFile and writeFile objects
    ifstream readFile;
    ofstream writeFile;
    //step 2: open the file
    readFile.open(fileName);
    writeFile.open("palindrome_results.txt");
    if(!readFile.is_open()){
        cout << "Sorry unable to read file. Check if the file exist!" << endl;
        return;
    }
    if(!writeFile.is_open()){
        cout << "Sorry unable to save the results for later. Check error detaisl "<< endl;
        return;
    }
    string text;
    writeFile << "Result of Palindrome check from file " << fileName << endl;
    while(getline(readFile,text)){
        string result;
        string cleanedText = cleanTheTextEntered(text);
        string reversedText = reverseTheText(cleanedText);
        if(isPalindrome(cleanedText,reversedText)){
            result = text + " is Palindrome";
        }else{
            result = text + " is not Palindrome";
        }
        cout << result << endl;
        writeFile << result << endl;
    }
    cout << "Processing of read and write of files successful see palindrome_results.txt for reference " << endl;
    readFile.close();
    writeFile.close();
}
void runPalindromeCheckFromFile(){
    cout << "PALINDROME CHECK FROM FILE" << endl;
    string fileName;
    cout << "Enter the File Name. Example: file.txt" << endl;
    cin >> fileName;
    cout << "Reading file " << fileName << " ..." << endl;
    readFromFile(fileName);
}
void runPalindromeCheckFromUserInput(){
    cout << "PALINDROME CHECK FROM USER INPUT" << endl;
    string text;
    cout << "Enter the text to check "<< endl;
    getline(cin,text);
    cout << "You entereded " << text << endl;
    string cleanedText = cleanTheTextEntered(text);
    string reversedText = reverseTheText(cleanedText);
    cout << "CleanedText : " << cleanedText << endl;
    cout << "reversed text : " << reversedText << endl;
    if(isPalindrome(cleanedText,reversedText)){
       cout << "Result : PALINDROME" << endl;
    }else{
        cout << "Result : NOT PALINDROME" << endl;
    }
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
void showOptions(){
    cout << "Select an option" << endl;
    cout << "1: Enter text" << endl;
    cout << "2: Enter file name to test. Example: textfile.txt"<< endl;
    cout << "0: Exit" << endl;
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
                showOptions();
                showDivider();
                break;
            case '2':
                clearScreen();
                showDivider();
                runPalindromeCheckFromFile();
                showDivider();
                showOptions();
                showDivider();
                break;
            default:
                cout << "That is not in the options" << endl;
                break;
        }
    }while(option!='0');
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
