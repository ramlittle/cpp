#include <iostream>
using namespace std;

bool isValidDecimal(string givenDecimal){
    for(int i=0;i<givenDecimal.length();i++){
        if(isalpha(givenDecimal[i])){
            return false;
        }
    }
    return true;
}

bool isValidBinary(string givenBinary){
    for(int i=0;i<givenBinary.length();i++){
        if(isalpha(givenBinary[i])){
            return false;
        }else{
            int bit = givenBinary[i]-'0';
            if(bit>1){
                return false;
            }
        }
    }
    return true;
}

string convertDecimalToBinary(int givenDecimal){
    int bitValue = 1;
    string binaryResult = "";
    while(bitValue<=givenDecimal){
        bitValue*=2;
    }
    bitValue/=2;
    /*
        givenDecimal = 12
        bitValue = 8

    */

    while(bitValue!=0){
        if(givenDecimal>=bitValue){

            binaryResult+='1';
            givenDecimal-=bitValue;
        }else{
            binaryResult+='0';
        }
        bitValue/=2;
    }
    return binaryResult;
}

int convertBinaryToDecimal(string givenBinary){
    int decimalResult = 0;
    int bitValue =1;
    /*
        1100
    */
    for(int i=givenBinary.length()-1;i>=0;i--){
        char bit = givenBinary[i];
        if(bit == '1'){
            decimalResult+=bitValue;
        }
        bitValue*=2;
    }
    return decimalResult;
}

void runDecimalToBinaryConversion(){
    cout << "DECIMAL TO BINARY CONVERSION" << endl;
    string decimal;
    cout << "Enter the number to convert " << endl;
    cin >> decimal;
    while(!isValidDecimal(decimal)){
        cout << "That is not a valid decimal " << endl;
        cin >> decimal;
    }
    string binaryResult = convertDecimalToBinary(stoi(decimal));
    cout << "Binary Result : "<< binaryResult<<endl;
}

void runBinaryToDecimalConversion(){
    cout << "BINARY TO DECIMAL CONVERSION " << endl;
    string binary;
    cout << "Enter the binary" << endl;
    cin >> binary;
    while(!isValidBinary(binary)){
        cout << "That is not a valid binary" << endl;
        cin >> binary;
    }
    int decimalResult = convertBinaryToDecimal(binary);
    cout << "Decimal Result: " << decimalResult<< endl;
}

void showOptions(){
    cout << "What do you want to do " << endl;
    cout << "1: Convert Decimal to Binary " << endl;
    cout << "2: Convert Binary to Decimal " <<endl;
    cout << "0: Exit" <<endl;
}

void showDivider(){
    cout << "====================================" << endl;
}
void clearScreen(){
    system("cls");
}
void acceptUserOption(){
    char option;
    do{
        cin >> option;
        switch(option){
            case '0':
                cout << "Thank you for using this app" <<endl;
                break;
            case '1':
                clearScreen();
                runDecimalToBinaryConversion();
                showDivider();
                showOptions();
                break;
            case '2':
                clearScreen();
                runBinaryToDecimalConversion();
                showDivider();
                showOptions();
                break;
            default :
                cout << "That is not in the options. Try again" << endl;
                break;
        }
    }while(option!='0');
}

void runApplication(){
    showOptions();
    acceptUserOption();
}
int main(){
    runApplication();
    return 0;
}
