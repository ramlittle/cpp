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
    //step 1: get employee count
    int employeeCount=0;
    cout << "How many Employees would you like to record" << endl;
    cin >> employeeCount;
    //step 2: declare array obj
    MyObject Employees[employeeCount];
    //step 3: let user enter the details of employees in the array
    cout << "Enter the details of employees" << endl;
    for(int i =0;i<employeeCount;i++){
        cout << "Entering details for employee " << i+1 << " : " << endl;
        cout << "Name: " << endl;
        cin >> Employees[i].name;
        cout << "Age: " << endl;
        cin >> Employees[i].age;
    }
    //step 4: display the list that was entered in table form
    cout << "Item #" << "\t" << "Name" << "\t" << "Age" << endl;
    for(int i=0;i<employeeCount;i++){
        cout << i+1 << "\t" << Employees[i].name << "\t" << Employees[i].age << endl;
    }
}

bool isValidDecimal(string givenDecimal){
    //step 1: loop through the givenDecimal
    for(int i=0;i<givenDecimal.length();i++){
        if(isalpha(givenDecimal[i])){
            return false;
        }
    }
    //step 2: convert the givenDecimal to integer
    int givenInteger = stoi(givenDecimal);
    //step 3: return false if value is less than 0
    if(givenInteger < 0){
        return false;
    }
    //step 4: return true if all goods
    return true;
}

string convertDecimalToBinary(string givenDecimal){
    //step 1: convert givenDecimal to int
    int givenInteger = stoi(givenDecimal);
    //step 2: let's determine the bitValue by
    //increasing its value 2x every iteration as
    //long as the bitValue is less than the givenInteger
    int bitValue = 1;
    while(bitValue<=givenInteger){
        bitValue*=2;
    }
    //step 3: go down one bitValue so that givenInteger is still one bitValue higher
    bitValue/=2;
    //step 3: prepare binaryResult Variable
    string binaryResult = "";
    //step 4: iterate through bitValue until bitValue is 0
    while(bitValue!=0){
        //step 5: concatenate 1 to binaryResult if givenInteger is greater
        //than or equal to bitValue
        if(givenInteger >= bitValue){
            binaryResult+= '1';
            givenInteger-=bitValue;
        }else{
            //step 6: concatenate 0 if otherwise
            binaryResult+= '0';
        }
        //step 7: divide bitValue by two every iteration
        bitValue/=2;
    }
    //step 8: return binaryResult;
    return binaryResult;
}
void runBinaryConversionLowToHigh(){
    string title = "Binary Conversion Low To High";
    cout << "Title: " << title << endl;
    //step 1: get user input
    string decimal;
    cout << "Enter your decimal " << endl;
    cin >> decimal;
    //step 2: validate input
    while(!isValidDecimal(decimal)){
        cout << "That is not valid decimal or integer. Try again!" << endl;
        cin >> decimal;
    }
    //step 3: do bin conversion
    string binaryResult = convertDecimalToBinary(decimal);
    //step 4: display binaryResult;
    cout << "Binary Result " << binaryResult << endl;
}

void runBinaryConversionHighToLow(){
    string title = "Binary Conversion High To Low";
    cout << "Title: " << title << endl;
}
void showOptions(){
    cout << "What would you like to do?"<< endl;
    cout << "1: Practice Array Objects" << endl;
    cout << "2: Enter a decimal, system will convert to binary, convert to octal, sort the result lowest to highest, then display the decimal result" << endl;
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
        case '2':
            clearScreen();
            showDivider();
            runBinaryConversionLowToHigh();
            showDivider();
            showOptions();
            break;
        case '3':
            clearScreen();
            showDivider();
            runBinaryConversionHighToLow();
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
