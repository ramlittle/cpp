#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

string convertToLowerCase(string givenWord){
    string lowerCasedWord="";
    char temporaryChar;
    for(int i=0;i<givenWord.length();i++){
        temporaryChar = tolower(givenWord[i]);
        lowerCasedWord+=temporaryChar;
    }
    return lowerCasedWord;
}
bool isPalindrome(string givenWord){
    string lowerCasedWord=convertToLowerCase(givenWord);
    string reversedWord=lowerCasedWord;
    int givenWordIndex=0;

    for(int i=lowerCasedWord.length()-1;i>=0;i--){
        reversedWord[i] = lowerCasedWord[givenWordIndex];
        givenWordIndex++;
    }

    if(reversedWord == lowerCasedWord){
        return true;
    }

    return false;
}
void readFileAndDisplayResult(){
    ifstream readWords;
    readWords.open("words.txt");
    if(!readWords.is_open()){
        cout << "unable to open the file";
        return;
    }

    string word;
    while(readWords >> word){
        isPalindrome(word) ?
            cout << word << " is palindrome" << endl :
            cout << word << " is not palindrome" << endl;
    }
    readWords.close();
}

int main(){
    readFileAndDisplayResult();
return 0;
}
