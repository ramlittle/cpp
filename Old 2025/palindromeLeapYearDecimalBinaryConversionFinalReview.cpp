/*
    Author: Ramelito N. Martinez
    Exam: ICT Proficiency Hands
    Activity: Palindrome
    Date: 10-22-2025
    Venue: DICT-CAR

*/

#include <iostream>
#include <fstream>
using namespace std;

struct PalindromeResultObject{
    string text;
    string cleanedText;
    string lowerCasedText;
    string reversedText;
    string palindromeResult;
};
void showDivider(){
    string divider = "======================================";
    cout << divider << endl;
}

void showExamDetail(){
    string author = "Ramelito N. Martinez";
    string exam = "ICT Proficiency Hands";
    string activity = "Palindrome";
    string date = "10-22-2025";
    string venue = "DICT-CAR";

    cout << "Author: " << author << endl;
    cout << "Exam: " << exam << endl;
    cout << "Activity: " << activity << endl;
    cout << "Date: " << date << endl;
    cout << "Venue: " << venue << endl;
}

void showOptions(){
    cout << "Select your option" << endl;
    cout << "1: Determine Palindrome from user input" << endl;
    cout << "2: Determine Palindrome from file" << endl;
    cout << "0: Exit" << endl;
}

void processTheFirstCharacter(){
    cin.ignore(1000,'\n');
}

void clearScreen(){
    system("cls");
}

string cleanTheText(string givenText){
    //step 1: prepareSpecialCharacters and result variable
    string specialCharacters = "`1234567890-=~!@#$%^&*()_+[]\{}|;':,./<>? ";
    string cleanedText = "";
    //step 2: loop through the givenText
    //example I am RAm23423Lito
    for(int i=0;i<givenText.length();i++){
        //step 3: check each givenText character if it is equal to any of the specialCharacters
        int counter = 0;
        for(int j =0;j<specialCharacters.length();j++){
            if(givenText[i] == specialCharacters[j]){
                counter++;
            }
        }
        //step 4: concatenate the givenText Character to cleanedText if counter is still zero;
        if(counter ==0){
                cleanedText+=givenText[i];
        }
    }
    //step 5: return result
    return cleanedText;
}

string lowerCaseTheText(string givenText){
    //step 1: prepare result variable
    string lowerCasedText = "";
    //step 2: loop through the givenText
    for(int i=0;i<givenText.length();i++){
        //step 3: lower case each character of givenText
        char lowerCasedCharacter = tolower(givenText[i]);
        //step 4: concatenate the result to the lowerCasedText
        lowerCasedText+=lowerCasedCharacter;
    }
    //step 5: return the result
    return lowerCasedText;
}

string reverseTheCharacters(string givenText){
    //step 1: prepare the result variable
    string reversedText="";
    //step 2: loop through the givenText in reverse
    for(int i=givenText.length()-1;i>=0;i--){
        //step 3: concatenate each character to the reversedText
        reversedText+=givenText[i];
    }
    //step 3: return the result
    return reversedText;
}

bool isPalindrome(string lowerCasedText,string reversedText){
    //step 1: return true if
    if(lowerCasedText == reversedText){
        return true;
    }
    //step 2: return false if otherwise
    return false;
}
void writeUserInputResultToFile(PalindromeResultObject PalindromeDetail,string title){
    //step 1: prepare fstream object
    fstream writeToFile;
    writeToFile.open("results.txt",ios::app);
    //step 2: end run if unable to write to file
    if(!writeToFile.is_open()){
        cout << "Sorry, unable to write to file" << endl;
        return;
    }
    //step 3: write to file
    string divider = "================================";
    writeToFile << divider << endl;
    writeToFile << title << endl;
    writeToFile << PalindromeDetail.text << endl;
    writeToFile << PalindromeDetail.cleanedText << endl;
    writeToFile << PalindromeDetail.lowerCasedText << endl;
    writeToFile << PalindromeDetail.reversedText << endl;
    writeToFile << PalindromeDetail.palindromeResult << endl;
    cout << "Saving is successful. See results.txt for reference" << endl;
    //step 4: close the fstream object
    writeToFile.close();
}
void runPalindromeFromUserInput(){
    //step 0: show title and prepare result variable
    string title = "Palindrome From User Input ";
    string palindromeResult = "";
    cout << title << endl;

    //step 1: ask for user input
    cout << "Enter your text" << endl;
    string text;
    getline(cin,text);
    //step 2: clean the text by removing special characters
    //lower case the cleaned text and reverse the characters
    string cleanedText = cleanTheText(text);
    string lowerCasedText = lowerCaseTheText(cleanedText);
    string reversedText = reverseTheCharacters(lowerCasedText);
    //step 3: display the new text
    cout << "You entered: " << text << endl;
    cout << "Clenead text: " << cleanedText << endl;
    cout << "Lower cased text: " << lowerCasedText << endl;
    cout << "Reversed text: " << reversedText << endl;
    //step 4: check if lowerCasedText and reversedText is palindrome
    if(isPalindrome(lowerCasedText,reversedText)){
        palindromeResult = "Palindrome";
    }else{
        palindromeResult = "Not Palindrome";
    }
    //step 5: displayReult;
    cout << "Result: " << palindromeResult << endl;
    //step 6: store the details in the object
    PalindromeResultObject PalindromeDetail;
    PalindromeDetail.text = text;
    PalindromeDetail.cleanedText = cleanedText;
    PalindromeDetail.lowerCasedText = lowerCasedText;
    PalindromeDetail.reversedText = reversedText;
    PalindromeDetail.palindromeResult = palindromeResult;
    //step 7: save the results
    writeUserInputResultToFile(PalindromeDetail,title);
}

void readFromAndWriteToFile(string fileName,string title){
    //step 1: prepare fstream object
    ifstream readFromFile;
    fstream writeToFile;
    readFromFile.open(fileName);
    writeToFile.open("results.txt",ios::app);
    //step 2: end the run if either of the two stream objects does not work
    if(!readFromFile.is_open()){
        cout << "Sorry the file cannot be found. Try Again!" << endl;
        return;
    }
    if(!writeToFile.is_open()){
        cout << "Sorry the file for writing results is not accessible. Further troubleshooting is needed" << endl;
        return;
    }
    //step 3: loop through the file content
    string text;
    string palindromeResult = "";
    string divider = "===================================";
    string miniDivider = "-------------------------------";
    writeToFile << "===================================" << endl;
    writeToFile << title << endl;
    PalindromeResultObject PalindromeDetail;
    while(getline(readFromFile,text)){
        //step 4: process each text
        string cleanedText = cleanTheText(text);
        string lowerCasedText = lowerCaseTheText(cleanedText);
        string reversedText = reverseTheCharacters(lowerCasedText);
        //step 5: display the details of text
        cout << "You entered: " << text << endl;
        cout << "Clenead text: " << cleanedText << endl;
        cout << "Lower cased text: " << lowerCasedText << endl;
        cout << "Reversed text: " << reversedText << endl;
        //step 6: check if lowerCasedText and reversedText is palindrome
        if(isPalindrome(lowerCasedText,reversedText)){
            palindromeResult = "Palindrome";
        }else{
            palindromeResult = "Not Palindrome";
        }
        //step 7:display the result
        cout << "Result: " << palindromeResult << endl;
        cout << miniDivider << endl;
        //step 8: put details in the object
        PalindromeDetail.text = text;
        PalindromeDetail.cleanedText = cleanedText;
        PalindromeDetail.lowerCasedText = lowerCasedText;
        PalindromeDetail.reversedText = reversedText;
        PalindromeDetail.palindromeResult = palindromeResult;
        //step 9: save the results
        writeToFile << "You entered: "<< PalindromeDetail.text << endl;
        writeToFile << "Clenead text: " << PalindromeDetail.cleanedText << endl;
        writeToFile << "Lower cased text: "<<PalindromeDetail.lowerCasedText << endl;
        writeToFile << "Reversed text: "<<PalindromeDetail.reversedText << endl;
        writeToFile << PalindromeDetail.palindromeResult << endl;
        writeToFile << miniDivider << endl;
    }
    //step 10: close the fstream objects
    cout << "Saving is successful. See results.txt for reference" << endl;
    readFromFile.close();
    writeToFile.close();
}
void runPalindromeFromFile(){
    //step 1: show title
    string title = "Palindrome From File";
    cout << title << endl;
    //step 2: ask user for the file name
    cout << "Enter the file name. Example: words.txt" << endl;
    string fileName;
    getline(cin,fileName);
    //step 3:
    readFromAndWriteToFile(fileName,title);
}
void acceptUserOption(){
    //step 1: prepare char option
    char option;
    //step 2:
    do{
        //step 3: obtain selection
        cin >> option;
        //step 4: process only the first character, ignore the rest
        processTheFirstCharacter();
        //step 5: validate user selection
        while(isalpha(option)){
            cout << "That is not a number. Try again" << endl;
            cin >> option;
            processTheFirstCharacter();
        }
        //step 6: switch through available routines
        switch(option){
        case '0':
            clearScreen();
            showDivider();
            cout << "Thank you for using this application!" << endl;
            cout << "See you again next time!" <<endl;
            showDivider();
            break;
        case '1':
            clearScreen();
            showDivider();
            runPalindromeFromUserInput();
            showDivider();
            showOptions();
            showDivider();
            break;
        case '2':
            clearScreen();
            showDivider();
            runPalindromeFromFile();
            showDivider();
            showOptions();
            showDivider();
            break;
        default:
            cout << "That is not in the options. Try again!" << endl;
            break;
        }
    }while(option!='0');
}
void runApplication(){
    showDivider();
    showExamDetail();
    showDivider();
    showOptions();
    showDivider();
    acceptUserOption();
}
int main(){
    runApplication();
return 0;
}
